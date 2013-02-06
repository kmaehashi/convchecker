
// This file is auto-generated from convchecker.idl
// *** DO NOT EDIT ***

#ifndef CONVCHECKER_CLIENT_HPP_
#define CONVCHECKER_CLIENT_HPP_


#include "convchecker_types.hpp"
#include <jubatus/msgpack/rpc/client.h>


namespace jubatus {

namespace client {

class convchecker {
public:
  convchecker(const std::string &host, uint64_t port, double timeout_sec)
    : c_(host, port) {
    c_.set_timeout( timeout_sec );
  }

    std::string get_config(std::string name) {
      return c_.call("get_config", name).get<std::string >();
    }

    std::string query(std::string name, datum query) {
      return c_.call("query", name, query).get<std::string >();
    }

    std::string bulk_query(std::string name, std::vector<datum > query) {
      return c_.call("bulk_query", name, query).get<std::string >();
    }

    bool save(std::string name, std::string id) {
      return c_.call("save", name, id).get<bool >();
    }

    bool load(std::string name, std::string id) {
      return c_.call("load", name, id).get<bool >();
    }

    std::map<std::string, std::map<std::string, std::string > > get_status(std::string name) {
      return c_.call("get_status", name).get<std::map<std::string, std::map<std::string, std::string > > >();
    }

private:
  msgpack::rpc::client c_;
};

} // namespace client

} // namespace jubatus



#endif // CONVCHECKER_CLIENT_HPP_
