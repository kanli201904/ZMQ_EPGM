#ifndef __H_DA_MARKETDATA_H__
#define __H_DA_MARKETDATA_H__

#include <cstdint>

#pragma pack(push,1)

// ֱ���г�������Ϣͷ
struct DAMarketdataHead
{	
	uint64_t timestamp;
	// ��������
	uint8_t type;
	// �г���ʶ
	uint8_t market;
	// ��ı�ʶ
	uint16_t instrument;
	// �������
	uint32_t sequence;
	// �ۼƴ�͸�ӳ٣����룩
	uint32_t latency;
	// ����Դ��ʶ
	uint8_t source;
	// ����λͼ
	uint8_t bitmap;
	// ������Ϣ�峤��
	uint16_t length;
	
};
//�۹���չ�ֶ�
struct DAExpandInformation_HK
{
	//���鳤��
	uint8_t length;
	//�ɽ���
	uint64_t volume;
	 //����Ļ�ûʵ��
	//��Ʊͣ��flag
	bool if_suspended;
	//�۹ɰ��̼�
	double nominal_price;
};
//������չ�ֶ�
struct DAExpandInformation_US
{
	//���鳤��
	uint8_t length;
	//�ɽ���
	uint64_t volume;
	//����Ļ�ûʵ��
   //��Ʊͣ��flag
	bool if_suspended;
	//���ɽ���ʱ���flag
	bool if_US_trading;
	//��ǰ���¼�
	double latest_pre_price;
	//�̺����¼�
	double latest_after_price;
};
//�̿�����
struct DAOrderBookOne
{
	//��1��
	double buy_first_price;
	//��1��
	double sell_first_price;
	//��1��
	uint32_t buy_first_volume;
	//��1��
	uint32_t sell_first_volume;
	//�ּ�
	double current_price;
	//����
	uint64_t current_volume;
	//���ճɽ���
	uint64_t daily_volume;
};
//�嵵�̿�����
struct DAOrderBookFive
{
	//��1��
	double buy_first_price;
	//��1��
	double sell_first_price;
	//��1��
	uint32_t buy_first_volume;
	//��1��
	uint32_t sell_first_volume;
	//�ּ�
	double current_price;
	//����
	uint64_t current_volume;
	//���ճɽ���
	uint64_t daily_volume;
	//��2��
	double buy_second_price;
	//��2��
	double sell_second_price;
	//��2��
	uint32_t buy_second_volume;
	//��2��
	uint32_t sell_second_volume;
	//��3��
	double buy_three_price;
	//��3��
	double sell_three_price;
	//��3��
	uint32_t buy_three_volume;
	//��3��
	uint32_t sell_three_volume;
	//��4��
	double buy_four_price;
	//��4��
	double sell_four_price;
	//��4��
	uint32_t buy_four_volume;
	//��4��
	uint32_t sell_four_volume;
	//��5��
	double buy_five_price;
	//��5��
	double sell_five_price;
	//��5��
	uint32_t buy_five_volume;
	//��5��
	uint32_t sell_five_volume;
};
//ʮ���̿�����
struct DAOrderBookTen
{

	//��1��
	double buy_first_price;
	//��1��
	double sell_first_price;
	//��1��
	uint32_t buy_first_volume;
	//��1��
	uint32_t sell_first_volume;
	//�ּ�
	double current_price;
	//����
	uint64_t current_volume;
	//���ճɽ���
	uint64_t daily_volume;
	//��2��
	double buy_second_price;
	//��2��
	double sell_second_price;
	//��2��
	uint32_t buy_second_volume;
	//��2��
	uint32_t sell_second_volume;
	//��3��
	double buy_three_price;
	//��3��
	double sell_three_price;
	//��3��
	uint32_t buy_three_volume;
	//��3��
	uint32_t sell_three_volume;
	//��4��
	double buy_four_price;
	//��4��
	double sell_four_price;
	//��4��
	uint32_t buy_four_volume;
	//��4��
	uint32_t sell_four_volume;
	//��5��
	double buy_five_price;
	//��5��
	double sell_five_price;
	//��5��
	uint32_t buy_five_volume;
	//��5��
	uint32_t sell_five_volume;
	//��6��
	double buy_six_price;
	//��6��
	double sell_six_price;
	//��6��
	uint32_t buy_six_volume;
	//��6��
	uint32_t sell_six_volume;
	//��7��
	double buy_seven_price;
	//��7��
	double sell_seven_price;
	//��7��
	uint32_t buy_seven_volume;
	//��7��
	uint32_t sell_seven_volume;
	//��8��
	double buy_eight_price;
	//��8��
	double sell_eight_price;
	//��8��
	uint32_t buy_eight_volume;
	//��8��
	uint32_t sell_eight_volume;
	//��9��
	double buy_nine_price;
	//��9��
	double sell_nine_price;
	//��9��
	uint32_t buy_nine_volume;
	//��9��
	uint32_t sell_nine_volume;
	//��10��
	double buy_ten_price;
	//��10��
	double sell_ten_price;
	//��10��
	uint32_t buy_ten_volume;
	//��10��
	uint32_t sell_ten_volume;
};
//�������̿�
struct DAImplicitPriceOrderBook
{
	//������1��
	double buy_first_price;
	//������1��
	uint32_t buy_first_volume;
	//������1��
	double sell_first_price;
	//������1��
	uint32_t sell_first_volume;
};
//ͳ������
struct DAStatisticData
{
	//��߼�
	double max_price;
	//��ͼ�
	double min_price;
	//���̼�
	double open;
	//���̼�
	double close;
	//ǰ�����
	double pre_price;
	//���н����
	double in_price;
	//��ͣ��
	double harden_price;
	//��ͣ��
	double down_price;
	//�ֲ���
	uint64_t open_interest;
};
//�ɽ�����
struct DADealData
{
	//�ɽ���
	double deal_price;
	//�ɽ���
	uint32_t deal_volume;
	//�ճɽ���
	uint32_t daily_deal_volume;
	//��������flag
	bool buy_sell_flag;
	//�۹ɳɽ����ݵ�flag
	bool HK_deal_data;
};
//����
struct DAHeartBeat
{
	//ʱ��
	uint32_t time;
	//ip�Ͷ˿�
	uint64_t ip_port;
};
//����ͳ������
struct DAClearData
{
	//״̬
	uint8_t state;
};
//�۹ɾ����̶�������
struct DAHKQueueData
{
	//��Ϣ��С
	uint16_t MsgSize;
	//��Ϣ����
	uint16_t MsgType;
	//��ȫ��
	uint32_t SecurityCode;
	//Item����
	uint8_t ItemCount;
	//������
	uint16_t Side;
	//�������Ƿ��и��ྭ����
	char BQMoreFlag;
	//����
	uint16_t Item;
	//����
	char Type;
	//����
	char Filler;
};
#pragma pack(pop)

#endif//__H_DA_MARKETDATA_H__
