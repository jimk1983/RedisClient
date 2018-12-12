/******************************************************************************

                  版权所有 (C), 2018-2028, 技术有限公司

 ******************************************************************************
  文 件 名   : RedisTerminalApi.h
  版 本 号   : 初稿
  作    者   : jimk
  生成日期   : 2018年11月29日
  最近修改   :
  功能描述   : 终端信息采用Redis-Hash来实现
  函数列表   :
  修改历史   :
  1.日    期   : 2018年11月29日
    作    者   : jimk
    修改内容   : 创建文件
说明:
    1. 终端信息采用Redis的Hash来单独的存放每个终端的具体信息
    2. 终端信息采用Redis的集合来存放所有终端的在线信息/离线信息
    
******************************************************************************/



long REDIS_Terminal_InfoAdd(redisContext   *    pstRedisConnCtx,
                                 unsigned char *pcTerminalID,
                                 unsigned char *pcTerminalDescptor,
                                 unsigned char *pcTerminalAddr,
                                 unsigned int  uiTerminalPort);


void REDIS_Terminal_InfoDel(redisContext* pstRedisConnCtx,
                                 unsigned char *pcTerminalID);


long REDIS_Terminal_InfoUpdate(redisContext   *    pstRedisConnCtx,
                              unsigned char *pcTerminalID,
                              unsigned char *pcTerminalStat,
                              unsigned int uiAppVersion,
                              unsigned char *pcClientAddr,
                              unsigned int uiClientPort);

long REDIS_Terminal_InfoUpdateStatus(redisContext   *    pstRedisConnCtx, unsigned char *pcTerminalID, unsigned int uiTerminalOnline);



