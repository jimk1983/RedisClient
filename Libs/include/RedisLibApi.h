/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �������޹�˾

 ******************************************************************************
  �� �� ��   : RedisLibApi.h
  �� �� ��   : ����
  ��    ��   : jimk
  ��������   : 2018��11��27��
  ����޸�   :
  ��������   : �ӿڲ���
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��11��27��
    ��    ��   : jimk
    �޸�����   : �����ļ�

******************************************************************************/


#define REDIS_COMM_LEN              16
#define REDIS_TERMAL_STRLEN         64

/***************************************************************************/
/************************        �ն���Ϣ          *****************************/
/***************************************************************************/
/* �ն���Ϣ */
typedef struct tagRedisTerminalInfo
{
    unsigned char acTerminalID[REDIS_TERMAL_STRLEN];            /*�ն�ID*/
    unsigned char acTerminalDesptor[REDIS_TERMAL_STRLEN];       /*�ն�����*/
    unsigned char acTerminalStatus[REDIS_COMM_LEN];             /*�ն�״̬*/
    unsigned char acTerminalPubAddr[REDIS_TERMAL_STRLEN];       /*������ַ*/
    unsigned char acTerminalNATType[REDIS_COMM_LEN];            /*NAT����*/
    unsigned char acProxyServerInfoID[REDIS_COMM_LEN];          /*�����������ϢID*/
}REDIS_TERMAL_INFO_S, *PREDIS_TERMAL_INFO_S;






/***************************************************************************/
/************************        �������          *****************************/
/***************************************************************************/
/* �����������Ϣ */
typedef struct tagRedisTerminalInfo
{
    unsigned char acProxyServerInfoID[REDIS_COMM_LEN];          /*�����������ϢID*/
    unsigned char acProxyServerConnNums[REDIS_COMM_LEN];        /*�ն������������Ϣ*/
    unsigned char acProxyServerAddr[REDIS_COMM_LEN];            /*���������������ַ*/
    unsigned char acProxyServerCtrlPort[REDIS_COMM_LEN];        /*����������������ƶ˿�*/
}REDIS_TERMAL_INFO_S, *PREDIS_TERMAL_INFO_S;































