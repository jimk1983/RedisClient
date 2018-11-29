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


#define REDIS_COMM_LEN              16
#define REDIS_TERMAL_STRLEN         64

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






/***************************************************************************/
/************************        代理服务          *****************************/
/***************************************************************************/
/* 代理服务器信息 */
typedef struct tagRedisTerminalInfo
{
    unsigned char acProxyServerInfoID[REDIS_COMM_LEN];          /*代理服务器信息ID*/
    unsigned char acProxyServerConnNums[REDIS_COMM_LEN];        /*终端相关连接数信息*/
    unsigned char acProxyServerAddr[REDIS_COMM_LEN];            /*代理服务器内网地址*/
    unsigned char acProxyServerCtrlPort[REDIS_COMM_LEN];        /*代理服务器内网控制端口*/
}REDIS_TERMAL_INFO_S, *PREDIS_TERMAL_INFO_S;































