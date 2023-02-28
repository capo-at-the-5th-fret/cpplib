#include <doctest/doctest.h>

#include <string>
#include <string_view>
#include <unordered_map>
#include "cpplib/string.h"

TEST_CASE("string_hash")
{
    using std::string;
    using std::unordered_map;
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    unordered_map<string, size_t,
        cpplib::string_hash, std::equal_to<>> map{{"one"s, 1}};
    
    CHECK(map.find("one") != map.end());
    CHECK(map.find("one"s) != map.end());
    CHECK(map.find("one"sv) != map.end());
}
