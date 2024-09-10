add_library(tahm STATIC)

project(tahm
    VERSION 1.0.0
    DESCRIPTION "tahmlib is a simple C++ library for making video games"
    LANGUAGES CXX
)


target_sources(tahm PRIVATE
    audio.cpp
    font.cpp
    graphics.cpp
    renderer.cpp
    sound.cpp
    tahm.cpp
    window.cpp
)

target_link_libraries(tahm PUBLIC
    SDL2::SDL2
    SDL2_ttf::SDL2_ttf
)
