cmake_minimum_required(VERSION 3.9)
project(SDL2_Template)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

file(GLOB FILES_SRC "*.h" "*.cpp")
add_executable(SDL2_Template ${FILES_SRC})
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(SDL2_Template ${SDL2_LIBRARIES})

