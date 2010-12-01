import Options
from os import unlink, symlink, popen
from os.path import exists 

srcdir = "."
blddir = "build"
VERSION = "0.0.1"

def set_options(opt):
  opt.tool_options("compiler_cxx")

def configure(conf):
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")

def build(bld):
  obj = bld.new_task_gen("cxx", "shlib", "node_addon")
  obj.target = "des"
  obj.source = "src/des-module.cpp src/d3des.cpp"

def shutdown():
  if Options.commands['clean']:
    if exists('des.node'): unlink('des.node')
  else:
    if exists('build/default/des.node') and not exists('des.node'):
      symlink('build/default/des.node', 'des.node')

