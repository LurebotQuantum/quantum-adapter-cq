/**
 * cqdefines.h
 * based on previous work by coxxs and orzfly
 */

#pragma once

#include <cstdint>

typedef int32_t CQ_BOOL;
typedef const char *CQ_RESPONSE_FLAG;
typedef const char *CQ_ANONYMOUS;

#define CQAPIVER 9
#define CQAPIVERTEXT "9"

#define CQAPI(ReturnType) \
extern "C" __declspec(dllimport) ReturnType __stdcall

#define CQEVENT(ReturnType, Name, Size) \
__pragma(comment(linker, "/EXPORT:" #Name "=_" #Name "@" #Size)) \
extern "C" __declspec(dllexport) ReturnType __stdcall Name

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
