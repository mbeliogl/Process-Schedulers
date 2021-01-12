#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <ostream>
#include "BSTNode.hpp"
#include "BSTMultimap.hpp"

using namespace std;

TEST_CASE("TESTING BSTMULTIMAP"){

    SECTION("Testing BSTMULTIMAP CONSTRUCTOR/FUNCTIONS"){
        BSTMultimap<int, int> m;
        m.insert(4,5);
        m.insert(3,4);
        m.insert(2,7);
        m.insert(20,2);
        m.insert(2,6);
        m.insert(5,10);
        m.insert(10,11);
        cout << "Size: " << m.getSize() << endl; //works
        cout << "Empty? " << m.isEmpty() << endl; //works
        cout << m.contains(8) << endl; //works

        BSTForwardIterator<int, int> iter1 = m.getMax(); // works
        cout << "MAX: " << iter1.getKey() << endl;


        BSTForwardIterator<int, int> iter2 = m.getMin(); 
        cout << "MIN: " << iter2.getKey() << endl;

        BSTForwardIterator<int, int> iter3 = m.findFirst(2); 
        cout << "FIRST: " << iter3.getValue() << endl;

        // BSTForwardIterator<int, int> iter4 = m.findLast(5); 
        // cout << "LAST: " << iter4.getValue() << endl;


    }
}