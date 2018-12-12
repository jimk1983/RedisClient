/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �������޹�˾

 ******************************************************************************
  �� �� ��   : RedisTerminalApi.cpp
  �� �� ��   : ����
  ��    ��   : jimk
  ��������   : 2018��11��29��
  ����޸�   :
  ��������   : �ն���Ϣ����Redis-Hash��ʵ��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��11��29��
    ��    ��   : jimk
    �޸�����   : �����ļ�
˵��:
    1. �ն���Ϣ����Redis��Hash�������Ĵ��ÿ���ն˵ľ�����Ϣ
    2. �ն���Ϣ����Redis�ļ�������������ն˵�������Ϣ/������Ϣ
    
******************************************************************************/
#include <RedisComm.h>


/************************ Redis�ն���Ϣhash�� *************************/
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

                              


