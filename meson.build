project('BasicEmulator', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])


gtest_proj = subproject('gtest')
gtest = gtest_proj.get_variable('gtest_dep')
gmock = gtest_proj.get_variable('gmock_dep')


SOURCES = []
TESTS = []
INCDIR = [include_directories('include'), include_directories('external/imgui_club/imgui_memory_editor')]
DEPS = [
  dependency('spdlog'),
  dependency('glfw3'),
  dependency('imgui'),
  gtest,
  gmock
]

subdir('src')

exe = executable('basicemulator', SOURCES, include_directories: INCDIR, dependencies: DEPS)

tests_exe = executable('emu_tests',SOURCES, TESTS, dependencies: DEPS, include_directories: INCDIR)
test('Emulation Test', tests_exe)