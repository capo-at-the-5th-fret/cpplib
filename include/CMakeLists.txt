add_library(cpplib

    ../src/math.cpp
)
add_library(cpplib::cpplib ALIAS cpplib)

target_sources(cpplib
    INTERFACE
        FILE_SET HEADERS
        FILES
            cpplib/math.h
)

target_compile_features(cpplib INTERFACE cxx_std_23)
