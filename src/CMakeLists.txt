# Header-only
add_library(cpplib INTERFACE)
add_library(cpplib::cpplib ALIAS cpplib)

# source files
target_sources(cpplib

INTERFACE
    cpplib/cmath.h
    cpplib/string.h
)

# require c++23
target_compile_features(cpplib INTERFACE cxx_std_23)

# https://stackoverflow.com/questions/7035734/cmake-parent-directory
#get_filename_component(CURRENT_PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)

# Add folder to any project that uses the library
# https://discourse.cmake.org/t/possible-issue-with-build-interface/659/4
target_include_directories(
    cpplib
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
