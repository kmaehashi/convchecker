
// This file is auto-generated from convchecker.idl
// *** DO NOT EDIT ***

#ifndef CONVCHECKER_TYPES_HPP_
#define CONVCHECKER_TYPES_HPP_


#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <stdint.h>
#include <msgpack.hpp>


namespace jubatus {

struct config_data {
public:

  
  MSGPACK_DEFINE(config);  

  std::string config;
};

struct datum {
public:

  
  MSGPACK_DEFINE(string_values, num_values);  

  std::vector<std::pair<std::string, std::string > > string_values;
  std::vector<std::pair<std::string, double > > num_values;
};

} // namespace jubatus



#endif // CONVCHECKER_TYPES_HPP_
