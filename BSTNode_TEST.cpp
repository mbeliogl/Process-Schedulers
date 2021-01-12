#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <ostream>
#include "BSTNode.hpp"
using namespace std;

TEST_CASE("TESTING BSTNODE"){

    SECTION("Testing BSTNODE CONSTRUCTOR/FUNCTIONS"){
       BSTNode<int, int> n(9,3);
       
       REQUIRE(n.getKey() == 9);
       REQUIRE(n.getValue() == 3);

       const int& tk = 10;
       const int& tv = 7;
       n.setKey(tk);
       n.setValue(tv);

       REQUIRE(n.getKey() == 10);
       REQUIRE(n.getValue() == 7);

       BSTNode<int, int>* p;
       BSTNode<int, int> q(5,1);
       p = &q;
       n.setParent(p);
       
       REQUIRE(n.getParent()->getKey() == 5);
       REQUIRE(n.getParent()->getValue() == 1);
       
    }
}