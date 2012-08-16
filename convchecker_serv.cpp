// this is automatically generated template header please implement and edit.

#include <sstream>
#include "convchecker_serv.hpp"
#include <jubatus/common/shared_ptr.hpp>
#include <jubatus/fv_converter/datum.hpp>
#include <jubatus/fv_converter/datum_to_fv_converter.hpp>

using namespace jubatus::framework;
using namespace pfi::lang;

namespace jubatus { namespace server { // do not change
convchecker_serv::convchecker_serv(const server_argv& a)
  :framework::jubatus_serv(a)
{}

convchecker_serv::~convchecker_serv()
{}


//update, broadcast
bool convchecker_serv::set_config(const config_data& c)
{
  shared_ptr<jubatus::fv_converter::datum_to_fv_converter> converter = framework::make_fv_converter(c.config);

  config_ = c;
  converter_ = converter;

  return true;
}

//analysis, random
config_data convchecker_serv::get_config() const
{
  check_set_config();
  return config_;
}

//update, random
std::string convchecker_serv::query(const jubatus::datum& query)
{
  jubatus::sfv_t fv;
  fv_converter::datum d;

  check_set_config();
  convert<jubatus::datum, fv_converter::datum>(query, d);
  converter_->convert(d, fv);

  std::stringstream ret;
  for (size_t i = 0; i < fv.size(); ++i) {
    ret << fv[i].first << ": " << fv[i].second << std::endl;
  }

  return ret.str();
}

//update, random
std::string convchecker_serv::bulk_query(const std::vector<datum >& query)
{
  jubatus::sfv_t fv;
  fv_converter::datum d;
  std::stringstream ret;

  check_set_config();
  for (size_t i = 0; i < query.size(); ++i) {
  
    convert<jubatus::datum, fv_converter::datum>(query[i], d);
    converter_->convert(d, fv);

    for (size_t i = 0; i < fv.size(); ++i) {
      ret << fv[i].first << ": " << fv[i].second << std::endl;
    }
  }

  return ret.str();
}

//update, broadcast
bool convchecker_serv::save(const std::string& id)
{
  return false;
}

//update, broadcast
bool convchecker_serv::load(const std::string& id)
{
  return false;
}

//analysis, broadcast
std::map<std::string,std::map<std::string,std::string > > convchecker_serv::get_status() const
{
  std::map<std::string, std::map<std::string,std::string> > ret = jubatus_serv::get_status();

  return ret;
}

void convchecker_serv::check_set_config()const
{
  if (!converter_){
    throw JUBATUS_EXCEPTION(config_not_set());
  }
}

void convchecker_serv::after_load(){}
}} // namespace jubatus::serve
