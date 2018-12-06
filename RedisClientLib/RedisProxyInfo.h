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






long REDIS_ProxyInfoSet(redisContext   *    pstRedisConnCtx,
                                 unsigned char *pcSevID,
                                 unsigned char *pcSevConnNums, 
                                 unsigned char *pcSevAddr, 
                                 unsigned char *pcSevPort );


long REDIS_ProxyInfoGet(redisContext* pstRedisConnCtx,
                                 unsigned char *pcSevID,
                                 unsigned char *pcSevConnNums, 
                                 unsigned char *pcSevAddr, 
                                 unsigned char *pcSevPort );


