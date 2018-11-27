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


#include <hiredis/hiredis.h>
#include "RedisLibApi.h"

void Redis_Api_ForTest(const char *pcHostAddr, unsigned int uiPort)
{
    
    redisContext *conn = redisConnect(pcHostAddr, uiPort);
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






