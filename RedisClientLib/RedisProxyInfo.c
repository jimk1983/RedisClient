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

/*****************************************************************************
 �� �� ��  : REDIS_ProxyInfoSet
 ��������  : ������Ϣ����
 �������  : redisContext   *    pstRedisConnCtx  
             unsigned char *pcSevID               
             unsigned char *pcSevConnNums         
             unsigned char *pcSevAddr             
             unsigned char *pcSevPort             
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��12��11��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
long REDIS_ProxyInfoSet(redisContext   *    pstRedisConnCtx,
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

    reply = redisCommand(pstRedisConnCtx,"HSET %s pxyconn %s pxyaddr %s pxyport %s", 
                                         pcSevID,pcSevConnNums, pcSevAddr,pcSevPort);
    if ( NULL == reply )
    {
        printf("REDIS_ProxyInfoSet error=%s\n", pstRedisConnCtx->errstr);
        return VOS_ERR;
    }
    freeReplyObject(reply);
    
    return VOS_OK;
}



/*****************************************************************************
 �� �� ��  : REDIS_ProxyInfoGet
 ��������  : ������Ϣ��ȡ
 �������  : redisContext* pstRedisConnCtx  
             unsigned char *pcSevID         
             unsigned char *pcSevConnNums   
             unsigned char *pcSevAddr       
             unsigned char *pcSevPort       
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��12��11��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
long REDIS_ProxyInfoGet(redisContext* pstRedisConnCtx,
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
    
    reply = redisCommand(pstRedisConnCtx,"HMGET %s pxyconn pxyaddr pxyport", pcSevID);
    if ( NULL == reply )
    {
        printf("REDIS_ProxyInfoSet error=%s\n", pstRedisConnCtx->errstr);
        return VOS_ERR;
    }
    

    strcpy((char *)pcSevConnNums,reply->element[0]->str); 
    strcpy((char *)pcSevAddr,reply->element[1]->str); 
    strcpy((char *)pcSevPort,reply->element[2]->str); 
        
    //printf("REDIS_ProxyInfoGet: pxyconn=%s,pxaddr=%s, pxyport=%s, keyid=[%s]\n",
    //    pcSevConnNums,pcSevAddr,pcSevPort, pcSevID);
    freeReplyObject(reply);
    
    

    return VOS_OK;
}



