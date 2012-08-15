// this is automatically generated template header please implement and edit.
#pragma once
#include <jubatus/framework.hpp>
#include "convchecker_types.hpp"
using namespace jubatus::framework;

namespace jubatus { namespace server { // do not change
class convchecker_serv : public jubatus_serv // do not change
{
public:
  convchecker_serv(const server_argv& a); // do not change
  virtual ~convchecker_serv(); // do not change

  bool set_config(const config_data& c); //update broadcast

  config_data get_config() const; //analysis random

  std::string query(const std::string& query); //update random

  bool save(const std::string& id); //update broadcast

  bool load(const std::string& id); //update broadcast

  std::map<std::string,std::map<std::string,std::string > > get_status() const; //analysis broadcast
  void after_load();

private:
  // add user data here like: pfi::lang::shared_ptr<some_type> some_;
};
}} // namespace jubatus::server
