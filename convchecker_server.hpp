
// This file is auto-generated from convchecker.idl
// *** DO NOT EDIT ***

#ifndef CONVCHECKER_SERVER_HPP_
#define CONVCHECKER_SERVER_HPP_


#include "convchecker_types.hpp"
#include <pficommon/network/mprpc.h>
#include <pficommon/lang/bind.h>


namespace jubatus {

namespace server {

template <class Impl>
class convchecker : public pfi::network::mprpc::rpc_server {
public:
  convchecker(double timeout_sec): rpc_server(timeout_sec) {

    rpc_server::add<bool(std::string, config_data) >("set_config", pfi::lang::bind(&Impl::set_config, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<config_data(std::string) >("get_config", pfi::lang::bind(&Impl::get_config, static_cast<Impl*>(this), pfi::lang::_1));
    rpc_server::add<std::string(std::string, datum) >("query", pfi::lang::bind(&Impl::query, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<std::string(std::string, std::vector<datum >) >("bulk_query", pfi::lang::bind(&Impl::bulk_query, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string) >("save", pfi::lang::bind(&Impl::save, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string) >("load", pfi::lang::bind(&Impl::load, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string > >(std::string) >("get_status", pfi::lang::bind(&Impl::get_status, static_cast<Impl*>(this), pfi::lang::_1));
  }
};

} // namespace server

} // namespace jubatus



#endif // CONVCHECKER_SERVER_HPP_
