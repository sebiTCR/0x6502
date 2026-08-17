project('0x6502', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])


SOURCES = []
INCDIR = [include_directories('include')]
DEPS = [
  dependency('spdlog'),
  dependency('glfw3'),
  dependency('imgui-docking'),
]

subdir('external')
subdir('src')

exe = executable('0x6502', SOURCES, include_directories: INCDIR, dependencies: DEPS)