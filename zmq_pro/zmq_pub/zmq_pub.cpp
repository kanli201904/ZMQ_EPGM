#include <future>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "zmq.hpp"
#include "zmq_addon.hpp"
#include <windows.h>
#include <time.h>
#include "da_marketdata.h"
std::string  sAddress;

// 初始化log

uint64_t xdk_nanosecond_timestamp() { //用来获取纳秒级别的时间戳
	static uint64_t baseline = 0;
	static uint64_t multiplier = 0;
	static LARGE_INTEGER frequency;
	static LARGE_INTEGER base_counter;

	uint64_t timestamp = 0;
	if (baseline == 0) {
		::QueryPerformanceFrequency(&frequency);
		multiplier = 1000000000ULL / frequency.QuadPart;
		FILETIME file_time;
		::GetSystemTimeAsFileTime(&file_time);
		baseline |= file_time.dwHighDateTime;
		baseline <<= 32;
		baseline |= file_time.dwLowDateTime;
		baseline *= 100;
		baseline -= 11644473600000000000ULL;
		::QueryPerformanceCounter(&base_counter);
		timestamp = baseline;
	}
	else {
		LARGE_INTEGER counter;
		::QueryPerformanceCounter(&counter);
		timestamp = baseline + (counter.QuadPart - base_counter.QuadPart) * multiplier;
	}
	return timestamp;
}

inline void xdk_microsecond_delay(uint64_t interval) { //用来进行微秒级别的sleep
	interval *= 1000ULL;
	uint64_t t, t0 = xdk_nanosecond_timestamp();
	do
	{
		t = xdk_nanosecond_timestamp();
	} while (t - t0 < interval);
}
void EPGMPublisherThread() {
	void* ctx = zmq_ctx_new();                       //创建一个新的上下文
	void* publisher = zmq_socket(ctx, ZMQ_PUB); //创建一个新的zmq的socket 类型为pub
	int rate = 800000;
	zmq_setsockopt(publisher, ZMQ_RATE, &rate, sizeof(rate)); //设置socket的发送速率，单位为kilobits per second
	int sndbuf = 20000000;
	zmq_setsockopt(publisher, ZMQ_SNDBUF, &sndbuf, sizeof(sndbuf)); //设置socket的发送区buffer, 单位为bytes
	int sndhwm = 999999;
	zmq_setsockopt(publisher, ZMQ_SNDHWM, &sndhwm, sizeof(sndhwm)); //设置socket的发送区高水位，如果管道内堆积的数据超过水位，新发送的数据将直接被管道drop
	int recover = 60000;
	zmq_setsockopt(publisher, ZMQ_RECOVERY_IVL, &recover, sizeof(recover)); //设置socket的能从多播组缺席的最长时间 单位为ms,这段时间发送的数据会被保存在内存里
    
	int mulithops = 64;
	zmq_setsockopt(publisher, ZMQ_MULTICAST_HOPS, &mulithops, sizeof(mulithops));
																			//std::string  sAddress = "epgm://239.192.1.23:5580";
	zmq_bind(publisher, sAddress.c_str());                //pub端使用bind连接组播地址 
	std::cout << "The addr=" << sAddress << std::endl;

	char buffer[512] = { 0 };                                          //一个512字节的buffer 
	
	std::string rand_string = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWZYZ";
	for (int i = 0; i < 512; i++) {
		int rand = std::rand() % rand_string.length();
		buffer[i] = rand_string[rand];
	}
	buffer[511] = '\0';   //生成一个随机字符串buffer 测试用
	
	

	std::this_thread::sleep_for(std::chrono::milliseconds(200));         //bind后要等待一段时间才能发送消息
	long long index = 0;                                                  //计数器 可不用 
	//DAMarketdataHead* head = reinterpret_cast<DAMarketdataHead*>(buffer);  //强制转化类型， 用字符串存储结构体
	DAMarketdataHead* head = new DAMarketdataHead;
	memset(head, 0, sizeof(DAMarketdataHead));

	std::cout << "Start run pub" << sAddress << std::endl;
	while (1==1) {        
			head->timestamp = xdk_nanosecond_timestamp();                      
			head->sequence = index;
			memcpy(buffer, head, 511);
			zmq_send(publisher, buffer, 511, 0);                          //ZMQ的send函数后面四个参数依次为，socket，buffer，buffer大小，最后一个设置为0即可
			index++;
			uint64_t dt = xdk_nanosecond_timestamp() - head->timestamp;

			std::this_thread::sleep_for(std::chrono::milliseconds(1250));
			
			uint64_t interval = 500;
			if (dt < interval * 1000ULL) {
				xdk_microsecond_delay(interval - dt * 0.001);                //设置delay防止while循环过快超过rate导致堆积数据超过水位，drop数据
			}
		

	//	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	zmq_close(publisher);
	zmq_ctx_destroy(ctx);

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}

int main(int argc, char *argv[])
{
	/*
	 * No I/O threads are involved in passing messages using the inproc transport.
	 * Therefore, if you are using a ØMQ context for in-process messaging only you
	 * can initialise the context with zero I/O threads.
	 *
	 * Source: http://api.zeromq.org/4-3:zmq-inproc
	 */

	if (argc < 2)
		std::cout <<"参数不够格式为exe epagm://ip:port "<< std::endl;

	std::string sTemp = argv[1];

	//sAddress = "epgm://" + sTemp ;
	sAddress = sTemp;
	
	auto thread1 = std::async(std::launch::async, EPGMPublisherThread);  //异步发送
	thread1.wait();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	


	
}
