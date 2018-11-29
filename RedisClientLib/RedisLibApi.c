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


#include <RedisComm.h>

/*****************************************************************************
 �� �� ��  : REDIS_API_ConnCreate
 ��������  : ���ӵĴ���
 �������  : unsigned char *pcSevAddr  
             unsigned char *pcSevPort  
             void *pvUserCtx           
 �������  : ��
 �� �� ֵ  : REDIS_CONN_S
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
REDIS_CONN_S *REDIS_API_ConnCreate(unsigned char *pcSevAddr, unsigned char *pcSevPort, void *pvUserCtx)
{
    


    return NULL;
}


/*****************************************************************************
 �� �� ��  : REDIS_API_ConnRelease
 ��������  : ���ӵ��ͷ�
 �������  : REDIS_CONN_S **ppstConn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
void REDIS_API_ConnRelease(REDIS_CONN_S **ppstConn)
{
    REDIS_CONN_S*   pstConn = NULL;
    redisContext*   pstRedisConn = NULL;
    
    if ( NULL == ppstConn )
    {
        return;    
    }

    pstConn = *ppstConn;

    pstRedisConn= (redisContext *)pstConn->pstRedisCtx;

    if ( NULL != pstRedisConn )
    {
       redisFree(pstRedisConn);
    }
    
    *ppstConn = NULL;
}


/*****************************************************************************
 �� �� ��  : REDIS_API_TerminalInfoSet
 ��������  : �ն���Ϣ����
 �������  : REDIS_TERMAL_INFO_S *pstInfo  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

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
 �� �� ��  : REDIS_API_TerminalInfoGet
 ��������  : �ն���Ϣ��ȡ
 �������  : REDIS_TERMAL_INFO_S *pstInfo  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

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
 �� �� ��  : REDIS_API_TerminalInfoGetSet
 ��������  : ����ΪҪ���õ��µ�ֵ��Ȼ�󷵻س�ԭ���ϵ�ֵ
 �������  : INOUT REDIS_TERMAL_INFO_S *pstInfoGetSet  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

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
 �� �� ��  : REDIS_API_ProxyGatewayInfoSet
 ��������  : ������Ϣ����
 �������  : IN REDIS_PROXYGW_INFO_S *pstInfo  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
long REDIS_API_ProxyGatewayInfoSet(IN REDIS_CONN_S *pstConn,IN REDIS_PROXYGW_INFO_S *pstInfo)
{
    if ( NULL == pstInfo
        || NULL == pstConn )
    {
        return VOS_ERR;
    }
    

    return VOS_OK;
}


/*****************************************************************************
 �� �� ��  : REDIS_API_ProxyGatewayInfoGet
 ��������  : ������Ϣ��ȡ
 �������  : OUT REDIS_PROXYGW_INFO_S *pstInfo  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
long REDIS_API_ProxyGatewayInfoGet(IN REDIS_CONN_S *pstConn,OUT REDIS_PROXYGW_INFO_S *pstInfo)
{
    if ( NULL == pstInfo
        || NULL == pstConn )
    {
        return VOS_ERR;
    }
    

    return VOS_OK;
}


/*****************************************************************************
 �� �� ��  : REDIS_API_ProxyGatewayInfoGetSet
 ��������  : �����µ�ֵ�����س�ԭ�����ϵ�ֵ
 �������  : INOUT REDIS_PROXYGW_INFO_S *pstInfoGetSet  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2018��11��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

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





