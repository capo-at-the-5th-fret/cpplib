
add_definitions(-DENABLE_DOCTEST_IN_LIBRARY)
include(FetchContent)

# search for a doctest package, otherwise fetch it
set(NEEDED_DOCTEST_VERSION "2.4.9")

find_package(doctest ${NEEDED_DOCTEST_VERSION} QUIET)

if (NOT doctest_FOUND)

  FetchContent_Declare(
      DocTest
      GIT_REPOSITORY "https://github.com/onqtam/doctest"
      GIT_TAG        v${NEEDED_DOCTEST_VERSION}
      GIT_SHALLOW    TRUE
  )

  FetchContent_MakeAvailable(DocTest)
 
  # include the doctest module that contains doctest_discover_tests
  # TODO: Can't figure out how to get to the path in the FetchContent source
  # folder, so a copy was placed in the tests/modules folder
  #list(APPEND CMAKE_MODULE_PATH ${DOCTEST_INCLUDE_DIR}/scripts/cmake)
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules)

endif()

# this needs to be called for the doctest_discover_tests function to work
include(doctest)

add_executable(testrunner

    main.cpp

    cmath_tests.cpp
    string_tests.cpp

)

target_include_directories(testrunner PRIVATE "${CMAKE_CURRENT_DIR}/")
target_link_libraries(testrunner
  PRIVATE
  cpp_lib
  doctest::doctest
)

doctest_discover_tests(testrunner)

#include(Catch)
#catch_discover_tests(testrunner)


# include(FetchContent)

# # search for a Catch2 package, otherwise fetch it
# set(NEEDED_CATCH2_VERSION "3.3.0")

# find_package(Catch2 ${NEEDED_CATCH2_VERSION} QUIET)

# if (NOT Catch2_FOUND)

#   FetchContent_Declare(
#     Catch2
#     GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#     GIT_TAG        v${NEEDED_CATCH2_VERSION}
#     GIT_SHALLOW    TRUE
#   )
#   FetchContent_MakeAvailable(Catch2)

#   list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)

# endif()

# add_executable(testrunner

#     cmath_tests.cpp

# )

# target_include_directories(testrunner PRIVATE "${CMAKE_CURRENT_DIR}/")
# target_link_libraries(testrunner PRIVATE Catch2::Catch2WithMain cpp_lib)

# include(Catch)
# catch_discover_tests(testrunner)
