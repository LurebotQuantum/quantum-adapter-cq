/**
 * app.cpp
 * author: esphas
 */

#include "app.h"

#include "cqapi.h"

int32_t App::Initialize(int32_t authcode) {
	this->authcode = authcode;
	return 0;
}

int32_t App::Startup() {
	return 0;
}

int32_t App::Exit() {
	return 0;
}

int32_t App::Enable() {
	this->enabled = true;
	return 0;
}

int32_t App::Disable() {
	this->enabled = false;
	return 0;
}

// type: indicates the source of the message
// 11/friend; 1/online status; 2/group; 3/discuss
int32_t App::OnPrivateMessage(int32_t msgId, int32_t type, int64_t qq, std::string message) {
	this->SendPrivateMessage(qq, message); // Echo bot
	return EVENT_IGNORE;
}

int32_t App::OnGroupMessage(int32_t msgId, int64_t group, int64_t qq, std::string msg, CQ_ANONYMOUS anonymous) {
	return EVENT_IGNORE;
}

int32_t App::OnDiscussMessage(int32_t msgId, int64_t discuss, int64_t qq, std::string msg) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupAdminRemoved(int32_t sendTime, int64_t group, int64_t qq) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupAdminAdded(int32_t sendTime, int64_t group, int64_t qq) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupMemberLeft(int32_t sendTime, int64_t group, int64_t qq) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupMemberKicked(int32_t sendTime, int64_t group, int64_t qq, int64_t moderator) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupKicked(int32_t sendTime, int64_t group, int64_t moderator) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupMemberJoined(int32_t sendTime, int64_t group, int64_t qq, int64_t moderator) {
	return EVENT_IGNORE;
}

int32_t App::OnFriendAdded(int32_t sendTime, int64_t qq) {
	return EVENT_IGNORE;
}

int32_t App::OnFriendRequest(int32_t sendTime, int64_t qq, std::string message, CQ_RESPONSE_FLAG flag) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupRequest(int32_t sendTime, int64_t qq, int64_t group, std::string message, CQ_RESPONSE_FLAG flag) {
	return EVENT_IGNORE;
}

int32_t App::OnGroupInvitation(int32_t sendTime, int64_t qq, int64_t group, std::string message, CQ_RESPONSE_FLAG flag) {
	return EVENT_IGNORE;
}

int32_t App::SendPrivateMessage(int64_t qq, std::string message) {
	return CQ_sendPrivateMsg(this->authcode, qq, message.c_str());
}

int32_t App::SendGroupMessage(int64_t group, std::string message) {
	return CQ_sendGroupMsg(this->authcode, group, message.c_str());
}

int32_t App::SendDiscussMessage(int64_t discuss, std::string message) {
	return CQ_sendDiscussMsg(this->authcode, discuss, message.c_str());
}

int32_t App::DeleteMessage(int32_t msgId) {
	return CQ_deleteMsg(this->authcode, msgId);
}

int32_t App::SendLike(int64_t qq) {
	return CQ_sendLike(this->authcode, qq);
}

int32_t App::KickGroupMember(int64_t group, int64_t qq, bool rejectAddRequest) {
	return CQ_setGroupKick(this->authcode, group, qq, rejectAddRequest);
}

int32_t App::AddGroupAdmin(int64_t group, int64_t qq) {
	return CQ_setGroupAdmin(this->authcode, group, qq, true);
}

int32_t App::RemoveGroupAdmin(int64_t group, int64_t qq) {
	return CQ_setGroupAdmin(this->authcode, group, qq, false);
}

int32_t App::BanWholeGroup(int64_t group, bool ban) {
	return CQ_setGroupWholeBan(this->authcode, group, ban);
}

int32_t App::BanGroupMember(int64_t group, int64_t qq, int32_t duration) {
	return CQ_setGroupBan(this->authcode, group, qq, duration);
}

int32_t App::BanGroupMember(int64_t group, CQ_ANONYMOUS anonymous, int32_t duration) {
	return CQ_setGroupAnonymousBan(this->authcode, group, anonymous, duration);
}

int32_t App::EnableGroupAnonymous(int64_t group) {
	return CQ_setGroupAnonymous(this->authcode, group, true);
}

int32_t App::DisableGroupAnonymous(int64_t group) {
	return CQ_setGroupAnonymous(this->authcode, group, false);
}

int32_t App::SetGroupMemberCard(int64_t group, int64_t qq, std::string card) {
	return CQ_setGroupCard(this->authcode, group, qq, card.c_str());
}

// title = "": clear title
// duration = -1: forever
int32_t App::SetGroupMemberTitle(int64_t group, int64_t qq, std::string title, int32_t duration) {
	return CQ_setGroupSpecialTitle(this->authcode, group, qq, title.c_str(), duration);
}

int32_t App::LeaveGroup(int64_t group, bool dismiss) {
	return CQ_setGroupLeave(this->authcode, group, dismiss);
}

int32_t App::LeaveDiscuss(int64_t discuss) {
	return CQ_setDiscussLeave(this->authcode, discuss);
}

int32_t App::AllowFriendRequest(CQ_RESPONSE_FLAG flag, std::string remark) {
	return CQ_setFriendAddRequest(this->authcode, flag, REQUEST_ALLOW, remark.c_str());
}

int32_t App::DenyFriendRequest(CQ_RESPONSE_FLAG flag) {
	return CQ_setFriendAddRequest(this->authcode, flag, REQUEST_DENY, "");
}

int32_t App::AllowGroupRequest(CQ_RESPONSE_FLAG flag) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPADD, REQUEST_ALLOW, "");
}

int32_t App::DenyGroupRequest(CQ_RESPONSE_FLAG flag, std::string reason) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPADD, REQUEST_DENY, reason.c_str());
}

int32_t App::AllowGroupInvitation(CQ_RESPONSE_FLAG flag) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPINVITE, REQUEST_ALLOW, "");
}

int32_t App::DenyGroupInvitation(CQ_RESPONSE_FLAG flag) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPINVITE, REQUEST_DENY, "");
}

std::string App::GetGroupMemberInfo(int64_t group, int64_t qq, bool noCache) {
	return CQ_getGroupMemberInfoV2(this->authcode, group, qq, noCache);
}

std::string App::GetStrangerInfo(int64_t qq, bool noCache) {
	return CQ_getStrangerInfo(this->authcode, qq, noCache);
}

std::string App::GetCookies() {
	return CQ_getCookies(this->authcode);
}

int32_t App::GetCsrfToken() {
	return CQ_getCsrfToken(this->authcode);
}

int64_t App::GetLoginQQ() {
	return CQ_getLoginQQ(this->authcode);
}

std::string App::GetLoginNick() {
	return CQ_getLoginNick(this->authcode);
}

std::string App::GetAppDirectory() {
	return CQ_getAppDirectory(this->authcode);
}

int32_t App::Log(int32_t level, std::string category, std::string content) {
	return CQ_addLog(this->authcode, level, category.c_str(), content.c_str());
}

int32_t App::SetFatal(std::string message) {
	return CQ_setFatal(this->authcode, message.c_str());
}
