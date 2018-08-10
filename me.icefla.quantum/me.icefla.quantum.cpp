/**
 * me.icefla.quantum.cpp
 * author: esphas
 * based on previous work by coxxs and orzfly
 */

#include "me.icefla.quantum.h"
#include "app.h"

App *app = nullptr;

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		app = new App;
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		delete app;
		break;
	}
	return TRUE;
}

CQEVENT(const char*, AppInfo, 0)() {
	return app->Info();
}
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	return app->Initialize(AuthCode);
}
CQEVENT(int32_t, __eventStartup, 0)() {
	return app->Startup();
}
CQEVENT(int32_t, __eventExit, 0)() {
	return app->Exit();
}
CQEVENT(int32_t, __eventEnable, 0)() {
	return app->Enable();
}
CQEVENT(int32_t, __eventDisable, 0)() {
	return app->Disable();
}
CQEVENT(int32_t, __eventPrivateMsg, 24)(int32_t subType, int32_t msgId, int64_t fromQQ, const char *msg, int32_t font) {
	return app->OnPrivateMessage(msgId, subType, fromQQ, msg);
}
CQEVENT(int32_t, __eventGroupMsg, 36)(int32_t subType, int32_t msgId, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font) {
	return app->OnGroupMessage(msgId, fromGroup, fromQQ, msg, fromAnonymous);
}
CQEVENT(int32_t, __eventDiscussMsg, 32)(int32_t subType, int32_t msgId, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font) {
	return app->OnDiscussMessage(msgId, fromDiscuss, fromQQ, msg);
}
CQEVENT(int32_t, __eventSystem_GroupAdmin, 24)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t beingOperateQQ) {
	if (subType == 1) {
		return app->OnGroupAdminRemoved(sendTime, fromGroup, beingOperateQQ);
	} else if (subType == 2) {
		return app->OnGroupAdminAdded(sendTime, fromGroup, beingOperateQQ);
	}
	return EVENT_IGNORE; // unreachable
}
CQEVENT(int32_t, __eventSystem_GroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	if (subType == 1) {
		return app->OnGroupMemberLeft(sendTime, fromGroup, beingOperateQQ);
	} else if (subType == 2) {
		return app->OnGroupMemberKicked(sendTime, fromGroup, beingOperateQQ, fromQQ);
	} else if (subType == 3) {
		return app->OnGroupKicked(sendTime, fromGroup, fromQQ);
	}
	return EVENT_IGNORE; // unreachable
}
CQEVENT(int32_t, __eventSystem_GroupMemberIncrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	return app->OnGroupMemberJoined(sendTime, fromGroup, beingOperateQQ, fromQQ);
}
CQEVENT(int32_t, __eventFriend_Add, 16)(int32_t subType, int32_t sendTime, int64_t fromQQ) {
	return app->OnFriendAdded(sendTime, fromQQ);
}
CQEVENT(int32_t, __eventRequest_AddFriend, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, CQ_RESPONSE_FLAG responseFlag) {
	return app->OnFriendRequest(sendTime, fromQQ, msg, responseFlag);
}
CQEVENT(int32_t, __eventRequest_AddGroup, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, CQ_RESPONSE_FLAG responseFlag) {
	if (subType == 1) {
		return app->OnGroupRequest(sendTime, fromQQ, fromGroup, msg, responseFlag);
	} else if (subType == 2) {
		return app->OnGroupInvitation(sendTime, fromQQ, fromGroup, msg, responseFlag);
	}
	return EVENT_IGNORE; // unreachable
}
