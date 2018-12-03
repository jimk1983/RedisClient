/******************************************************************************

                  版权所有 (C), 2018-2028, 技术有限公司

 ******************************************************************************
  文 件 名   : RedisLibApi.h
  版 本 号   : 初稿
  作    者   : jimk
  生成日期   : 2018年11月27日
  最近修改   :
  功能描述   : 接口测试
  函数列表   :
  修改历史   :
  1.日    期   : 2018年11月27日
    作    者   : jimk
    修改内容   : 创建文件

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


#define REDIS_COMM_LEN              16      /*通用的字符串长度*/

#define REDIS_TERMAL_STRLEN         64      /*终端的部分字符串长度*/

/* Redis的连接 */
typedef struct tagRedisConnection
{
    char          acServerAddr[REDIS_COMM_LEN];     /*Redis服务器地址*/
    int           iSevPort;                         /*Redis服务器端口*/
    void*         pstRedisConn;                      /*Redis上下文*/
    void*         pstUserCtx;                       /*用户上下文*/            
}REDIS_CONN_S, *PREDIS_CONN_S;

REDIS_CONN_S *REDIS_API_ConnCreate(char *pcSevAddr, int iSevPort, void *pvUserCtx);

void REDIS_API_ConnRelease(REDIS_CONN_S **ppstConn);

/***************************************************************************/
/************************        终端信息          *****************************/
/***************************************************************************/
/* 终端信息 */
typedef struct tagRedisTerminalInfo
{
    unsigned char acTerminalID[REDIS_TERMAL_STRLEN];            /*终端ID*/
    unsigned char acTerminalDesptor[REDIS_TERMAL_STRLEN];       /*终端描述*/
    unsigned char acTerminalStatus[REDIS_COMM_LEN];             /*终端状态*/
    unsigned char acTerminalPubAddr[REDIS_TERMAL_STRLEN];       /*公网地址*/
    unsigned char acTerminalNATType[REDIS_COMM_LEN];            /*NAT类型*/
    unsigned char acProxyServerInfoID[REDIS_COMM_LEN];          /*代理服务器信息ID*/
}REDIS_TERMAL_INFO_S, *PREDIS_TERMAL_INFO_S;

long REDIS_API_TerminalInfoSet(IN REDIS_CONN_S *pstConn, IN REDIS_TERMAL_INFO_S *pstInfo);

long REDIS_API_TerminalInfoGet(IN REDIS_CONN_S *pstConn, OUT REDIS_TERMAL_INFO_S *pstInfo);

long REDIS_API_TerminalInfoGetSet(IN REDIS_CONN_S *pstConn, INOUT REDIS_TERMAL_INFO_S *pstInfoGetSet);


/***************************************************************************/
/************************        代理服务          *****************************/
/***************************************************************************/
/* 代理服务器信息 */
typedef struct tagRedisProxyGatewayInfo
{
    unsigned char acProxyServerInfoID[REDIS_COMM_LEN];          /*代理服务器信息ID*/
    unsigned char acProxyServerConnNums[REDIS_COMM_LEN];        /*终端相关连接数信息*/
    unsigned char acProxyServerAddr[REDIS_COMM_LEN];            /*代理服务器内网地址*/
    unsigned char acProxyServerCtrlPort[REDIS_COMM_LEN];        /*代理服务器内网控制端口*/
}REDIS_PROXYGW_INFO_S, *PREDIS_PROXYGW_INFO_S;
    
long REDIS_API_ProxyGatewayInfoSet(IN REDIS_CONN_S *pstConn, IN REDIS_PROXYGW_INFO_S *pstInfo);

long REDIS_API_ProxyGatewayInfoGet(IN REDIS_CONN_S *pstConn, OUT REDIS_PROXYGW_INFO_S *pstInfo);

long REDIS_API_ProxyGatewayInfoGetSet(IN REDIS_CONN_S *pstConn, INOUT REDIS_PROXYGW_INFO_S *pstInfoGetSet);



#ifdef __cplusplus
}
#endif


