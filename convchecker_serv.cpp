// this is automatically generated template header please implement and edit.

#include "convchecker_serv.hpp"

#include <sstream>

#include <jubatus/common/shared_ptr.hpp>
#include <jubatus/fv_converter/datum.hpp>
#include <jubatus/fv_converter/converter_config.hpp>
#include <jubatus/fv_converter/datum_to_fv_converter.hpp>
#include <jubatus/framework/mixer/mixer_factory.hpp>
#include <pficommon/text/json.h>

using namespace jubatus::common;
using namespace jubatus::framework;
using namespace pfi::lang;

namespace jubatus { namespace server { // do not change

struct convchecker_config {
  jubatus::fv_converter::converter_config converter;

  template <typename Ar>
  void serialize(Ar& ar) {
    ar
        & NAMED_MEMBER("converter", converter);
  }
};

convchecker_serv::convchecker_serv(const server_argv& a, const jubatus::common::cshared_ptr<jubatus::common::lock_service>& zk)
  :server_base(a)
{
  mixer_.reset(mixer::create_mixer(a, zk));
  mixable_holder_.reset(new mixable_holder());
  mixer_->set_mixable_holder(mixable_holder_);
}

convchecker_serv::~convchecker_serv()
{}


//update, broadcast
bool convchecker_serv::set_config(const std::string& c)
{
  jsonconfig::config config_root(lexical_cast<pfi::text::json::json>(c));
  convchecker_config conf =
    jsonconfig::config_cast_check<convchecker_config>(config_root);

  shared_ptr<jubatus::fv_converter::datum_to_fv_converter> converter =
    fv_converter::make_fv_converter(pfi::text::json::to_json(conf.converter));

  config_ = c;
  converter_ = converter;

  return true;
}

//analysis, random
std::string convchecker_serv::get_config() const
{
  return config_;
}

//update, random
std::string convchecker_serv::query(const jubatus::datum& query)
{
  jubatus::sfv_t fv;
  fv_converter::datum d;

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
void convchecker_serv::get_status(status_t& status) const
{}

void convchecker_serv::after_load(){}
}} // namespace jubatus::serve
