cmake_minimum_required(VERSION 2.8.10)
project(libpolyp)

exec_program("git" ${CMAKE_CURRENT_SOURCE_DIR} ARGS "describe --long" OUTPUT_VARIABLE VERSION )
set( GIT_VERSION ${VERSION} )
configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.cmake ${CMAKE_SOURCE_DIR}/src/config.h )

message("Building version: ${VERSION}")

enable_testing()

find_package(unittest REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${UNITTEST_INCLUDE_DIR})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(src)

#tests
add_subdirectory(t)
