// this is automatically generated template header please implement and edit.

#include "convchecker_serv.hpp"

using namespace jubatus::framework;

namespace jubatus { namespace server { // do not change
convchecker_serv::convchecker_serv(const server_argv& a)
  :framework::jubatus_serv(a)
{
  //somemixable* mi = new somemixable;
  //somemixable_.set_model(mi);
  //register_mixable(framework::mixable_cast(mi));
}

convchecker_serv::~convchecker_serv()
{}


//update, broadcast
bool convchecker_serv::set_config(const config_data& c)
{}

//analysis, random
config_data convchecker_serv::get_config() const
{}

//update, random
std::string convchecker_serv::query(const std::string& query)
{}

//update, broadcast
bool convchecker_serv::save(const std::string& id)
{}

//update, broadcast
bool convchecker_serv::load(const std::string& id)
{}

//analysis, broadcast
std::map<std::string,std::map<std::string,std::string > > convchecker_serv::get_status() const
{}

void convchecker_serv::after_load(){}
}} // namespace jubatus::server
