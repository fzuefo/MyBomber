##
## EPITECH PROJECT, 2022
## CMakeLists
## File description:
## Main Compilation Program
##

project(Bomberman)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
cmake_minimum_required(VERSION 3.17)

# Set Include Directory
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)
FIND_PACKAGE(raylib REQUIRED)

if (WIN32)
# Configure raylib CMakeLists.txt
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/raylib/CMakeLists.in
    ${CMAKE_SOURCE_DIR}/build/raylib-download/CMakeLists.txt
)

# Configure boost CMakeLists.txt
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/boost/CMakeLists.in
    ${CMAKE_SOURCE_DIR}/build/boost-download/CMakeLists.txt
)

# Generate the raylib project ---------------
# Generate build commands
execute_process(
        COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/raylib-download
)
if(result)
    message(FATAL_ERROR "CMake step for deps failed: ${result}")
endif()
# Build the raylib project
execute_process(
        COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/raylib-download
)
#-----------------

# Generate the boost project ---------------
# Generate build commands
execute_process(
        COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/boost-download
)
if(result)
    message(FATAL_ERROR "CMake step for deps failed: ${result}")
endif()
# Build the boost project
execute_process(
        COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/boost-download
)
#-----------------

add_subdirectory(
        ${CMAKE_SOURCE_DIR}/build/raylib-src
        ${CMAKE_SOURCE_DIR}/build/raylib-build
)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/build/boost-src
    ${CMAKE_SOURCE_DIR}/build/boost-build
)

set( RAYLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/build/raylib-build/include )
set( BOOST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/build/boost-src/libs/ )
endif()
# Set Include Directory
include_directories(include)
include_directories(include/Encapsulation)
include_directories(include/Engine)
include_directories(include/System)
include_directories(include/Error)
if (WIN32)
include_directories(${RAYLIB_INCLUDE_DIR})
include_directories(${BOOST_INCLUDE_DIR}/accumulators/include)
include_directories(${BOOST_INCLUDE_DIR}/algorithm/include)
include_directories(${BOOST_INCLUDE_DIR}/align/include)
include_directories(${BOOST_INCLUDE_DIR}/any/include)
include_directories(${BOOST_INCLUDE_DIR}/array/include)
include_directories(${BOOST_INCLUDE_DIR}/asio/include)
include_directories(${BOOST_INCLUDE_DIR}/assert/include)
include_directories(${BOOST_INCLUDE_DIR}/assign/include)
include_directories(${BOOST_INCLUDE_DIR}/atomic/include)
include_directories(${BOOST_INCLUDE_DIR}/beast/include)
include_directories(${BOOST_INCLUDE_DIR}/bimap/include)
include_directories(${BOOST_INCLUDE_DIR}/bind/include)
include_directories(${BOOST_INCLUDE_DIR}/callable_traits/include)
include_directories(${BOOST_INCLUDE_DIR}/chrono/include)
include_directories(${BOOST_INCLUDE_DIR}/circular_buffer/include)
include_directories(${BOOST_INCLUDE_DIR}/compatibility/include)
include_directories(${BOOST_INCLUDE_DIR}/compute/include)
include_directories(${BOOST_INCLUDE_DIR}/concept_check/include)
include_directories(${BOOST_INCLUDE_DIR}/config/include)
include_directories(${BOOST_INCLUDE_DIR}/container/include)
include_directories(${BOOST_INCLUDE_DIR}/container_hash/include)
include_directories(${BOOST_INCLUDE_DIR}/context/include)
include_directories(${BOOST_INCLUDE_DIR}/contract/include)
include_directories(${BOOST_INCLUDE_DIR}/conversion/include)
include_directories(${BOOST_INCLUDE_DIR}/convert/include)
include_directories(${BOOST_INCLUDE_DIR}/core/include)
include_directories(${BOOST_INCLUDE_DIR}/coroutine/include)
include_directories(${BOOST_INCLUDE_DIR}/coroutine2/include)
include_directories(${BOOST_INCLUDE_DIR}/crc/include)
include_directories(${BOOST_INCLUDE_DIR}/date_time/include)
include_directories(${BOOST_INCLUDE_DIR}/describe/include)
include_directories(${BOOST_INCLUDE_DIR}/detail/include)
include_directories(${BOOST_INCLUDE_DIR}/dll/include)
include_directories(${BOOST_INCLUDE_DIR}/dynamic_bitset/include)
include_directories(${BOOST_INCLUDE_DIR}/endian/include)
include_directories(${BOOST_INCLUDE_DIR}/exception/include)
include_directories(${BOOST_INCLUDE_DIR}/fiber/include)
include_directories(${BOOST_INCLUDE_DIR}/filesystem/include)
include_directories(${BOOST_INCLUDE_DIR}/flyweight/include)
include_directories(${BOOST_INCLUDE_DIR}/foreach/include)
include_directories(${BOOST_INCLUDE_DIR}/format/include)
include_directories(${BOOST_INCLUDE_DIR}/function/include)
include_directories(${BOOST_INCLUDE_DIR}/function_types/include)
include_directories(${BOOST_INCLUDE_DIR}/functional/include)
include_directories(${BOOST_INCLUDE_DIR}/fusion/include)
include_directories(${BOOST_INCLUDE_DIR}/geometry/include)
include_directories(${BOOST_INCLUDE_DIR}/gil/include)
include_directories(${BOOST_INCLUDE_DIR}/graph/include)
include_directories(${BOOST_INCLUDE_DIR}/graph_parallel/include)
include_directories(${BOOST_INCLUDE_DIR}/hana/include)
include_directories(${BOOST_INCLUDE_DIR}/headers/include)
include_directories(${BOOST_INCLUDE_DIR}/heap/include)
include_directories(${BOOST_INCLUDE_DIR}/histogram/include)
include_directories(${BOOST_INCLUDE_DIR}/hof/include)
include_directories(${BOOST_INCLUDE_DIR}/icl/include)
include_directories(${BOOST_INCLUDE_DIR}/integer/include)
include_directories(${BOOST_INCLUDE_DIR}/interprocess/include)
include_directories(${BOOST_INCLUDE_DIR}/intrusive/include)
include_directories(${BOOST_INCLUDE_DIR}/io/include)
include_directories(${BOOST_INCLUDE_DIR}/iostreams/include)
include_directories(${BOOST_INCLUDE_DIR}/iterator/include)
include_directories(${BOOST_INCLUDE_DIR}/json/include)
include_directories(${BOOST_INCLUDE_DIR}/lambda/include)
include_directories(${BOOST_INCLUDE_DIR}/lambda2/include)
include_directories(${BOOST_INCLUDE_DIR}/leaf/include)
include_directories(${BOOST_INCLUDE_DIR}/lexical_cast/include)
include_directories(${BOOST_INCLUDE_DIR}/local_function/include)
include_directories(${BOOST_INCLUDE_DIR}/locale/include)
include_directories(${BOOST_INCLUDE_DIR}/lockfree/include)
include_directories(${BOOST_INCLUDE_DIR}/log/include)
include_directories(${BOOST_INCLUDE_DIR}/logic/include)
include_directories(${BOOST_INCLUDE_DIR}/math/include)
include_directories(${BOOST_INCLUDE_DIR}/metaparse/include)
include_directories(${BOOST_INCLUDE_DIR}/move/include)
include_directories(${BOOST_INCLUDE_DIR}/mp11/include)
include_directories(${BOOST_INCLUDE_DIR}/mpi/include)
include_directories(${BOOST_INCLUDE_DIR}/mpl/include)
include_directories(${BOOST_INCLUDE_DIR}/msm/include)
include_directories(${BOOST_INCLUDE_DIR}/multi_array/include)
include_directories(${BOOST_INCLUDE_DIR}/multi_index/include)
include_directories(${BOOST_INCLUDE_DIR}/multiprecision/include)
include_directories(${BOOST_INCLUDE_DIR}/nowide/include)
include_directories(${BOOST_INCLUDE_DIR}/numeric/include)
include_directories(${BOOST_INCLUDE_DIR}/optional/include)
include_directories(${BOOST_INCLUDE_DIR}/outcome/include)
include_directories(${BOOST_INCLUDE_DIR}/parameter/include)
include_directories(${BOOST_INCLUDE_DIR}/parameter_python/include)
include_directories(${BOOST_INCLUDE_DIR}/pfr/include)
include_directories(${BOOST_INCLUDE_DIR}/phoenix/include)
include_directories(${BOOST_INCLUDE_DIR}/poly_collection/include)
include_directories(${BOOST_INCLUDE_DIR}/polygon/include)
include_directories(${BOOST_INCLUDE_DIR}/pool/include)
include_directories(${BOOST_INCLUDE_DIR}/predef/include)
include_directories(${BOOST_INCLUDE_DIR}/preprocessor/include)
include_directories(${BOOST_INCLUDE_DIR}/process/include)
include_directories(${BOOST_INCLUDE_DIR}/program_options/include)
include_directories(${BOOST_INCLUDE_DIR}/property_map/include)
include_directories(${BOOST_INCLUDE_DIR}/property_map_parallel/include)
include_directories(${BOOST_INCLUDE_DIR}/property_tree/include)
include_directories(${BOOST_INCLUDE_DIR}/proto/include)
include_directories(${BOOST_INCLUDE_DIR}/ptr_container/include)
include_directories(${BOOST_INCLUDE_DIR}/python/include)
include_directories(${BOOST_INCLUDE_DIR}/qvm/include)
include_directories(${BOOST_INCLUDE_DIR}/random/include)
include_directories(${BOOST_INCLUDE_DIR}/range/include)
include_directories(${BOOST_INCLUDE_DIR}/ratio/include)
include_directories(${BOOST_INCLUDE_DIR}/rational/include)
include_directories(${BOOST_INCLUDE_DIR}/regex/include)
include_directories(${BOOST_INCLUDE_DIR}/safe_numerics/include)
include_directories(${BOOST_INCLUDE_DIR}/scope_exit/include)
include_directories(${BOOST_INCLUDE_DIR}/serialization/include)
include_directories(${BOOST_INCLUDE_DIR}/signals2/include)
include_directories(${BOOST_INCLUDE_DIR}/smart_ptr/include)
include_directories(${BOOST_INCLUDE_DIR}/sort/include)
include_directories(${BOOST_INCLUDE_DIR}/spirit/include)
include_directories(${BOOST_INCLUDE_DIR}/stacktrace/include)
include_directories(${BOOST_INCLUDE_DIR}/statechart/include)
include_directories(${BOOST_INCLUDE_DIR}/static_assert/include)
include_directories(${BOOST_INCLUDE_DIR}/static_string/include)
include_directories(${BOOST_INCLUDE_DIR}/stl_interfaces/include)
include_directories(${BOOST_INCLUDE_DIR}/system/include)
include_directories(${BOOST_INCLUDE_DIR}/test/include)
include_directories(${BOOST_INCLUDE_DIR}/thread/include)
include_directories(${BOOST_INCLUDE_DIR}/throw_exception/include)
include_directories(${BOOST_INCLUDE_DIR}/timer/include)
include_directories(${BOOST_INCLUDE_DIR}/tokenizer/include)
include_directories(${BOOST_INCLUDE_DIR}/tti/include)
include_directories(${BOOST_INCLUDE_DIR}/tuple/include)
include_directories(${BOOST_INCLUDE_DIR}/type_erasure/include)
include_directories(${BOOST_INCLUDE_DIR}/type_index/include)
include_directories(${BOOST_INCLUDE_DIR}/type_traits/include)
include_directories(${BOOST_INCLUDE_DIR}/typeof/include)
include_directories(${BOOST_INCLUDE_DIR}/units/include)
include_directories(${BOOST_INCLUDE_DIR}/unordered/include)
include_directories(${BOOST_INCLUDE_DIR}/utility/include)
include_directories(${BOOST_INCLUDE_DIR}/uuid/include)
include_directories(${BOOST_INCLUDE_DIR}/variant/include)
include_directories(${BOOST_INCLUDE_DIR}/variant2/include)
include_directories(${BOOST_INCLUDE_DIR}/vmd/include)
include_directories(${BOOST_INCLUDE_DIR}/wave/include)
include_directories(${BOOST_INCLUDE_DIR}/winapi/include)
include_directories(${BOOST_INCLUDE_DIR}/xpressive/include)
include_directories(${BOOST_INCLUDE_DIR}/yap/include)
endif()

# Set Cmake Wildcard
file(GLOB ALL_SRCS
    "src/*.cpp"
    "src/Component/*.cpp"
    "src/World/*.cpp"
    "src/Game/System/*.cpp"
    "src/Encapsulation/*.cpp"
    "src/Game/*.cpp"
    "src/Error/*.cpp"
)

# Set Sources Files & Link Libraries
add_executable(bomberman ${ALL_SRCS})
target_link_libraries(bomberman raylib)

# TODO: file updated to commit
