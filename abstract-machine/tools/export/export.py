#!/usr/bin/env python3

from pathlib import Path
import os, re, shutil

WHITE_LIST = [
  r'^/klib/',
  r'^/am/',
  r'^/Makefile',
  r'^/README',
  r'^/LICENSE',
  r'^/scripts',
  r'^/tools',
  r'.gitignore',
]

BLACK_LIST = [
  r'/build/',
  r'/tools/export/',
  r'/.git/',
  r'/mininative/',
  r'/riscv/qemu/',
  r'/mips/qemu/',
  r'/*mininative.*',
  r'/mips32-qemu.*',
  r'/riscv32-qemu.*',
  r'/riscv64-qemu.*',
  r'/riscv64-npc.*',
  r'/*ysyxsoc*',
  r'/*.swp',
  r'README.md',
  r'.DS_Store',
  r'.o$', r'.a$', r'.d$', r'.html$',
]

AM_HOME    = (Path(__file__) / '../../..').resolve()
EXPORT_DIR = AM_HOME / 'tools' / 'export' / 'output'
UNIFDEF_FLAGS = '-D__ICS_EXPORT'

# cleanup files
# os.system(f'cd {AM_HOME} && make clean-all')

convert = lambda r: r.replace('.', r'\.').replace('*', r'[^/]*')
list_filter = lambda path, xs: any(re.search(convert(x), path) for x in xs)

def export(white_list, black_list):
  def files():
    for abspath in AM_HOME.rglob('*'):
      if abspath.is_file():
        path = abspath.relative_to(AM_HOME)
        path_str = '/' + str(path)
        white = list_filter(path_str, white_list)
        black = list_filter(path_str, black_list)
        if white and not black:
          print('COPY', path)
          yield abspath, path
   
  try:
    shutil.rmtree(EXPORT_DIR)
  except:
    pass
  
  for abspath, relpath in files():
    src = abspath
    dst = EXPORT_DIR / relpath
    dst.parent.mkdir(parents=True, exist_ok=True)
    if dst.match('*.[chS]'):
        os.system("unifdef " + UNIFDEF_FLAGS + ' ' + str(src) + " > " + str(dst))
    else:
        shutil.copyfile(src, dst)
 
export(WHITE_LIST, BLACK_LIST)
