cmake_minimum_required (VERSION 3.8)

project (soundex)

add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
set(CMAKE_SUPPRESS_REGENERATION true)

enable_testing()

add_subdirectory(main)
add_subdirectory(test)
add_subdirectory(libsoundex)
