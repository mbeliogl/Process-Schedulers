#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTMultimap.hpp"
#include "BSTForwardIterator.hpp"
#include <iostream>

TEST_CASE("Testing BSTForwardIterator")
{
    SECTION("Testing constructor"){
        BSTNode<int, int>* node;
        BSTNode<int, int> node1(0, 10);
        node = &node1;
        BSTForwardIterator<int, int> iter(node, 0);
    }
    
    SECTION("Testing next method"){
        BSTMultimap<int, int> x;
        x.insert(4, 10);
        x.insert(5, 20);
        x.insert(2, 20);
        BSTForwardIterator<int, int> min = x.getMin();
        
        min.next();
        REQUIRE(min.getKey() == 4);
        min.next();
        REQUIRE(min.getKey() == 5);
    }
}