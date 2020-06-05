file(GLOB sources *.cpp)

add_executable(testlibsoundex ${sources})

target_link_libraries(testlibsoundex
   libsoundex
   libgtest
   libgmock
)

add_test(NAME testlibsoundex 
        COMMAND testlibsoundex)
