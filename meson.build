project('leet1', 'cpp',
  version: '0.1.0',
  default_options: [
    'cpp_std=c++26',
    'warning_level=3',
    'werror=true',
    'b_colorout=always',
    'b_sanitize=address,undefined',
    'b_lundef=false',
  ],
)

add_project_arguments(
  '-Wconversion',
  '-fdiagnostics-show-template-tree',
  language: 'cpp',
)

executable('leet1', 'src/main.cc',
  include_directories: include_directories('include'),
)
