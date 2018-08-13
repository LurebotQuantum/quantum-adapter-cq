/**
 * message.cpp
 * author: esphas
 */

#include <sstream>

#include "message.h"

namespace adapter {

void Message::SetupPrivate(CQ_QQ qq, int type) {
  auto context = this->message.mutable_context();
  auto aid = this->QQ2AID(qq);
  std::stringstream ss; ss << "type:" << type << ";";
  auto ext = ss.str();
  context->set_aid(aid);
  context->set_cid(aid);
  context->set_type(quantum::Context::PRIVATE);
  context->set_ext(ext);
}

void Message::SetupGroup(CQ_QQ qq, CQ_GROUP group, CQ_ANONYMOUS anonymous) {
  auto context = this->message.mutable_context();
  auto aid = this->QQ2AID(qq);
  auto cid = this->Group2CID(group);
  context->set_aid(aid);
  context->set_cid(cid);
  context->set_type(quantum::Context::GROUP);
}

void Message::SetupDiscuss(CQ_QQ qq, CQ_DISCUSS discuss) {
  auto context = this->message.mutable_context();
  auto aid = this->QQ2AID(qq);
  auto cid = this->Discuss2CID(discuss);
  context->set_aid(aid);
  context->set_cid(cid);
  context->set_type(quantum::Context::GROUP);
}

std::string Message::QQ2AID(CQ_QQ qq) {
  return std::to_string(qq);
}

CQ_QQ AID2QQ(std::string &aid) {
  return std::stoll(aid);
}

std::string Message::Group2CID(CQ_GROUP group) {
  return "GRP" + std::to_string(group);
}

CQ_GROUP CID2Group(std::string &cid) {
  return std::stoll(cid.substr(3));
}

std::string Message::Discuss2CID(CQ_DISCUSS discuss) {
  return "DIS" + std::to_string(discuss);
}

CQ_DISCUSS Message::CID2Discuss(std::string &cid) {
  return std::stoll(cid.substr(3));
}

bool Message::IsCIDGroup(std::string &cid) {
  return cid.substr(0, 3) == "GRP";
}

}
