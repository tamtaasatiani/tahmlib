project('tahm', 'cpp',
  version : '0.1.0',
  default_options : [
    'cpp_std=c++23',
    'warning_level=3', # 3 is the default
    'buildtype=debug',
    'optimization=0',
  ]
)

c_args = [
  '-Wall',
  '-Wextra',
]

cpp_args = [
  '-Wno-pedantic',
  '-Wno-narrowing',
  '-Wno-missing-field-initializers',
]

# Define the source files for the project
src_files = files(
    'tahm/main.cpp',
    'tahm/engine.cpp',

    'tahm/tahm/audio.cpp',
    'tahm/tahm/font.cpp',
    'tahm/tahm/graphics.cpp',
    'tahm/tahm/renderer.cpp',
    'tahm/tahm/sound.cpp',
    'tahm/tahm/tahm.cpp',
    'tahm/tahm/window.cpp',
)

link_args = [
 
]


sdl_dep = dependency('sdl2', required: true)
sdl_ttf_dep = dependency('sdl2_ttf', required: true)

dependencies = [
    sdl_dep,
    sdl_ttf_dep,
]

# Includes
inc_dir = include_directories(
    'tahm/tahm',
)

# Make the executable
executable('tahm', 
  src_files,
  include_directories: inc_dir,
  dependencies: dependencies,
  c_args: c_args,
  cpp_args: cpp_args,
  link_args: link_args,
)
