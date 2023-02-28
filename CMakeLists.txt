cmake_minimum_required(VERSION 3.25)

project(cpp_lib
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "A C++ static library project"
)

# Determine if this project is built as a subproject (using add_subdirectory)
# or if it is the top project.
set(CPP_LIB_TOP_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CPP_LIB_TOP_PROJECT ON)
endif()

# project options
option(CPP_LIB_BUILD_TESTS "Build cpp lib tests" ${CPP_LIB_TOP_PROJECT})

# the main library
add_subdirectory(src)

# the tests
if(CPP_LIB_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

# header only install
option(CPP_LIB_INSTALL ${CPP_LIB_TOP_PROJECT})
if (CPP_LIB_INSTALL)
    include(GNUInstallDirs)

    install(TARGETS cpp_lib EXPORT cpp_lib-config)

    install(
        EXPORT cpp_lib-config
        NAMESPACE cpp_lib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cpp_lib
    )

    install(
        DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/src/cpp_lib/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_lib
        FILES_MATCHING PATTERN "*.h"
    )
    install(
        DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/external/cpp_lib/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_lib
    )

endif()
