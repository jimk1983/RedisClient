/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �����ѻ��������޹�˾

 ******************************************************************************
  �� �� ��   : RedisDefine.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2018��12��5��
  ����޸�   :
  ��������   : Redis�ļ��Ķ���
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��12��5��
    ��    ��   : ����
    �޸�����   : �����ļ�

******************************************************************************/



/****************************** �ַ������� *************************************/
#define REDIS_CMD_STR_SET           "SET"       /* �ַ������� : SET key value */
#define REDIS_CMD_STR_MSET          "MSET"      /* �ַ������ö��: SET key value [key value]*/
#define REDIS_CMD_STR_SETNX         "SETNX"     /* �ַ��������ڵ�KEY: SETNX key value */
#define REDIS_CMD_STR_GET           "GET"       /* �ַ�����ȡ : GET key */
#define REDIS_CMD_STR_GETSET        "GETSET"    /* ԭ�Ӽ�: �ַ�����ȡ�ϵ������µ� */


/****************************** ��ϣ���� **************************************/
#define REDIS_CMD_HASH_SET          "HSET"      /* Hash���� : HSET key field */
#define REDIS_CMD_HASH_GET          "HGET"      /* Hash��ȡ : HGET key   */
#define REDIS_CMD_HASH_MGET         "HMGET"     /* Hash��ȡ��� : HMGET key */

/******************************************************************************/
#define REDIS_CMD_KEY_DEL           "DEL"       /* ɾ��KEY */


/****************************** ҵ���� *************************************/
#define REDIS_PXYINFO_STR_CONN      "pxyconn"           /*��������*/
#define REDIS_PXYINFO_STR_ADDR      "pxyaddr"           /*�����ַ*/
#define REDIS_PXYINFO_STR_PORT      "pxyport"           /*����˿�*/


#define REDIS_TERMINFO_STR_MID      "tmid"      /*�ն�ID*/
#define REDIS_TERMINFO_STR_DES      "tmdes"     /*�ն�����*/
#define REDIS_TERMINFO_STR_VERN     "tmver"     /*�ն˰汾*/
#define REDIS_TERMINFO_STR_STUS     "tmstat"    /*�ն�״̬*/
#define REDIS_TERMINFO_STR_ADDR     "tmaddr"    /*�ն˵�ַ*/
#define REDIS_TERMINFO_STR_PORT     "tmport"    /*�ն˶˿�*/

/*�����ն���ϢHSET TerminalID       termalinfodes value tm */
#define REDIS_TERMINFO_CMD_HSET     "HSET %s tmdes %s tmver %08x tmstat %s tmaddr %s tmport %d"
/*����*/
#define REDIS_TERMINFO_CMD_UPDT     "HSET %s tmver %08x tmstat %s tmaddr %s tmport %d"
/*����״̬*/
#define REDIS_TERMINFO_CMD_UPST     "HSET %s tmstat %s"     



