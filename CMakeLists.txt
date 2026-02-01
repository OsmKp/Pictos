cmake_minimum_required(VERSION 3.20)
project(Pictos)

set(CMAKE_CXX_STANDARD 23)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
include(Dependencies.cmake)

add_subdirectory(Core)
add_subdirectory(App)
