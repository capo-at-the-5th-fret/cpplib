cmake_minimum_required(VERSION 3.26.0)

project(cpplib
    VERSION 0.1.0
    LANGUAGES CXX
)

add_subdirectory(include)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)

    option(CPPLIB_BUILD_TESTS "Enable or disable the building of tests" ON)
    option(CPPLIB_ENABLE_INSTALL "Enable or disable the install rule" ON)

    if (CPPLIB_BUILD_TESTS)
        enable_testing()
        add_subdirectory(tests)
    endif()

    if (CPPLIB_ENABLE_INSTALL)

        include(GNUInstallDirs)
        include(CMakePackageConfigHelpers)

        # NOTE 1: The XXX_PACKAGE_TARGETS variable is referenced inside of the
        # xxxConfig.cmake.in file, so if the name of this variable changes, it
        # must be updated inside of the xxxConfig.cmake.in file.
        #
        # NOTE 2: If value of this variable changes, the xxxConfig.cmake.in file
        # name must be renamed to match the new value.
        set(CPPLIB_PACKAGE_NAME ${PROJECT_NAME})
        set(CPPLIB_PACKAGE_TARGETS ${CPPLIB_PACKAGE_NAME}Targets)

        set(CPPLIB_INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_INCLUDEDIR})
        set(CPPLIB_INSTALL_CMAKE_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${CPPLIB_PACKAGE_NAME})

        set(CPPLIB_CONFIG_DIR ${PROJECT_BINARY_DIR}/cmake)
        set(CPPLIB_CONFIG_IN cmake/${CPPLIB_PACKAGE_NAME}Config.cmake.in)
        set(CPPLIB_CONFIG ${CPPLIB_CONFIG_DIR}/${CPPLIB_PACKAGE_NAME}Config.cmake)
        set(CPPLIB_CONFIG_VERSION ${CPPLIB_CONFIG_DIR}/${CPPLIB_PACKAGE_NAME}ConfigVersion.cmake)

        configure_package_config_file(
            ${CPPLIB_CONFIG_IN}
            ${CPPLIB_CONFIG}
            INSTALL_DESTINATION ${CPPLIB_INSTALL_CMAKE_DIR}
        )

        # major.minor.patch1 is compatible with major.minor.patch2..n
        # if no VERSION is specified, the ${PROJECT_VERSION} variable will be
        # used. if the ${PROJECT_VERSION} is not set, CMake will output an
        # error
        write_basic_package_version_file(
            ${CPPLIB_CONFIG_VERSION}
            COMPATIBILITY SameMinorVersion
        )

        install(
            FILES
                ${CPPLIB_CONFIG}
                ${CPPLIB_CONFIG_VERSION}
            DESTINATION ${CPPLIB_INSTALL_CMAKE_DIR}
        )

        install(TARGETS ${CPPLIB_PACKAGE_NAME}
            EXPORT ${CPPLIB_PACKAGE_TARGETS}
            FILE_SET HEADERS
        )

        install(EXPORT ${CPPLIB_PACKAGE_TARGETS}
            NAMESPACE ${CPPLIB_PACKAGE_NAME}::
            DESTINATION ${CPPLIB_INSTALL_CMAKE_DIR}
        )

    endif()

endif()
