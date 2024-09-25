project('tahm', 'cpp',
  version : '0.1.0',
  default_options : [
    'cpp_std=c++20',
    'warning_level=3',  # 3 is the default
    'buildtype=debug',  # debug is the default
    'optimization=0',   # 0 is the default, 0 is for debug
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

# Define the linker arguments
link_args = [
 
]


sdl_dep = dependency('sdl2', required: true)
# sdl_ttf_dep = dependency('sdl2_ttf', required: true) # for Arch Linux
sdl_ttf_dep = dependency('SDL2_ttf', required: true, method: 'pkg-config') # for Ubuntu

dependencies = [
    sdl_dep,
    sdl_ttf_dep,
]

# Project includes
inc_dir = include_directories(
    'tahm/tahm',
)

# Create the executable
executable('tahm', 
  src_files,
  include_directories: inc_dir,
  dependencies: dependencies,
  c_args: c_args,
  cpp_args: cpp_args,
  link_args: link_args,
)
