/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �������޹�˾

 ******************************************************************************
  �� �� ��   : RedisLibApi.h
  �� �� ��   : ����
  ��    ��   : jimk
  ��������   : 2018��11��27��
  ����޸�   :
  ��������   : �ӿڲ���
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��11��27��
    ��    ��   : jimk
    �޸�����   : �����ļ�

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






