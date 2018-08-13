/**
 * cqapi.h
 * based on official vc++ sdk
 */

#pragma once

#include <cstdint>

#include "cqdefines.h"

// send messages

CQAPI(int32_t, CQ_sendPrivateMsg)(int32_t ac, int64_t qq, const char *msg);
CQAPI(int32_t, CQ_sendGroupMsg)(int32_t ac, int64_t group, const char *msg);
CQAPI(int32_t, CQ_sendDiscussMsg)(int32_t ac, int64_t discuss, const char *msg);
CQAPI(int32_t, CQ_deleteMsg)(int32_t ac, int64_t msgid);

// moderate group

CQAPI(int32_t, CQ_setGroupKick)(int32_t ac, int64_t group, int64_t qq, int32_t rejectaddrequest);
CQAPI(int32_t, CQ_setGroupAdmin)(int32_t ac, int64_t group, int64_t qq, int32_t setadmin);
CQAPI(int32_t, CQ_setGroupWholeBan)(int32_t ac, int64_t group, int32_t enableban);
CQAPI(int32_t, CQ_setGroupBan)(int32_t ac, int64_t group, int64_t qq, int64_t duration);
CQAPI(int32_t, CQ_setGroupAnonymousBan)(int32_t ac, int64_t group, const char *anomymous, int64_t duration);
CQAPI(int32_t, CQ_setGroupAnonymous)(int32_t ac, int64_t group, int32_t enableanomymous);
CQAPI(int32_t, CQ_setGroupCard)(int32_t ac, int64_t group, int64_t qq, const char *newcard);
CQAPI(int32_t, CQ_setGroupSpecialTitle)(int32_t ac, int64_t group, int64_t qq, const char *newspecialtitle, int64_t duration);

// misc

CQAPI(int32_t, CQ_setFriendAddRequest)(int32_t ac, CQ_RESPONSE_FLAG responseflag, int32_t responseoperation, const char *remark);
CQAPI(int32_t, CQ_setGroupAddRequestV2)(int32_t ac, CQ_RESPONSE_FLAG responseflag, int32_t requesttype, int32_t responseoperation, const char *reason);

// info and utils

CQAPI(const char *, CQ_getGroupMemberInfoV2)(int32_t ac, int64_t group, int64_t qq, int32_t nocache);
CQAPI(const char *, CQ_getStrangerInfo)(int32_t ac, int64_t qq, int32_t nocache);
CQAPI(int64_t, CQ_getLoginQQ)(int32_t ac);
CQAPI(const char *, CQ_getLoginNick)(int32_t ac);
CQAPI(const char *, CQ_getAppDirectory)(int32_t ac);
CQAPI(int32_t, CQ_addLog)(int32_t ac, int32_t priority, const char *category, const char *content);
CQAPI(int32_t, CQ_setFatal)(int32_t ac, const char *errorinfo);
