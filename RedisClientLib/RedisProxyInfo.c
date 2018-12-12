/******************************************************************************

                  版权所有 (C), 2018-2028, 技术有限公司

 ******************************************************************************
  文 件 名   : RedisProxyApi.h
  版 本 号   : 初稿
  作    者   : jimk
  生成日期   : 2018年11月29日
  最近修改   :
  功能描述   : 接口测试
  函数列表   :
  修改历史   :
  1.日    期   : 2018年11月29日
    作    者   : jimk
    修改内容   : 创建文件

******************************************************************************/

#include <RedisComm.h>

/*****************************************************************************
 函 数 名  : REDIS_ProxyInfoSet
 功能描述  : 代理信息设置
 输入参数  : redisContext   *    pstRedisConnCtx  
             unsigned char *pcSevID               
             unsigned char *pcSevConnNums         
             unsigned char *pcSevAddr             
             unsigned char *pcSevPort             
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年12月11日
    作    者   : 蒋康
    修改内容   : 新生成函数

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
 函 数 名  : REDIS_ProxyInfoGet
 功能描述  : 代理信息获取
 输入参数  : redisContext* pstRedisConnCtx  
             unsigned char *pcSevID         
             unsigned char *pcSevConnNums   
             unsigned char *pcSevAddr       
             unsigned char *pcSevPort       
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年12月11日
    作    者   : 蒋康
    修改内容   : 新生成函数

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



