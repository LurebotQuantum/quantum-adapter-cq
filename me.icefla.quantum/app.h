/**
 * app.h
 * author: esphas
 */

#pragma once

#include <string>

#include "cqdefines.h"

#define APPID "me.icefla.quantum"

class App {

	int32_t authcode;

public:

	bool enabled = false;

	constexpr const char *Info() {
		return CQAPIVERTEXT "," APPID;
	}

	int32_t Initialize(int32_t authcode);

	int32_t Startup();
	int32_t Exit();
	int32_t Enable();
	int32_t Disable();

	int32_t OnPrivateMessage(int32_t msgId, int32_t type, int64_t qq, std::string msg);
	int32_t OnGroupMessage  (int32_t msgId, int64_t group, int64_t qq, std::string msg, CQ_ANONYMOUS anonymous);
	int32_t OnDiscussMessage(int32_t msgId, int64_t discuss, int64_t qq, std::string msg);
	
	int32_t OnGroupAdminRemoved(int32_t sendTime, int64_t group, int64_t qq);
	int32_t OnGroupAdminAdded  (int32_t sendTime, int64_t group, int64_t qq);
	int32_t OnGroupMemberLeft  (int32_t sendTime, int64_t group, int64_t qq);
	int32_t OnGroupMemberKicked(int32_t sendTime, int64_t group, int64_t qq, int64_t moderator);
	int32_t OnGroupKicked      (int32_t sendTime, int64_t group, int64_t moderator);
	int32_t OnGroupMemberJoined(int32_t sendTime, int64_t group, int64_t qq, int64_t moderator);

	int32_t OnFriendAdded(int32_t sendTime, int64_t qq);
	int32_t OnFriendRequest(int32_t sendTime, int64_t qq, std::string message, CQ_RESPONSE_FLAG flag);
	int32_t OnGroupRequest(int32_t sendTime, int64_t qq, int64_t group, std::string message, CQ_RESPONSE_FLAG flag);
	int32_t OnGroupInvitation(int32_t sendTime, int64_t qq, int64_t group, std::string message, CQ_RESPONSE_FLAG flag);

	int32_t SendPrivateMessage(int64_t qq, std::string message);
	int32_t SendGroupMessage(int64_t group, std::string message);
	int32_t SendDiscussMessage(int64_t discuss, std::string message);
	int32_t DeleteMessage(int32_t msgId);

	int32_t SendLike(int64_t qq);

	int32_t KickGroupMember(int64_t group, int64_t qq, bool rejectAddRequest = false);
	int32_t AddGroupAdmin(int64_t group, int64_t qq);
	int32_t RemoveGroupAdmin(int64_t group, int64_t qq);
	int32_t BanWholeGroup(int64_t group, bool ban);
	int32_t BanGroupMember(int64_t group, int64_t qq, int32_t duration);
	int32_t BanGroupMember(int64_t group, CQ_ANONYMOUS anonymous, int32_t duration);
	int32_t EnableGroupAnonymous(int64_t group);
	int32_t DisableGroupAnonymous(int64_t group);
	int32_t SetGroupMemberCard(int64_t group, int64_t qq, std::string card);
	int32_t SetGroupMemberTitle(int64_t group, int64_t qq, std::string title, int32_t duration);
	int32_t LeaveGroup(int64_t group, bool dismiss = false);
	int32_t LeaveDiscuss(int64_t discuss);

	int32_t AllowFriendRequest(CQ_RESPONSE_FLAG flag, std::string remark = "");
	int32_t DenyFriendRequest(CQ_RESPONSE_FLAG flag);
	int32_t AllowGroupRequest(CQ_RESPONSE_FLAG flag);
	int32_t DenyGroupRequest(CQ_RESPONSE_FLAG flag, std::string message = "");
	int32_t AllowGroupInvitation(CQ_RESPONSE_FLAG flag);
	int32_t DenyGroupInvitation(CQ_RESPONSE_FLAG flag);

	std::string GetGroupMemberInfo(int64_t group, int64_t qq, bool noCache);
	std::string GetStrangerInfo(int64_t qq, bool noCache);

	std::string GetCookies();
	int32_t GetCsrfToken();

	int64_t GetLoginQQ();
	std::string GetLoginNick();
	std::string GetAppDirectory();

	int32_t Log(int32_t level, std::string category, std::string content);
	int32_t SetFatal(std::string message);
};
