#!/usr/bin/env python
# -*- coding: utf-8 -*-

import convchecker.client
import convchecker.types

NAME = "checker";

if __name__ == '__main__':

  checker = convchecker.client.convchecker("127.0.0.1",9199)

  datum0 = convchecker.types.datum(  [["message", "We love jubatus!"]], [["rank", 10.0]] )
  datum1 = convchecker.types.datum(  [["name", "jubatus"],["license", "LGPL v2.1"],["author", "NTT & PFI"]], [["version", 0.31]] )
  datum2 = convchecker.types.datum(  [["URL", "http://jubat.us/"]], [["count", 256.0],["lenght", 10243.0]] )
  
  print checker.query(NAME, datum0)
  print "--------------------------------------"
  print checker.bulk_query(NAME, [datum1,datum2])



