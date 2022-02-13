#ifndef __H_DA_MARKETDATA_H__
#define __H_DA_MARKETDATA_H__

#include <cstdint>

#pragma pack(push,1)

// 直达市场数据消息头
struct DAMarketdataHead
{	
	uint64_t timestamp;
	// 行情类型
	uint8_t type;
	// 市场标识
	uint8_t market;
	// 标的标识
	uint16_t instrument;
	// 发送序号
	uint32_t sequence;
	// 累计穿透延迟（纳秒）
	uint32_t latency;
	// 数据源标识
	uint8_t source;
	// 保留位图
	uint8_t bitmap;
	// 行情消息体长度
	uint16_t length;
	
};
//港股扩展字段
struct DAExpandInformation_HK
{
	//行情长度
	uint8_t length;
	//成交额
	uint64_t volume;
	 //后面的还没实现
	//股票停牌flag
	bool if_suspended;
	//港股按盘价
	double nominal_price;
};
//美股扩展字段
struct DAExpandInformation_US
{
	//行情长度
	uint8_t length;
	//成交额
	uint64_t volume;
	//后面的还没实现
   //股票停牌flag
	bool if_suspended;
	//美股交易时间段flag
	bool if_US_trading;
	//盘前最新价
	double latest_pre_price;
	//盘后最新价
	double latest_after_price;
};
//盘口数据
struct DAOrderBookOne
{
	//买1价
	double buy_first_price;
	//卖1价
	double sell_first_price;
	//买1量
	uint32_t buy_first_volume;
	//卖1量
	uint32_t sell_first_volume;
	//现价
	double current_price;
	//现量
	uint64_t current_volume;
	//当日成交量
	uint64_t daily_volume;
};
//五档盘口数据
struct DAOrderBookFive
{
	//买1价
	double buy_first_price;
	//卖1价
	double sell_first_price;
	//买1量
	uint32_t buy_first_volume;
	//卖1量
	uint32_t sell_first_volume;
	//现价
	double current_price;
	//现量
	uint64_t current_volume;
	//当日成交量
	uint64_t daily_volume;
	//买2价
	double buy_second_price;
	//卖2价
	double sell_second_price;
	//买2量
	uint32_t buy_second_volume;
	//卖2量
	uint32_t sell_second_volume;
	//买3价
	double buy_three_price;
	//卖3价
	double sell_three_price;
	//买3量
	uint32_t buy_three_volume;
	//卖3量
	uint32_t sell_three_volume;
	//买4价
	double buy_four_price;
	//卖4价
	double sell_four_price;
	//买4量
	uint32_t buy_four_volume;
	//卖4量
	uint32_t sell_four_volume;
	//买5价
	double buy_five_price;
	//卖5价
	double sell_five_price;
	//买5量
	uint32_t buy_five_volume;
	//卖5量
	uint32_t sell_five_volume;
};
//十档盘口数据
struct DAOrderBookTen
{

	//买1价
	double buy_first_price;
	//卖1价
	double sell_first_price;
	//买1量
	uint32_t buy_first_volume;
	//卖1量
	uint32_t sell_first_volume;
	//现价
	double current_price;
	//现量
	uint64_t current_volume;
	//当日成交量
	uint64_t daily_volume;
	//买2价
	double buy_second_price;
	//卖2价
	double sell_second_price;
	//买2量
	uint32_t buy_second_volume;
	//卖2量
	uint32_t sell_second_volume;
	//买3价
	double buy_three_price;
	//卖3价
	double sell_three_price;
	//买3量
	uint32_t buy_three_volume;
	//卖3量
	uint32_t sell_three_volume;
	//买4价
	double buy_four_price;
	//卖4价
	double sell_four_price;
	//买4量
	uint32_t buy_four_volume;
	//卖4量
	uint32_t sell_four_volume;
	//买5价
	double buy_five_price;
	//卖5价
	double sell_five_price;
	//买5量
	uint32_t buy_five_volume;
	//卖5量
	uint32_t sell_five_volume;
	//买6价
	double buy_six_price;
	//卖6价
	double sell_six_price;
	//买6量
	uint32_t buy_six_volume;
	//卖6量
	uint32_t sell_six_volume;
	//买7价
	double buy_seven_price;
	//卖7价
	double sell_seven_price;
	//买7量
	uint32_t buy_seven_volume;
	//卖7量
	uint32_t sell_seven_volume;
	//买8价
	double buy_eight_price;
	//卖8价
	double sell_eight_price;
	//买8量
	uint32_t buy_eight_volume;
	//卖8量
	uint32_t sell_eight_volume;
	//买9价
	double buy_nine_price;
	//卖9价
	double sell_nine_price;
	//买9量
	uint32_t buy_nine_volume;
	//卖9量
	uint32_t sell_nine_volume;
	//买10价
	double buy_ten_price;
	//卖10价
	double sell_ten_price;
	//买10量
	uint32_t buy_ten_volume;
	//卖10量
	uint32_t sell_ten_volume;
};
//隐含价盘口
struct DAImplicitPriceOrderBook
{
	//隐含买1价
	double buy_first_price;
	//隐含买1量
	uint32_t buy_first_volume;
	//隐含卖1价
	double sell_first_price;
	//隐含卖1量
	uint32_t sell_first_volume;
};
//统计数据
struct DAStatisticData
{
	//最高价
	double max_price;
	//最低价
	double min_price;
	//开盘价
	double open;
	//收盘价
	double close;
	//前结算价
	double pre_price;
	//盘中结算价
	double in_price;
	//涨停价
	double harden_price;
	//跌停价
	double down_price;
	//持仓量
	uint64_t open_interest;
};
//成交数据
struct DADealData
{
	//成交价
	double deal_price;
	//成交量
	uint32_t deal_volume;
	//日成交量
	uint32_t daily_deal_volume;
	//主动买卖flag
	bool buy_sell_flag;
	//港股成交数据的flag
	bool HK_deal_data;
};
//心跳
struct DAHeartBeat
{
	//时间
	uint32_t time;
	//ip和端口
	uint64_t ip_port;
};
//清理统计数据
struct DAClearData
{
	//状态
	uint8_t state;
};
//港股经纪商队列数据
struct DAHKQueueData
{
	//消息大小
	uint16_t MsgSize;
	//消息类型
	uint16_t MsgType;
	//安全码
	uint32_t SecurityCode;
	//Item数量
	uint8_t ItemCount;
	//买还是卖
	uint16_t Side;
	//队列中是否有更多经纪人
	char BQMoreFlag;
	//条款
	uint16_t Item;
	//类型
	char Type;
	//补白
	char Filler;
};
#pragma pack(pop)

#endif//__H_DA_MARKETDATA_H__
