project('BasicEmulator', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

SOURCES = []
subdir('src')

exe = executable('basicemulator', SOURCES, include_directories: include_directories('include'), dependencies: [dependency('spdlog')])

test('basic', exe)
