##
## EPITECH PROJECT, 2022
## CMakeLists
## File description:
## Main Compilation Program
##

project(bomberman)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.17)

# Set Include Directory
include_directories(../include)
include_directories(../include/Encapsulation)
include_directories(../include/Engine)
include_directories(../include/Error)
include_directories(../include/System)
# add_subdirectory(lib/Game)
# add_subdirectory(lib/Graphic)

# Set Cmake Wildcard
file(GLOB ALL_SRCS
    #"sandBox/*.cpp"
    "../src/Component/*.cpp"
    "../src/World/*.cpp"
    "../src/Game/System/*.cpp"
    "../src/Encapsulation/*.cpp"
    "../src/Game/*.cpp"
    "../src/Game/baseEntities/*.cpp"
    "../src/Error/*.cpp"
    "../src/*.cpp"
)

# Set Sources Files & Link Libraries
add_executable(bomberman ${ALL_SRCS} )

find_package(
 Boost 1.65 REQUIRED
)

target_link_libraries(bomberman raylib)
# target_link_libraries(bomberman boost_serialization)
target_link_libraries(bomberman ${Boost_LIBRARIES})
add_custom_command(TARGET bomberman POST_BUILD COMMAND cp bomberman ${PROJECT_SOURCE_DIR})
