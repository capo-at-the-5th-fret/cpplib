# Header-only
add_library(cpp_lib INTERFACE)
add_library(cpp_lib::cpp_lib ALIAS cpp_lib)

# source files
target_sources(cpp_lib

INTERFACE
    cpp_lib/cmath.h

)

# require c++23
target_compile_features(cpp_lib INTERFACE cxx_std_23)

# https://stackoverflow.com/questions/7035734/cmake-parent-directory
get_filename_component(CURRENT_PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)

# Add folder to any project that uses the library
# https://discourse.cmake.org/t/possible-issue-with-build-interface/659/4
target_include_directories(
    cpp_lib
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
