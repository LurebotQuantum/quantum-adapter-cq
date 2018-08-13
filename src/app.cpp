/**
 * app.cpp
 * author: esphas
 */

#include "app.h"
#include "cqapi.h"

namespace adapter {

int App::Initialize(int authcode) {
	this->authcode = authcode;
	return 0;
}

int App::Startup() {
	return 0;
}

int App::Exit() {
	return 0;
}

int App::Enable() {
	this->enabled = true;
	return 0;
}

int App::Disable() {
	this->enabled = false;
	return 0;
}

// type: indicates the source of the message
// 11/friend; 1/online status; 2/group; 3/discuss
int App::OnPrivateMessage(int msgId, int type, CQ_QQ qq, std::string msg) {
	this->CQSendPrivateMessage(qq, msg); // DEBUG: Echo bot
	Message message(msgId, msg);
	message.SetupPrivate(qq, type);
	this->ProcessMessage(message);
	return EVENT_IGNORE;
}

int App::OnGroupMessage(int msgId, CQ_GROUP group, CQ_QQ qq, std::string msg, CQ_ANONYMOUS anonymous) {
	Message message(msgId, msg);
	message.SetupGroup(qq, group, anonymous);
	this->ProcessMessage(message);
	return EVENT_IGNORE;
}

int App::OnDiscussMessage(int msgId, CQ_DISCUSS discuss, CQ_QQ qq, std::string msg) {
	Message message(msgId, msg);
	message.SetupDiscuss(qq, discuss);
	this->ProcessMessage(message);
	return EVENT_IGNORE;
}

int App::OnGroupAdminRemoved(int sendTime, CQ_GROUP group, CQ_QQ qq) {
	return EVENT_IGNORE;
}

int App::OnGroupAdminAdded(int sendTime, CQ_GROUP group, CQ_QQ qq) {
	return EVENT_IGNORE;
}

int App::OnGroupMemberLeft(int sendTime, CQ_GROUP group, CQ_QQ qq) {
	return EVENT_IGNORE;
}

int App::OnGroupMemberKicked(int sendTime, CQ_GROUP group, CQ_QQ qq, int64_t moderator) {
	return EVENT_IGNORE;
}

int App::OnGroupKicked(int sendTime, CQ_GROUP group, int64_t moderator) {
	return EVENT_IGNORE;
}

int App::OnGroupMemberJoined(int sendTime, CQ_GROUP group, CQ_QQ qq, int64_t moderator) {
	return EVENT_IGNORE;
}

int App::OnFriendAdded(int sendTime, CQ_QQ qq) {
	return EVENT_IGNORE;
}

int App::OnFriendRequest(int sendTime, CQ_QQ qq, std::string message, CQ_RESPONSE_FLAG flag) {
	return EVENT_IGNORE;
}

int App::OnGroupRequest(int sendTime, CQ_QQ qq, CQ_GROUP group, std::string message, CQ_RESPONSE_FLAG flag) {
	return EVENT_IGNORE;
}

int App::OnGroupInvitation(int sendTime, CQ_QQ qq, CQ_GROUP group, std::string message, CQ_RESPONSE_FLAG flag) {
	return EVENT_IGNORE;
}

int App::CQSendPrivateMessage(CQ_QQ qq, std::string message) {
	return CQ_sendPrivateMsg(this->authcode, qq, message.c_str());
}

int App::CQSendGroupMessage(CQ_GROUP group, std::string message) {
	return CQ_sendGroupMsg(this->authcode, group, message.c_str());
}

int App::CQSendDiscussMessage(CQ_DISCUSS discuss, std::string message) {
	return CQ_sendDiscussMsg(this->authcode, discuss, message.c_str());
}

int App::CQDeleteMessage(int msgId) {
	return CQ_deleteMsg(this->authcode, msgId);
}

int App::CQKickGroupMember(CQ_GROUP group, CQ_QQ qq, bool rejectAddRequest) {
	return CQ_setGroupKick(this->authcode, group, qq, rejectAddRequest);
}

int App::CQSetGroupAdmin(CQ_GROUP group, CQ_QQ qq, bool set) {
	return CQ_setGroupAdmin(this->authcode, group, qq, set);
}

int App::CQBanWholeGroup(CQ_GROUP group, bool ban) {
	return CQ_setGroupWholeBan(this->authcode, group, ban);
}

int App::CQBanGroupMember(CQ_GROUP group, CQ_QQ qq, int duration) {
	return CQ_setGroupBan(this->authcode, group, qq, duration);
}

int App::CQBanGroupMember(CQ_GROUP group, CQ_ANONYMOUS anonymous, int duration) {
	return CQ_setGroupAnonymousBan(this->authcode, group, anonymous, duration);
}

int App::CQSetGroupAnonymous(CQ_GROUP group, bool enable) {
	return CQ_setGroupAnonymous(this->authcode, group, true);
}

int App::CQSetGroupMemberCard(CQ_GROUP group, CQ_QQ qq, std::string card) {
	return CQ_setGroupCard(this->authcode, group, qq, card.c_str());
}

int App::CQSetGroupMemberTitle(CQ_GROUP group, CQ_QQ qq, std::string title, int duration) {
	return CQ_setGroupSpecialTitle(this->authcode, group, qq, title.c_str(), duration);
}

int App::CQAllowFriendRequest(CQ_RESPONSE_FLAG flag, std::string remark) {
	return CQ_setFriendAddRequest(this->authcode, flag, REQUEST_ALLOW, remark.c_str());
}

int App::CQDenyFriendRequest(CQ_RESPONSE_FLAG flag) {
	return CQ_setFriendAddRequest(this->authcode, flag, REQUEST_DENY, "");
}

int App::CQAllowGroupRequest(CQ_RESPONSE_FLAG flag) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPADD, REQUEST_ALLOW, "");
}

int App::CQDenyGroupRequest(CQ_RESPONSE_FLAG flag, std::string reason) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPADD, REQUEST_DENY, reason.c_str());
}

int App::CQAllowGroupInvitation(CQ_RESPONSE_FLAG flag) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPINVITE, REQUEST_ALLOW, "");
}

int App::CQDenyGroupInvitation(CQ_RESPONSE_FLAG flag) {
	return CQ_setGroupAddRequestV2(this->authcode, flag, REQUEST_GROUPINVITE, REQUEST_DENY, "");
}

std::string App::CQGetGroupMemberInfo(CQ_GROUP group, CQ_QQ qq, bool noCache) {
	return CQ_getGroupMemberInfoV2(this->authcode, group, qq, noCache);
}

std::string App::CQGetStrangerInfo(CQ_QQ qq, bool noCache) {
	return CQ_getStrangerInfo(this->authcode, qq, noCache);
}

int64_t App::CQGetLoginQQ() {
	return CQ_getLoginQQ(this->authcode);
}

std::string App::CQGetLoginNick() {
	return CQ_getLoginNick(this->authcode);
}

std::string App::CQGetAppDirectory() {
	return CQ_getAppDirectory(this->authcode);
}

int App::CQLog(int level, std::string category, std::string content) {
	return CQ_addLog(this->authcode, level, category.c_str(), content.c_str());
}

int App::CQSetFatal(std::string message) {
	return CQ_setFatal(this->authcode, message.c_str());
}

void App::ProcessMessage(Message message) {
	// TODO
}

}
