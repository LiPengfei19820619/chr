/* chr_encode_mmtel.inc */
/* 本文件是通过工具自动生成，请勿手工修改 */


CHR_ENC_STRUCT_BEGIN(ptChrData, CHR_SYSCLOCK_T, ptJson)
    CHR_ENC_ITEM(ptChrData, wSysYear, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, ucSysMon, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, ucSysDay, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, ucSysHour, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, ucSysMin, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, ucSysSec, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, wMilliSec, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, ucSysWeek, NUMBER, ptJson)
CHR_ENC_STRUCT_END

CHR_ENC_STRUCT_BEGIN(ptChrData, CHR_STAT_STATUS_T, ptJson)
    CHR_ENC_ITEM(ptChrData, wStatId, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bFlag, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bStatResult, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bFailTypeFlag, NUMBER, ptJson)
CHR_ENC_STRUCT_END

CHR_ENC_MMTEL_BEGIN(ptChrData, ptJson)
    CHR_ENC_ITEM(ptChrData, bReceivedMsg, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bMoMtFlag, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bCtxFlag, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, dwCallFailCause, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bRcvXZteCause, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, achXZteCause, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chSgroupMark, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, wSgroup, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, achDialedURI, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, bCallType, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bCallProcessFlag, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bReleaseLocationFlag, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, dwCscfNodeId, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bFailCodeNum, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bServiceCounter, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, bSipCauseTimes, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, dwCHRType, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, wCHRAttrNodeRole, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, wCHRCloseReason, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, wSdpMediaIdentifier, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, wModule, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, wInstNo, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, chUserSessionId, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chChargingId, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chCallerTelUrl, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chCallerSipUrl, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chAccessNetWorkInfo, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chOriginatingIOI, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chCalledTelUrl, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chCalledSipUrl, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chTerminatingsIOI, STRING, ptJson)
    CHR_ENC_STRUCT(ptChrData, tSipRequestTimestamp, CHR_SYSCLOCK_T, ptJson)
    CHR_ENC_STRUCT(ptChrData, tSipReponseTimestamp, CHR_SYSCLOCK_T, ptJson)
    CHR_ENC_STRUCT(ptChrData, tServiceEndTimestamp, CHR_SYSCLOCK_T, ptJson)
    CHR_ENC_STRUCT(ptChrData, tConnectTimestamp, CHR_SYSCLOCK_T, ptJson)
    CHR_ENC_ITEM(ptChrData, chChargedPartyTelUrl, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chChargedPartySipUrl, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chServiceIdentity, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chConferenceIdentifier, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chServiceReasonReturnCode, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chCallingUserAgent, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, chCalledUserAgent, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, bDisconnectDirect, NUMBER, ptJson)
    CHR_ENC_ITEM(ptChrData, chOneTestCaseId, STRING, ptJson)
    CHR_ENC_ITEM(ptChrData, dwTrailNodeID, NUMBER, ptJson)
CHR_END_MMTEL_END



/* The End Of The File. */

