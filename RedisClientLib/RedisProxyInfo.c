/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �������޹�˾

 ******************************************************************************
  �� �� ��   : RedisProxyApi.h
  �� �� ��   : ����
  ��    ��   : jimk
  ��������   : 2018��11��29��
  ����޸�   :
  ��������   : �ӿڲ���
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��11��29��
    ��    ��   : jimk
    �޸�����   : �����ļ�

******************************************************************************/

#include <RedisComm.h>


long REDIS_ProxyInfoAllSet(redisContext   *    pstRedisConnCtx,
                                 unsigned char *pcSevID,
                                 unsigned char *pcSevConnNums, 
                                 unsigned char *pcSevAddr, 
                                 unsigned char *pcSevPort )
{
    redisReply*     reply = NULL;

    if ( NULL == pstRedisConnCtx )
    {
        return VOS_ERR;
    }

    reply = redisCommand(pstRedisConnCtx,"HSET %s proxyconn %s proxyaddr %s proxyport %s", pcSevID,pcSevConnNums, pcSevAddr,pcSevPort);
    freeReplyObject(reply);

    //reply = redisCommand(pstRedisConnCtx,"HGETALL %s", pcSevID);
    reply = redisCommand(pstRedisConnCtx,"HGET %s proxyconn", pcSevID);
    
    printf("%s\n",reply->str);
    freeReplyObject(reply);
    
    return VOS_OK;
}




