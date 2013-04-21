cmake_minimum_required(VERSION 2.8.10)
project(libpolyp)

exec_program("git" ${CMAKE_CURRENT_SOURCE_DIR} ARGS "describe --tags" OUTPUT_VARIABLE VERSION )
set( GIT_VERSION ${VERSION} )
configure_file( ${CMAKE_SOURCE_DIR}/src/config.h.cmake ${CMAKE_SOURCE_DIR}/src/config.h )

message("Building version: ${VERSION}")

find_package(unittest REQUIRED)
include(CTest)

include_directories(${UNITTEST_INCLUDE_DIR})
include_directories("${PROJECT_BINARY_DIR}/include")

add_subdirectory(src)
add_subdirectory(t)
