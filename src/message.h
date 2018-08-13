/**
 * message.h
 * author: esphas
 */

#pragma once

#include <string>

#include "message.pb.h"
#include "cqdefines.h"

namespace adapter {

class Message {

  quantum::Message message;

  int msgId;

public:

  Message(int msgId, const std::string &text) : msgId(msgId) {
    this->message.set_text(text);
  }

  void SetupPrivate(CQ_QQ qq, int type);
  void SetupGroup(CQ_QQ qq, CQ_GROUP group, CQ_ANONYMOUS anonymous);
  void SetupDiscuss(CQ_QQ qq, CQ_DISCUSS discuss);

private:

  std::string QQ2AID(CQ_QQ qq);
  CQ_QQ AID2QQ(std::string &aid);

  std::string Group2CID(CQ_GROUP group);
  CQ_GROUP CID2Group(std::string &cid);
  std::string Discuss2CID(CQ_DISCUSS discuss);
  CQ_DISCUSS CID2Discuss(std::string &cid);
  bool IsCIDGroup(std::string &cid);

};

}
