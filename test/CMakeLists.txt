include(ExternalProject)

set(GTEST_FORCE_SHARED_CRT ON)
set(GTEST_DISABLE_PTHREADS OFF)

ExternalProject_Add(
   gtest
   URL https://github.com/google/googletest/archive/master.zip
   PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
   CMAKE_ARGS -Dgtest_force_shared_crt=${GTEST_FORCE_SHARED_CRT}
   -Dgtest_disable_pthreads=${GTEST_DISABLE_PTHREADS}
   # Disable install step
   INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

set_target_properties(libgtest PROPERTIES
   "IMPORTED_LOCATION" "${binary_dir}/lib/MinSizeRel/gtest.lib"
   "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/lib/MinSizeRel/gmock.lib"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

add_subdirectory(testlibsoundex)