# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Soundex1")

include_directories($ENV{GMOCK_HOME}/googletest/include $ENV{GMOCK_HOME}/googlemock/include)
link_directories($ENV{GMOCK_HOME}/mybuild/lib/MinSizeRel)

add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
   main.cpp 
   SoundexTest.cpp)

add_executable(test ${sources})

target_link_libraries(test gmock)
target_link_libraries(test gtest)