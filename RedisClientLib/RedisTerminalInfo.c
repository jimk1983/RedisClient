/******************************************************************************

                  版权所有 (C), 2018-2028, 技术有限公司

 ******************************************************************************
  文 件 名   : RedisTerminalApi.cpp
  版 本 号   : 初稿
  作    者   : jimk
  生成日期   : 2018年11月29日
  最近修改   :
  功能描述   : 终端信息采用Redis-Hash来实现
  函数列表   :
  修改历史   :
  1.日    期   : 2018年11月29日
    作    者   : jimk
    修改内容   : 创建文件
说明:
    1. 终端信息采用Redis的Hash来单独的存放每个终端的具体信息
    2. 终端信息采用Redis的集合来存放所有终端的在线信息/离线信息
    
******************************************************************************/
#include <RedisComm.h>


/************************ Redis终端信息hash表 *************************/
long REDIS_Terminal_InfoAdd(redisContext   *    pstRedisConnCtx,
                                 unsigned char *pcTerminalID,
                                 unsigned char *pcTerminalDescptor)
{
    redisReply*     reply = NULL;

    if ( NULL == pstRedisConnCtx )
    {
        return VOS_ERR;
    }

    reply = redisCommand(pstRedisConnCtx, REDIS_TERMINFO_CMD_HSET, 
                            pcTerminalID,
                            pcTerminalDescptor, 
                            REDIS_TMINFO_DEFVALUE, 
                            REDIS_TMINFO_STAUS_ONLINE, 
                            REDIS_TMINFO_DEFVALUE, 
                            REDIS_TMINFO_DEFVALUE);
    if ( NULL == reply )
    {
        printf("REDIS_Terminal_InfoAdd error=%s\n", pstRedisConnCtx->errstr);
        return VOS_ERR;
    }
    else
    {
        printf("REDIS_Terminal_InfoAdd successful!, pcTerminalID=%s\n", pcTerminalID );
    }
    
    freeReplyObject(reply);
    

    return VOS_OK;
}


void REDIS_Terminal_InfoDel(redisContext* pstRedisConnCtx,
                                 unsigned char *pcTerminalID)
{
    redisReply*     reply = NULL;

    if ( NULL == pstRedisConnCtx )
    {
        return;
    }

    reply = redisCommand(pstRedisConnCtx,"DEL %s",pcTerminalID);
    if ( NULL == reply )
    {
        printf("REDIS_ProxyInfoSet error=%s\n", pstRedisConnCtx->errstr);
        return;
    }
    
    freeReplyObject(reply);
    

    return;
}


long REDIS_Terminal_InfoUpdate(redisContext   *    pstRedisConnCtx,
                              unsigned char *pcTerminalID,
                              unsigned char *pcTerminalStat,
                              unsigned int uiAppVersion,
                              unsigned int uiClientAddr,
                              unsigned int uiClientPort)
{
    redisReply*     reply = NULL;

    if ( NULL == pstRedisConnCtx )
    {
        return VOS_ERR;
    }

    reply = redisCommand(pstRedisConnCtx, REDIS_TERMINFO_CMD_UPDT, 
                         pcTerminalID,
                         uiAppVersion, 
                         pcTerminalStat, 
                         uiClientAddr, 
                         uiClientPort);
    if ( NULL == reply )
    {
        printf("REDIS_ProxyInfoSet error=%s\n", pstRedisConnCtx->errstr);
        return VOS_ERR;
    }
    freeReplyObject(reply);

    return VOS_OK;
}


long REDIS_Terminal_InfoUpdateStatus(redisContext   *    pstRedisConnCtx, unsigned char *pcTerminalID, unsigned int uiTerminalOnline)
{
    redisReply*     reply = NULL;

    if ( NULL == pstRedisConnCtx )
    {
        return VOS_ERR;
    }

    if ( uiTerminalOnline )
    {
        reply = redisCommand(pstRedisConnCtx, REDIS_TERMINFO_CMD_UPST, pcTerminalID, REDIS_TMINFO_STAUS_ONLINE);
    }
    else
    {
        reply = redisCommand(pstRedisConnCtx, REDIS_TERMINFO_CMD_UPST, pcTerminalID, REDIS_TMINFO_STAUS_OFFLINE);
    }
    
    if ( NULL == reply )
    {
        printf("REDIS_Terminal_InfoUpdate status error=%s\n", pstRedisConnCtx->errstr);
        return VOS_ERR;
    }
    else
    {
        printf("REDIS_Terminal_InfoUpdate status successful!, pcTerminalID=%s\n", pcTerminalID );
    }

    freeReplyObject(reply);


    return VOS_OK;
}

                              


