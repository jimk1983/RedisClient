/******************************************************************************

                  版权所有 (C), 2018-2028, 杭州友机技术有限公司

 ******************************************************************************
  文 件 名   : RedisDefine.h
  版 本 号   : 初稿
  作    者   : 蒋康
  生成日期   : 2018年12月5日
  最近修改   :
  功能描述   : Redis文件的定义
  函数列表   :
  修改历史   :
  1.日    期   : 2018年12月5日
    作    者   : 蒋康
    修改内容   : 创建文件

******************************************************************************/



/****************************** 字符串命令 *************************************/
#define REDIS_CMD_STR_SET           "SET"       /* 字符串设置 : SET key value */
#define REDIS_CMD_STR_MSET          "MSET"      /* 字符串设置多个: SET key value [key value]*/
#define REDIS_CMD_STR_SETNX         "SETNX"     /* 字符串不存在的KEY: SETNX key value */
#define REDIS_CMD_STR_GET           "GET"       /* 字符串获取 : GET key */
#define REDIS_CMD_STR_GETSET        "GETSET"    /* 原子级: 字符串获取老的设置新的 */


/****************************** 哈希命令 **************************************/
#define REDIS_CMD_HASH_SET          "HSET"      /* Hash设置 : HSET key field */
#define REDIS_CMD_HASH_GET          "HGET"      /* Hash获取 : HGET key   */
#define REDIS_CMD_HASH_MGET         "HMGET"     /* Hash获取多个 : HMGET key */

/******************************************************************************/
#define REDIS_CMD_KEY_DEL           "DEL"       /* 删除KEY */


/****************************** 业务定义 *************************************/
#define REDIS_PXYINFO_STR_CONN      "pxyconn"           /*代理连接*/
#define REDIS_PXYINFO_STR_ADDR      "pxyaddr"           /*代理地址*/
#define REDIS_PXYINFO_STR_PORT      "pxyport"           /*代理端口*/


#define REDIS_TERMINFO_STR_MID      "tmid"      /*终端ID*/
#define REDIS_TERMINFO_STR_DES      "tmdes"     /*终端描述*/
#define REDIS_TERMINFO_STR_VERN     "tmver"     /*终端版本*/
#define REDIS_TERMINFO_STR_STUS     "tmstat"    /*终端状态*/
#define REDIS_TERMINFO_STR_ADDR     "tmaddr"    /*终端地址*/
#define REDIS_TERMINFO_STR_PORT     "tmport"    /*终端端口*/

/*设置终端信息HSET TerminalID       termalinfodes value tm */
#define REDIS_TERMINFO_CMD_HSET     "HSET %s tmdes %s tmver %08x tmstat %s tmaddr %s tmport %d"
/*更新*/
#define REDIS_TERMINFO_CMD_UPDT     "HSET %s tmver %08x tmstat %s tmaddr %s tmport %d"
/*更新状态*/
#define REDIS_TERMINFO_CMD_UPST     "HSET %s tmstat %s"     



