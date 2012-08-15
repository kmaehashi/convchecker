#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys,json
import convchecker.client
import convchecker.types

NAME = "stat_cla";

if __name__ == '__main__':

  checker = convchecker.client.convchecker("127.0.0.1",9199)

  converter = json.loads(open('./convert.json').read())
  config = convchecker.types.config_data(json.dumps(converter))
  checker.set_config(NAME, config)

  datum = convchecker.types.datum(  [["URL", "We love hack!"]], [["weight", 10.0]] )
  print checker.query(NAME, datum)



