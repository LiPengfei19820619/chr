#ifndef CHR_MMTEL_DATA_INC
#define CHR_MMTEL_DATA_INC

/* chr_mmtel_data.inc */
/* 本文件是通过工具自动生成，请勿手工修改 */

#include "tulip.h"


typedef struct CHR_SYSCLOCK_T
{
    WORD16                      wSysYear;    /* 年 */
    WORD16                      ucSysMon;
    WORD16                      ucSysDay;
    WORD16                      ucSysHour;
    WORD16                      ucSysMin;
    WORD16                      ucSysSec;
    WORD16                      wMilliSec;
    WORD16                      ucSysWeek;
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
    CHAR                        achXZteCause[48];
    CHAR                        chSgroupMark[32];
    WORD16                      wSgroup;
    CHAR                        achDialedURI[128];
    BYTE                        bCallType;
    BYTE                        bCallProcessFlag;
    BYTE                        bReleaseLocationFlag;
    WORD32                      dwCscfNodeId;
    BYTE                        bFailCodeNum;
    BYTE                        bServiceCounter;
    BYTE                        bSipCauseTimes;
    WORD32                      dwCHRType;
    WORD16                      wCHRAttrNodeRole;
    WORD16                      wCHRCloseReason;
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
    BYTE                        abPad2[1];
    CHAR                        chOneTestCaseId[64];
    WORD32                      dwTrailNodeID;
    BYTE                        abPad3[4];    /* 对齐 */
} CHR_MMTEL_DATA_T;



#endif /* CHR_MMTEL_DATA_INC */

/* The End Of The File. */

