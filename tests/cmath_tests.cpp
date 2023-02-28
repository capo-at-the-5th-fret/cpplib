//#include <catch2/catch_all.hpp>
#include <doctest/doctest.h>
#include "cpplib/cmath.h"

namespace {

    using int_test_types = std::tuple<short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long>;
}

TEST_CASE_TEMPLATE_DEFINE("is_even", T, is_even_test_id)
{
    using cpplib::is_even;
    
    CHECK(is_even(T{0}));
    CHECK_FALSE(is_even(T{1}));
    CHECK(is_even(T{2}));
    CHECK_FALSE(is_even(T{3}));
    CHECK(is_even(T{4}));

    if constexpr (std::is_signed_v<T>)
    {
        CHECK_FALSE(is_even(T{-1}));
        CHECK(is_even(T{-2}));
        CHECK_FALSE(is_even(T{-3}));
        CHECK(is_even(T{-4}));
    }
}

TEST_CASE_TEMPLATE_APPLY(is_even_test_id, int_test_types);

TEST_CASE_TEMPLATE_DEFINE("is_odd", T, is_odd_test_id)
{
    using cpplib::is_odd;
    
    CHECK_FALSE(is_odd(T{0}));
    CHECK(is_odd(T{1}));
    CHECK_FALSE(is_odd(T{2}));
    CHECK(is_odd(T{3}));
    CHECK_FALSE(is_odd(T{4}));

    if constexpr (std::is_signed_v<T>)
    {
        CHECK(is_odd(T{-1}));
        CHECK_FALSE(is_odd(T{-2}));
        CHECK(is_odd(T{-3}));
        CHECK_FALSE(is_odd(T{-4}));
    }
}

TEST_CASE_TEMPLATE_APPLY(is_odd_test_id, int_test_types);