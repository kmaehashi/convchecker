name='convchecker'

def options(opt):
  opt.load('compiler_cxx')

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')

  conf.check_cxx(lib = 'msgpack', mandatory = True)
  conf.check_cxx(lib = 'glog', mandatory = True)

  conf.check_cxx(lib = 'pficommon', mandatory = True)
  conf.check_cxx(lib = 'pficommon_system', mandatory = True)
  conf.check_cxx(lib = 'pficommon_concurrent', mandatory = True)
  conf.check_cxx(lib = 'pficommon_math', mandatory = True)
  conf.check_cxx(lib = 'pficommon_text', mandatory = True)

  conf.check_cxx(lib = 'jubatus_framework', mandatory = True)
  conf.check_cxx(lib = 'jubacommon', mandatory = True)
  conf.check_cxx(lib = 'jubacommon_mprpc', mandatory = True)
  conf.check_cxx(lib = 'jubaconverter', mandatory = True)
  conf.check_cxx(lib = 'jubamixer', mandatory = True)
  conf.check_cxx(lib = 'jubatus_mpio', mandatory = True)
  conf.check_cxx(lib = 'jubatus_msgpack-rpc', mandatory = True)

def build(bld):
  bld.program(
    source = name+'_serv.cpp '+ name +'_impl.cpp',
    target = 'juba' + name,
    use = ['JUBATUS_FRAMEWORK', 'JUBACOMMON', 'JUBACOMMON_MPRPC', 'JUBACONVERTER', 'JUBAMIXER', 'PFICOMMON', 'PFICOMMON_CONCURRENT',
           'PFICOMMON_SYSTEM', 'PFICOMMON_TEXT', 'MSGPACK', 'JUBATUS_MPIO', 'JUBATUS_MSGPACK-RPC',
           'GLOG']
    )

