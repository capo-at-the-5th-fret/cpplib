#include <iostream>
#include <concepts>

namespace cpplib
{
    constexpr bool is_even(std::integral auto t)
    {
        return (t % 2) == 0;
    }

    constexpr bool is_odd(std::integral auto t)
    {
        return (t % 2) != 0;
    }

    constexpr bool evenly_divisible(std::integral auto t, std::integral auto u)
    {
        return (t % u) == 0;
    }
}
