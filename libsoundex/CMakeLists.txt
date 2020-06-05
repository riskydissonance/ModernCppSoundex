set(sources
   soundex.h
   soundex.cpp
)

add_library(libsoundex STATIC
   ${sources}
)

target_include_directories(libsoundex PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}
)