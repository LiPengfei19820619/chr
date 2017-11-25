#ifndef CHR_MMTEL_DATA_INC
#define CHR_MMTEL_DATA_INC

/* chr_mmtel_data.inc */
/* 本文件是通过工具自动生成，请勿手工修改 */

#include "tulip.h"


typedef struct CHR_SYSCLOCK_T
{
    WORD16                      wSysYear;    /* 年 */
    BYTE                        ucSysMon;    /* 月 */
    BYTE                        ucSysDay;    /* 日 */
    BYTE                        ucSysHour;    /* 时 */
    BYTE                        ucPading0;
    BYTE                        ucSysMin;    /* 分 */
    BYTE                        ucSysSec;    /* 秒 */
    WORD16                      wMilliSec;    /* 毫秒 */
    BYTE                        ucSysWeek;    /* 周 */
    BYTE                        ucPading1;
} CHR_SYSCLOCK_T;

typedef struct CHR_STAT_STATUS_T
{
    WORD16                      wStatId;
    BYTE                        bFlag;
    BYTE                        bStatResult;
    BYTE                        bFailTypeFlag;
    BYTE                        abPad[3];
} CHR_STAT_STATUS_T;

typedef struct CHR_MMTEL_DATA_T
{
    BYTE                        bReceivedMsg;    /* 收到过的消息 */
    BYTE                        bMoMtFlag;    /* 群呼叫关系 */
    BYTE                        bCtxFlag;
    WORD32                      dwCallFailCause;
    BYTE                        bRcvXZteCause;
#define  CSS_OBSRV_RCV_XZTECAUSE     (BYTE)0x01    /* 接收到X-ZTE-CAUSE */
    CHAR                        achXZteCause[48];
    CHAR                        chSgroupMark[32];
    WORD16                      wSgroup;
    CHAR                        achDialedURI[128];
    BYTE                        bCallType;
    BYTE                        bCallProcessFlag;
#define  CSS_CALL_SEIZE              (BYTE)0x01    /* 呼叫占用 */
#define  CSS_CALL_CONNECT            (BYTE)0x02    /* 呼叫接通 */
#define  CSS_CALL_ANSWER             (BYTE)0x04    /* 呼叫应答 */
#define  CSS_CALL_RELEASE            (BYTE)0x08    /* 呼叫释放 */
    BYTE                        bReleaseLocationFlag;
#define  CSS_REL_LOCATION_INTERNAL    (BYTE)0    /* 内部释放 */
#define  CSS_REL_LOCATION_EXTERNAL    (BYTE)1    /* 外部释放 */
    WORD32                      dwCscfNodeId;
    BYTE                        bFailCodeNum;
    BYTE                        bServiceCounter;
    BYTE                        bSipCauseTimes;
    WORD32                      dwCHRType;
#define  CSS_CALL_CHR_CHRTYPE_AS     69
    WORD16                      wCHRAttrNodeRole;
#define  CSS_CALL_CHR_CHRATTRNODEROLE_CALLER    0
#define  CSS_CALL_CHR_CHRATTRNODEROLE_CALLED    1
#define  CSS_CALL_CHR_CHRATTRNODEROLE_CF    4
    WORD16                      wCHRCloseReason;
#define  CSS_CALL_CHR_CHRCLOSEREASON_SUCCESS    0
#define  CSS_CALL_CHR_CHRCLOSEREASON_FAILURE    1
    WORD16                      wSdpMediaIdentifier;
    WORD16                      wModule;
    WORD16                      wInstNo;
    BYTE                        abPad1[2];
    CHAR                        chUserSessionId[128];
    CHAR                        chChargingId[128];
    CHAR                        chCallerTelUrl[128];
    CHAR                        chCallerSipUrl[128];
    CHAR                        chAccessNetWorkInfo[128];
    CHAR                        chOriginatingIOI[64];
    CHAR                        chCalledTelUrl[128];
    CHAR                        chCalledSipUrl[128];
    CHAR                        chTerminatingsIOI[64];
    CHR_SYSCLOCK_T              tSipRequestTimestamp;
    CHR_SYSCLOCK_T              tSipReponseTimestamp;
    CHR_SYSCLOCK_T              tServiceEndTimestamp;
    CHR_SYSCLOCK_T              tConnectTimestamp;
    CHAR                        chChargedPartyTelUrl[128];
    CHAR                        chChargedPartySipUrl[128];
    CHAR                        chServiceIdentity[64];
    CHAR                        chConferenceIdentifier[128];
    CHAR                        chServiceReasonReturnCode[6];
    CHAR                        chCallingUserAgent[64];
    CHAR                        chCalledUserAgent[64];
    BYTE                        bDisconnectDirect;
#define  CHR_DISCONNET_DIRECT_CALLER    1
#define  CHR_DISCONNET_DIRECT_CALLED    0
    BYTE                        abPad2[1];
    CHAR                        chOneTestCaseId[64];
    WORD32                      dwTrailNodeID;
    BYTE                        abPad3[4];    /* 对齐 */
    CHR_STAT_STATUS_T           tStatStatus[50];
    WORD32                      tStatStatusNum;
    WORD32                      adwFailCode[8];
    WORD32                      adwFailCodeNum;
} CHR_MMTEL_DATA_T;



#endif /* CHR_MMTEL_DATA_INC */

/* The End Of The File. */

