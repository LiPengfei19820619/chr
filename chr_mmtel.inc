typedef struct CHR_SYSCLOCK_T
{
    WORD16              wSysYear;
    WORD16              ucSysMon;
    WORD16              ucSysDay;
    WORD16              ucSysHour;
    WORD16              ucSysMin;
    WORD16              ucSysSec;
    WORD16              wMilliSec;
    WORD16              ucSysWeek;
} CHR_SYSCLOCK_T;

typedef struct chr_mmtel
{
    BYTE                bReceivedMsg;
    CHAR                achXZteCause[48];
    CHR_SYSCLOCK_T      tSipRequestTimestamp;
    CHR_SYSCLOCK_T      tSipReponseTimestamp;
    WORD32              adwFailCode[8];
} CHR_MMTEL;
