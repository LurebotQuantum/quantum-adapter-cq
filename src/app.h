/**
 * app.h
 * author: esphas
 */

#pragma once

#include <string>

#include "cqupdate.h"
#include "cqdefines.h"

namespace adapter {

class App {

	int authcode;
	bool enabled = false;

public:

	// CQ Events

	int Initialize(int authcode);

	int Startup();
	int Exit();
	int Enable();
	int Disable();

	int OnPrivateMessage(int msgId, CQ_QQ qq, std::string msg);
	int OnGroupMessage  (int msgId, CQ_GROUP group, CQ_QQ qq, std::string msg, CQ_ANONYMOUS anonymous);
	int OnDiscussMessage(int msgId, CQ_DISCUSS discuss, CQ_QQ qq, std::string msg);
	
	int OnGroupAdminRemoved(int sendTime, CQ_GROUP group, CQ_QQ qq);
	int OnGroupAdminAdded  (int sendTime, CQ_GROUP group, CQ_QQ qq);
	int OnGroupMemberLeft  (int sendTime, CQ_GROUP group, CQ_QQ qq);
	int OnGroupMemberKicked(int sendTime, CQ_GROUP group, CQ_QQ qq, CQ_QQ moderator);
	int OnGroupKicked      (int sendTime, CQ_GROUP group, CQ_QQ moderator);
	int OnGroupMemberJoined(int sendTime, CQ_GROUP group, CQ_QQ qq, CQ_QQ moderator);

	int OnFriendAdded    (int sendTime, CQ_QQ qq);
	int OnFriendRequest  (int sendTime, CQ_QQ qq, std::string message, CQ_RESPONSE_FLAG flag);
	int OnGroupRequest   (int sendTime, CQ_QQ qq, CQ_GROUP group, std::string message, CQ_RESPONSE_FLAG flag);
	int OnGroupInvitation(int sendTime, CQ_QQ qq, CQ_GROUP group, std::string message, CQ_RESPONSE_FLAG flag);

	// CQ APIs

	int CQSendPrivateMessage(CQ_QQ qq, std::string message);
	int CQSendGroupMessage  (CQ_GROUP group, std::string message);
	int CQSendDiscussMessage(CQ_DISCUSS discuss, std::string message);

	int CQDeleteMessage(int msgId);

	int CQKickGroupMember(CQ_GROUP group, CQ_QQ qq, bool rejectAddRequest = false);
	int CQSetGroupAdmin  (CQ_GROUP group, CQ_QQ qq, bool set = true);

	int CQBanWholeGroup (CQ_GROUP group, bool ban = true);
	int CQBanGroupMember(CQ_GROUP group, CQ_QQ qq, int duration);
	int CQBanGroupMember(CQ_GROUP group, CQ_ANONYMOUS anonymous, int duration);

	int CQSetGroupAnonymous(CQ_GROUP group, bool enabled = true);

	int CQSetGroupMemberCard (CQ_GROUP group, CQ_QQ qq, std::string card);
	int CQSetGroupMemberTitle(CQ_GROUP group, CQ_QQ qq, std::string title = "", int duration = -1);

	int CQAllowFriendRequest  (CQ_RESPONSE_FLAG flag, std::string remark = "");
	int CQDenyFriendRequest   (CQ_RESPONSE_FLAG flag);
	int CQAllowGroupRequest   (CQ_RESPONSE_FLAG flag);
	int CQDenyGroupRequest    (CQ_RESPONSE_FLAG flag, std::string message = "");
	int CQAllowGroupInvitation(CQ_RESPONSE_FLAG flag);
	int CQDenyGroupInvitation (CQ_RESPONSE_FLAG flag);

	std::string CQGetGroupMemberInfo(CQ_GROUP group, CQ_QQ qq, bool noCache = false);
	std::string CQGetStrangerInfo   (CQ_QQ qq, bool noCache = false);

	CQ_QQ CQGetLoginQQ();
	std::string CQGetLoginNick();
	std::string CQGetAppDirectory();

	int CQLog(int level, std::string category, std::string content);
	int CQSetFatal(std::string message);

	//



};

} // namespace adapter
