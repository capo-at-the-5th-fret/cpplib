#include <doctest/doctest.h>
//#include <catch2/catch_all.hpp>
#include "cpplib/math.h"

TEST_CASE("add")
{
    REQUIRE(cpplib::add(1, 1) == 2);
}
