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


#include <RedisComm.h>

/*****************************************************************************
 函 数 名  : REDIS_API_ConnCreate
 功能描述  : 连接的创建
 输入参数  : unsigned char *pcSevAddr  
             unsigned char *pcSevPort  
             void *pvUserCtx           
 输出参数  : 无
 返 回 值  : REDIS_CONN_S
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
REDIS_CONN_S *REDIS_API_ConnCreate(char *pcSevAddr, int iSevPort, void *pvUserCtx)
{
    REDIS_CONN_S*       pstConn = NULL;
    REDIS_CONN_INFO_S*  pstRedisConn = NULL;
    redisContext*       pstRedisConnCtx = NULL;
    
    if ( NULL == pcSevAddr )
    {
        return NULL;
    }

    pstConn = (REDIS_CONN_S *)malloc(sizeof(REDIS_CONN_S));
    if ( NULL == pstConn )
    {
        return NULL;
    }
    memset(pstConn, 0, sizeof(REDIS_CONN_S));

    pstRedisConn = (REDIS_CONN_INFO_S *)malloc(sizeof(REDIS_CONN_INFO_S));    
    if ( NULL == pstRedisConn )
    {
        free(pstConn);
        return NULL;
    }
    memset(pstRedisConn, 0, sizeof(REDIS_CONN_INFO_S));

    pstRedisConnCtx = redisConnect((const char *)pcSevAddr, iSevPort);
    if ( pstRedisConnCtx != NULL 
         && pstRedisConnCtx->err ) 
    { 
        free(pstRedisConn);
        free(pstConn);
        return NULL;
    }
    pstRedisConn->pstRedisConnCtx = pstRedisConnCtx;

    strcpy(pstConn->acServerAddr, pcSevAddr);
    pstConn->iSevPort = iSevPort;
    pstConn->pstRedisConn = (void *)pstRedisConn;

    
    return pstConn;
}


/*****************************************************************************
 函 数 名  : REDIS_API_ConnRelease
 功能描述  : 连接的释放
 输入参数  : REDIS_CONN_S **ppstConn  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
void REDIS_API_ConnRelease(REDIS_CONN_S **ppstConn)
{
    REDIS_CONN_S*       pstConn = NULL;
    REDIS_CONN_INFO_S*  pstRedisConn = NULL;
    
    if ( NULL == ppstConn )
    {
        return;    
    }

    pstConn = *ppstConn;

    pstRedisConn= (REDIS_CONN_INFO_S *)pstConn->pstRedisConn;

    if ( NULL != pstRedisConn)
    {
       if ( NULL != pstRedisConn->pstRedisConnCtx  )
       {
            redisFree(pstRedisConn->pstRedisConnCtx);
            pstRedisConn->pstRedisConnCtx= NULL;
       }
       
       free(pstRedisConn);
       pstConn->pstRedisConn = NULL;
    }
    
    free(pstConn);
    *ppstConn = NULL;
}


/*****************************************************************************
 函 数 名  : REDIS_API_TerminalInfoSet
 功能描述  : 终端信息设置
 输入参数  : REDIS_TERMAL_INFO_S *pstInfo  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
long REDIS_API_TerminalInfoSet(IN REDIS_CONN_S *pstConn, IN REDIS_TERMAL_INFO_S *pstInfo)
{
    if ( NULL == pstInfo
        || NULL == pstConn )
    {
        return VOS_ERR;
    }
    

    return VOS_OK;
}


/*****************************************************************************
 函 数 名  : REDIS_API_TerminalInfoGet
 功能描述  : 终端信息获取
 输入参数  : REDIS_TERMAL_INFO_S *pstInfo  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
long REDIS_API_TerminalInfoGet(IN REDIS_CONN_S *pstConn,OUT REDIS_TERMAL_INFO_S *pstInfo)
{
    if ( NULL == pstInfo
        || NULL == pstConn )
    {
        return VOS_ERR;
    }
    



    return VOS_OK;
}



/*****************************************************************************
 函 数 名  : REDIS_API_TerminalInfoGetSet
 功能描述  : 输入为要设置的新的值，然后返回出原来老的值
 输入参数  : INOUT REDIS_TERMAL_INFO_S *pstInfoGetSet  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
long REDIS_API_TerminalInfoGetSet(IN REDIS_CONN_S *pstConn,INOUT REDIS_TERMAL_INFO_S *pstInfoGetSet)
{
    
    if ( NULL == pstInfoGetSet
        || NULL == pstConn )
    {
        return VOS_ERR;
    }



    return VOS_OK;
}



/*****************************************************************************
 函 数 名  : REDIS_API_ProxyGatewayInfoSet
 功能描述  : 网关信息设置
 输入参数  : IN REDIS_PROXYGW_INFO_S *pstInfo  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
long REDIS_API_ProxyGatewayInfoSet(IN REDIS_CONN_S *pstConn,IN REDIS_PROXYGW_INFO_S *pstInfo)
{
    redisContext*       pstRedisConnCtx     = NULL;
    REDIS_CONN_INFO_S*  pstRedisConnInfo    = NULL;

    if ( NULL == pstInfo
        || NULL == pstConn
        || NULL == pstConn->pstRedisConn )
    {
        return VOS_ERR;
    }

    pstRedisConnInfo = (REDIS_CONN_INFO_S *)pstConn->pstRedisConn;
    if ( NULL == pstRedisConnInfo->pstRedisConnCtx  )
    {
        return VOS_ERR;
    }
    
    pstRedisConnCtx = pstRedisConnInfo->pstRedisConnCtx;
    if ( VOS_ERR == REDIS_ProxyInfoSet(pstRedisConnCtx, 
                                          pstInfo->acProxyServerInfoID, 
                                          pstInfo->acProxyServerConnNums,
                                          pstInfo->acProxyServerAddr,
                                          pstInfo->acProxyServerCtrlPort)  )
    {
        return VOS_ERR;
    }

    return VOS_OK;
}


/*****************************************************************************
 函 数 名  : REDIS_API_ProxyGatewayInfoGet
 功能描述  : 网关信息获取
 输入参数  : OUT REDIS_PROXYGW_INFO_S *pstInfo  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
long REDIS_API_ProxyGatewayInfoGet(IN REDIS_CONN_S *pstConn,OUT REDIS_PROXYGW_INFO_S *pstInfo)
{
    redisContext*       pstRedisConnCtx     = NULL;
    REDIS_CONN_INFO_S*  pstRedisConnInfo    = NULL;

    if ( NULL == pstInfo
        || NULL == pstConn
        || NULL == pstConn->pstRedisConn )
    {
        return VOS_ERR;
    }

    pstRedisConnInfo = (REDIS_CONN_INFO_S *)pstConn->pstRedisConn;
    if ( NULL == pstRedisConnInfo->pstRedisConnCtx  )
    {
        return VOS_ERR;
    }
    
    pstRedisConnCtx = pstRedisConnInfo->pstRedisConnCtx;
    if ( VOS_ERR == REDIS_ProxyInfoGet(pstRedisConnCtx, 
                                          pstInfo->acProxyServerInfoID, 
                                          pstInfo->acProxyServerConnNums,
                                          pstInfo->acProxyServerAddr,
                                          pstInfo->acProxyServerCtrlPort)  )
    {
        return VOS_ERR;
    }
                                          
    return VOS_OK;
}


/*****************************************************************************
 函 数 名  : REDIS_API_ProxyGatewayInfoGetSet
 功能描述  : 设置新的值，返回出原来的老的值
 输入参数  : INOUT REDIS_PROXYGW_INFO_S *pstInfoGetSet  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2018年11月29日
    作    者   : 蒋康
    修改内容   : 新生成函数

*****************************************************************************/
long REDIS_API_ProxyGatewayInfoGetSet(IN REDIS_CONN_S *pstConn, INOUT REDIS_PROXYGW_INFO_S *pstInfoGetSet)
{
    if ( NULL == pstInfoGetSet
        || NULL == pstConn )
    {
        return VOS_ERR;
    }

    
        

    return VOS_OK;
}





