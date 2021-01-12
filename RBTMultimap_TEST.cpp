#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <ostream>
#include "BSTNode.hpp"
#include "BSTMultimap.hpp"
#include "RBTNode.hpp"
#include "RBTMultimap.hpp"
using namespace std;

TEST_CASE("TESTING BSTMULTIMAP"){

    SECTION("Testing BSTMULTIMAP CONSTRUCTOR/FUNCTIONS"){
        RBTMultimap <int, int> m;
        m.insert(1,9);
        m.insert(2,7);
        cout << "Size: " << m.getSize() << endl;
        cout << "Empty? " << m.isEmpty() << endl;
        cout << m.contains(2) << endl;
        m.printDOT("test.txt");
    }

}