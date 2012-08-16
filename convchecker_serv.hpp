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

  std::string query(const datum& query); //update random

  std::string bulk_query(const std::vector<datum >& query); //update random

  bool save(const std::string& id); //update broadcast

  bool load(const std::string& id); //update broadcast

  std::map<std::string,std::map<std::string,std::string > > get_status() const; //analysis broadcast
  void after_load();

private:
  void check_set_config()const;
  config_data config_;
  pfi::lang::shared_ptr<fv_converter::datum_to_fv_converter> converter_;
};
}} // namespace jubatus::server
