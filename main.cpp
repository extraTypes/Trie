#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <trie.hpp>

using namespace std;
using namespace T;

TEST_CASE("Test abstract node constructor"){
    AbstractNode n {5};
    REQUIRE(any_cast<int>(n.getVal()) == 5);
}