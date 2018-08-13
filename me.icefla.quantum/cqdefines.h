/**
 * cqdefines.h
 * based on previous work by coxxs and orzfly
 */

#pragma once

typedef long long CQ_QQ;
typedef long long CQ_GROUP;
typedef long long CQ_DISCUSS;
typedef const char *CQ_RESPONSE_FLAG;
typedef const char *CQ_ANONYMOUS;

#define CQAPI(RET, NAME) \
extern "C" __declspec(dllimport) RET __stdcall NAME
#define CQEVT(RET, NAME, SIZE) \
__pragma(comment(linker, "/EXPORT:" #NAME "=_" #NAME "@" #SIZE)) \
extern "C" __declspec(dllexport) RET __stdcall NAME

#define EVENT_IGNORE 0
#define EVENT_BLOCK 1

#define REQUEST_ALLOW 1
#define REQUEST_DENY 2

#define REQUEST_GROUPADD 1
#define REQUEST_GROUPINVITE 2

#define CQLOG_DEBUG 0
#define CQLOG_INFO 10
#define CQLOG_INFOSUCCESS 11
#define CQLOG_INFORECV 12
#define CQLOG_INFOSEND 13
#define CQLOG_WARNING 20
#define CQLOG_ERROR 30
#define CQLOG_FATAL 40
