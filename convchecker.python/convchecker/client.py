
# This file is auto-generated from convchecker.idl
# *** DO NOT EDIT ***


import msgpackrpc
from types import *


class convchecker:
  def __init__ (self, host, port):
    address = msgpackrpc.Address(host, port)
    self.client = msgpackrpc.Client(address)

  def get_config (self, name):
    retval = self.client.call('get_config', name)
    return retval

  def query (self, name, query):
    retval = self.client.call('query', name, query)
    return retval

  def bulk_query (self, name, query):
    retval = self.client.call('bulk_query', name, query)
    return retval

  def save (self, name, id):
    retval = self.client.call('save', name, id)
    return retval

  def load (self, name, id):
    retval = self.client.call('load', name, id)
    return retval

  def get_status (self, name):
    retval = self.client.call('get_status', name)
    return {k_retval : {k_v_retval : v_v_retval for k_v_retval,v_v_retval in v_retval.items()} for k_retval,v_retval in retval.items()}



