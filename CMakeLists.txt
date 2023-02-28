cmake_minimum_required(VERSION 3.25)

project(cpplib
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "A C++ static library project"
)

# Determine if this project is built as a subproject (using add_subdirectory)
# or if it is the top project.
set(CPPLIB_TOP_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CPPLIB_TOP_PROJECT ON)
endif()

message("CPPLIB_TOP_PROJECT is ${CPPLIB_TOP_PROJECT}.")

# project options
option(CPPLIB_BUILD_TESTS "Build cpp lib tests" ${CPPLIB_TOP_PROJECT})

message("CPPLIB_BUILD_TESTS is ${CPPLIB_BUILD_TESTS}.")

# the main library
add_subdirectory(src)

# the tests
if(CPPLIB_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

# header only install
option(CPPLIB_INSTALL ${CPPLIB_TOP_PROJECT})

message("CPPLIB_INSTALL is ${CPPLIB_INSTALL}.")

if (CPPLIB_INSTALL)
    include(GNUInstallDirs)

    install(TARGETS cpplib EXPORT cpplib-config)

    install(
        EXPORT cpplib-config
        NAMESPACE cpplib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cpplib
    )

    install(
        DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/src/cpplib/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpplib
        FILES_MATCHING PATTERN "*.h"
    )

endif()
