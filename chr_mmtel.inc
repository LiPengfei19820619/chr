typedef struct CHR_SYSCLOCK_T
{
    WORD16                      wSysYear;
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

typedef struct chr_mmtel
{
    BYTE                        bReceivedMsg;
    BYTE                        bMoMtFlag;
    BYTE                        bCtxFlag;
    WORD32                      dwCallFailCause;
    BYTE                        bRcvXZteCause;
    CHAR                        achXZteCause[48];
    CHAR                        chSgroupMark[32];
    WORD16                      wSgroup;
    CHR_SYSCLOCK_T              tSipRequestTimestamp;
    CHR_SYSCLOCK_T              tSipReponseTimestamp;
    CHR_STAT_STATUS_T           tStatStatus[50];
    WORD32                      tStatStatusNum;
    WORD32                      adwFailCode[8];
    WORD32                      adwFailCodeNum;
} CHR_MMTEL_DATA_T, PUB_CHR_MSG_T;
