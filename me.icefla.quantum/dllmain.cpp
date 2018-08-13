/**
 * dllmain.cpp
 * author: esphas
 */

#include <cstdint>

#include "app.h"

App *app = nullptr;

CQEVT(const char*, AppInfo, 0)() {
		return "9" "," "me.icefla.quantum";
}
CQEVT(int32_t, Initialize, 4)(int32_t AuthCode) {
	app = new App;
	return app->Initialize(AuthCode);
}

CQEVT(int32_t, CQStartup, 0)() {
	return app->Startup();
}
CQEVT(int32_t, CQExit, 0)() {
	auto ret = app->Exit();
	delete app;
	return ret;
}
CQEVT(int32_t, CQEnable, 0)() {
	return app->Enable();
}
CQEVT(int32_t, CQDisable, 0)() {
	return app->Disable();
}

CQEVT(int32_t, CQPrivateMessage, 24)(int32_t subType, int32_t msgId, int64_t fromQQ, const char *msg, int32_t font) {
	return app->OnPrivateMessage(msgId, subType, fromQQ, msg);
}
CQEVT(int32_t, CQGroupMessage, 36)(int32_t subType, int32_t msgId, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font) {
	return app->OnGroupMessage(msgId, fromGroup, fromQQ, msg, fromAnonymous);
}
CQEVT(int32_t, CQDiscussMessage, 32)(int32_t subType, int32_t msgId, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font) {
	return app->OnDiscussMessage(msgId, fromDiscuss, fromQQ, msg);
}

CQEVT(int32_t, CQGroupAdminChange, 24)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t beingOperateQQ) {
	if (subType == 1) {
		return app->OnGroupAdminRemoved(sendTime, fromGroup, beingOperateQQ);
	} else if (subType == 2) {
		return app->OnGroupAdminAdded(sendTime, fromGroup, beingOperateQQ);
	}
	return EVENT_IGNORE; // unreachable
}
CQEVT(int32_t, CQGroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	if (subType == 1) {
		return app->OnGroupMemberLeft(sendTime, fromGroup, beingOperateQQ);
	} else if (subType == 2) {
		return app->OnGroupMemberKicked(sendTime, fromGroup, beingOperateQQ, fromQQ);
	} else if (subType == 3) {
		return app->OnGroupKicked(sendTime, fromGroup, fromQQ);
	}
	return EVENT_IGNORE; // unreachable
}
CQEVT(int32_t, CQGroupMemberIncrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	return app->OnGroupMemberJoined(sendTime, fromGroup, beingOperateQQ, fromQQ);
}

CQEVT(int32_t, CQFriendAdd, 16)(int32_t subType, int32_t sendTime, int64_t fromQQ) {
	return app->OnFriendAdded(sendTime, fromQQ);
}
CQEVT(int32_t, CQFriendAddRequest, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, CQ_RESPONSE_FLAG responseFlag) {
	return app->OnFriendRequest(sendTime, fromQQ, msg, responseFlag);
}
CQEVT(int32_t, CQGroupAddRequest, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, CQ_RESPONSE_FLAG responseFlag) {
	if (subType == 1) {
		return app->OnGroupRequest(sendTime, fromQQ, fromGroup, msg, responseFlag);
	} else if (subType == 2) {
		return app->OnGroupInvitation(sendTime, fromQQ, fromGroup, msg, responseFlag);
	}
	return EVENT_IGNORE; // unreachable
}
