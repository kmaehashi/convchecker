// this program is automatically generated by jenerator. do not edit.
#include <jubatus/framework.hpp>
#include "convchecker_server.hpp"
#include "convchecker_serv.hpp"

using namespace jubatus;
using namespace jubatus::framework;
namespace jubatus { namespace server {
class convchecker_impl_ : public convchecker<convchecker_impl_>
{
public:
  convchecker_impl_(const server_argv& a):
    convchecker<convchecker_impl_>(a.timeout),
    p_(new server_helper<convchecker_serv>(a))
  {}

  std::string get_config(std::string name) //analysis random
  { JRLOCK__(p_); return get_p()->get_config(); }

  std::string query(std::string name, datum query) //update random
  { JWLOCK__(p_); return get_p()->query(query); }

  std::string bulk_query(std::string name, std::vector<datum > query) //update random
  { JWLOCK__(p_); return get_p()->bulk_query(query); }

  bool save(std::string name, std::string id) //update broadcast
  { JWLOCK__(p_); return get_p()->save(id); }

  bool load(std::string name, std::string id) //update broadcast
  { JWLOCK__(p_); return get_p()->load(id); }

  std::map<std::string,std::map<std::string,std::string > > get_status(std::string name) //analysis broadcast
  { JRLOCK__(p_); return p_->get_status(); }
  int run(){ return p_->start(*this); };
  common::cshared_ptr<convchecker_serv> get_p(){ return p_->server(); };
private:
  common::cshared_ptr<server_helper<convchecker_serv> > p_;
};
}} // namespace jubatus::server
int main(int args, char** argv){
  return
    jubatus::framework::run_server<jubatus::server::convchecker_impl_>
       (args, argv, "convchecker");
}
