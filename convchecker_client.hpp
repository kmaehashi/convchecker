
// This file is auto-generated from convchecker.idl
// *** DO NOT EDIT ***

#ifndef CONVCHECKER_CLIENT_HPP_
#define CONVCHECKER_CLIENT_HPP_


#include "convchecker_types.hpp"
#include <pficommon/network/mprpc.h>


namespace jubatus {

namespace client {

class convchecker : public pfi::network::mprpc::rpc_client {
public:
  convchecker(const std::string &host, uint64_t port, double timeout_sec)
    : rpc_client(host, port, timeout_sec) {}

    bool set_config(std::string name, config_data c) {
      return call<bool(std::string, config_data)>("set_config")(name, c);
    }

    config_data get_config(std::string name) {
      return call<config_data(std::string)>("get_config")(name);
    }

    std::string query(std::string name, std::string query) {
      return call<std::string(std::string, std::string)>("query")(name, query);
    }

    bool save(std::string name, std::string id) {
      return call<bool(std::string, std::string)>("save")(name, id);
    }

    bool load(std::string name, std::string id) {
      return call<bool(std::string, std::string)>("load")(name, id);
    }

    std::map<std::string, std::map<std::string, std::string > > get_status(std::string name) {
      return call<std::map<std::string, std::map<std::string, std::string > >(std::string)>("get_status")(name);
    }

private:
};

} // namespace client

} // namespace jubatus



#endif // CONVCHECKER_CLIENT_HPP_
