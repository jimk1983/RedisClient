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
    
#ifdef __cplusplus
extern "C" {
#endif

#ifndef VOS_ERR
#define VOS_ERR                     -1
#endif

#ifndef VOS_OK
#define VOS_OK                      0
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif


#define REDIS_COMM_LEN              16      /*ͨ�õ��ַ�������*/

#define REDIS_TERMAL_STRLEN         64      /*�ն˵Ĳ����ַ�������*/

/* Redis������ */
typedef struct tagRedisConnection
{
    char          acServerAddr[REDIS_COMM_LEN];     /*Redis��������ַ*/
    int           iSevPort;                         /*Redis�������˿�*/
    void*         pstRedisConn;                      /*Redis������*/
    void*         pstUserCtx;                       /*�û�������*/            
}REDIS_CONN_S, *PREDIS_CONN_S;

REDIS_CONN_S *REDIS_API_ConnCreate(char *pcSevAddr, int iSevPort, void *pvUserCtx);

void REDIS_API_ConnRelease(REDIS_CONN_S **ppstConn);

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

long REDIS_API_TerminalInfoSet(IN REDIS_CONN_S *pstConn, IN REDIS_TERMAL_INFO_S *pstInfo);

long REDIS_API_TerminalInfoGet(IN REDIS_CONN_S *pstConn, OUT REDIS_TERMAL_INFO_S *pstInfo);

long REDIS_API_TerminalInfoGetSet(IN REDIS_CONN_S *pstConn, INOUT REDIS_TERMAL_INFO_S *pstInfoGetSet);


/***************************************************************************/
/************************        �������          *****************************/
/***************************************************************************/
/* �����������Ϣ */
typedef struct tagRedisProxyGatewayInfo
{
    unsigned char acProxyServerInfoID[REDIS_COMM_LEN];          /*�����������ϢID*/
    unsigned char acProxyServerConnNums[REDIS_COMM_LEN];        /*�ն������������Ϣ*/
    unsigned char acProxyServerAddr[REDIS_COMM_LEN];            /*���������������ַ*/
    unsigned char acProxyServerCtrlPort[REDIS_COMM_LEN];        /*����������������ƶ˿�*/
}REDIS_PROXYGW_INFO_S, *PREDIS_PROXYGW_INFO_S;
    
long REDIS_API_ProxyGatewayInfoSet(IN REDIS_CONN_S *pstConn, IN REDIS_PROXYGW_INFO_S *pstInfo);

long REDIS_API_ProxyGatewayInfoGet(IN REDIS_CONN_S *pstConn, OUT REDIS_PROXYGW_INFO_S *pstInfo);

long REDIS_API_ProxyGatewayInfoGetSet(IN REDIS_CONN_S *pstConn, INOUT REDIS_PROXYGW_INFO_S *pstInfoGetSet);



#ifdef __cplusplus
}
#endif


