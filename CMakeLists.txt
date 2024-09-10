cmake_minimum_required(VERSION 3.25)


set(PROJECT_NAME "tahm-app")
project(${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "App built with libtahm support"
    LANGUAGES CXX
)

# Define project options
set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_QUIET FALSE)


# Locate third-party libraries
find_package(SDL2 CONFIG)
find_package(SDL2_ttf CONFIG)


include(FetchContent)

# Download and build third-party libraries in case they were not found
if(${SDL2_FOUND})
    message(STATUS "Found SDL2")
else()
    message(STATUS "Could not locate SDL2")
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
        GIT_TAG release-2.30.5
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(SDL2)
endif()

if(${SDL_ttf_FOUND})
    message(STATUS "Found SDL2_ttf")
else()
    message(STATUS "Could not locate SDL2_ttf")
    FetchContent_Declare(
        SDL2_ttf
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL_ttf.git"
        GIT_TAG release-2.22.0
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(SDL2_ttf)
endif()


# Build libtahm.a
add_subdirectory(tahm/tahm)

# Build the app itself
add_executable(${PROJECT_NAME}
    tahm/engine.cpp
    tahm/main.cpp
)

# Link app with required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    tahm
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_ttf::SDL2_ttf
)