#include <RedisLibApi.h>
#include <string.h>
#include <stdio.h>
#include <hiredis/hiredis.h>


void testRedisConnection()
{

    redisContext *conn = redisConnect("182.61.36.87", 6379);
   if( conn != NULL && conn->err )
   {
	printf("connection error: %s\n", conn->errstr);
   }
   redisReply *reply = (redisReply *)redisCommand(conn, "set foo 123");
   freeReplyObject(reply);

   reply = redisCommand(conn, "get foo");
   printf("get foo value=%s\n", reply->str);
   freeReplyObject(reply);  
  
   redisFree(conn);


}

int main()
{
    REDIS_CONN_S *pstRedisConn  = NULL;
    REDIS_PROXYGW_INFO_S stGwInfo = {0};
    REDIS_TERMAL_INFO_S  stTmInfo = {0};

	printf("******Redis Api Start******\n");

    //testRedisConnection();
    
    pstRedisConn = REDIS_API_ConnCreate("182.61.36.87", 6379, NULL);
	if ( NULL == pstRedisConn )
	{
	    printf("******Redis connect create error!*******\n");
	    return -1;
	}

    strcpy((char *)stGwInfo.acProxyServerInfoID, "12345678");
    strcpy((char *)stGwInfo.acProxyServerConnNums, "1111");    
    strcpy((char *)stGwInfo.acProxyServerAddr, "1.1.1.1");
    strcpy((char *)stGwInfo.acProxyServerCtrlPort, "443");
    
    if ( VOS_ERR == REDIS_API_ProxyGatewayInfoSet(pstRedisConn, &stGwInfo) )
    {
        printf("******Redis Set gateway info error!*******\n");
        REDIS_API_ConnRelease(&pstRedisConn);
	    return -1;
    }

    memset(stGwInfo.acProxyServerAddr, 0, REDIS_COMM_LEN);
    memset(stGwInfo.acProxyServerConnNums, 0, REDIS_COMM_LEN);
    memset(stGwInfo.acProxyServerCtrlPort, 0, REDIS_COMM_LEN);
    if ( VOS_ERR == REDIS_API_ProxyGatewayInfoGet(pstRedisConn, &stGwInfo)  )
    {
        printf("******Redis Get gateway info error!*******\n");
        REDIS_API_ConnRelease(&pstRedisConn);
	    return -1;
    }

    memset(stGwInfo.acProxyServerAddr, 0, REDIS_COMM_LEN);
    memset(stGwInfo.acProxyServerConnNums, 0, REDIS_COMM_LEN);
    memset(stGwInfo.acProxyServerCtrlPort, 0, REDIS_COMM_LEN);
    if ( VOS_ERR == REDIS_API_ProxyGatewayInfoGet(pstRedisConn, &stGwInfo)  )
    {
        printf("******Redis Get gateway info error!*******\n");
        REDIS_API_ConnRelease(&pstRedisConn);
	    return -1;
    }
    
    strcpy((char *)stTmInfo.acTerminalID, "testTmOne");
    strcpy((char *)stTmInfo.acTerminalDesptor, "testTmHello");
    
    
    if ( VOS_ERR == REDIS_API_TerminalInfoSet(pstRedisConn, &stTmInfo) )
    {
        printf("******Redis set Terminal info error!*******\n");
        REDIS_API_ConnRelease(&pstRedisConn);
	    return -1;
    }
    
    REDIS_API_ConnRelease(&pstRedisConn);

	printf("******Redis Api End******\n");
	return 0;
}                                                                                                                                  