/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �������޹�˾

 ******************************************************************************
  �� �� ��   : RedisTerminalApi.h
  �� �� ��   : ����
  ��    ��   : jimk
  ��������   : 2018��11��29��
  ����޸�   :
  ��������   : �ն���Ϣ����Redis-Hash��ʵ��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��11��29��
    ��    ��   : jimk
    �޸�����   : �����ļ�
˵��:
    1. �ն���Ϣ����Redis��Hash�������Ĵ��ÿ���ն˵ľ�����Ϣ
    2. �ն���Ϣ����Redis�ļ�������������ն˵�������Ϣ/������Ϣ
    
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



