/**
 * cqapi.h
 * based on previous work by coxxs and orzfly
 */

#pragma once

#include "cqdefines.h"

CQAPI(int32_t) CQ_sendPrivateMsg(int32_t AuthCode, int64_t QQID, const char *msg);
CQAPI(int32_t) CQ_sendGroupMsg(int32_t AuthCode, int64_t groupid, const char *msg);
CQAPI(int32_t) CQ_sendDiscussMsg(int32_t AuthCode, int64_t discussid, const char *msg);
CQAPI(int32_t) CQ_deleteMsg(int32_t AuthCode, int64_t msgid);
CQAPI(int32_t) CQ_sendLike(int32_t AuthCode, int64_t QQID);
CQAPI(int32_t) CQ_setGroupKick(int32_t AuthCode, int64_t groupid, int64_t QQID, CQ_BOOL rejectaddrequest);
CQAPI(int32_t) CQ_setGroupAdmin(int32_t AuthCode, int64_t groupid, int64_t QQID, CQ_BOOL setadmin);
CQAPI(int32_t) CQ_setGroupWholeBan(int32_t AuthCode, int64_t groupid, CQ_BOOL enableban);
CQAPI(int32_t) CQ_setGroupBan(int32_t AuthCode, int64_t groupid, int64_t QQID, int64_t duration);
CQAPI(int32_t) CQ_setGroupAnonymousBan(int32_t AuthCode, int64_t groupid, const char *anomymous, int64_t duration);
CQAPI(int32_t) CQ_setGroupAnonymous(int32_t AuthCode, int64_t groupid, CQ_BOOL enableanomymous);
CQAPI(int32_t) CQ_setGroupCard(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newcard);
CQAPI(int32_t) CQ_setGroupSpecialTitle(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newspecialtitle, int64_t duration);
CQAPI(int32_t) CQ_setGroupLeave(int32_t AuthCode, int64_t groupid, CQ_BOOL isdismiss);
CQAPI(int32_t) CQ_setDiscussLeave(int32_t AuthCode, int64_t discussid);
CQAPI(int32_t) CQ_setFriendAddRequest(int32_t AuthCode, CQ_RESPONSE_FLAG responseflag, int32_t responseoperation, const char *remark);
CQAPI(int32_t) CQ_setGroupAddRequestV2(int32_t AuthCode, CQ_RESPONSE_FLAG responseflag, int32_t requesttype, int32_t responseoperation, const char *reason);
CQAPI(const char *) CQ_getGroupMemberInfoV2(int32_t AuthCode, int64_t groupid, int64_t QQID, CQ_BOOL nocache);
CQAPI(const char *) CQ_getStrangerInfo(int32_t AuthCode, int64_t QQID, CQ_BOOL nocache);
CQAPI(const char *) CQ_getCookies(int32_t AuthCode);
CQAPI(int32_t) CQ_getCsrfToken(int32_t AuthCode);
CQAPI(int64_t) CQ_getLoginQQ(int32_t AuthCode);
CQAPI(const char *) CQ_getLoginNick(int32_t AuthCode);
CQAPI(const char *) CQ_getAppDirectory(int32_t AuthCode);
CQAPI(int32_t) CQ_addLog(int32_t AuthCode, int32_t priority, const char *category, const char *content);
CQAPI(int32_t) CQ_setFatal(int32_t AuthCode, const char *errorinfo);
