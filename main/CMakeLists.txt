set(sources 
   main.cpp
)

add_executable(soundex
   ${sources}
)

target_link_libraries(soundex
   libsoundex
)