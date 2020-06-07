set(sources
   soundexencoder.h
   soundexencoder.cpp
   charutil.h
   stringutil.h
)

add_library(libsoundex STATIC
   ${sources}
)

target_include_directories(libsoundex PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}
)