project('BasicEmulator', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])


SOURCES = []
INCDIR = [include_directories('include'), include_directories('external/imgui_club/imgui_memory_editor')]
DEPS = [
  dependency('spdlog'),
  dependency('glfw3'),
  dependency('imgui'),
]

subdir('src')

exe = executable('basicemulator', SOURCES, include_directories: INCDIR, dependencies: DEPS)