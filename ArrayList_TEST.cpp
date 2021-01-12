#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <ostream>
using namespace std;

#include "ArrayList.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"

TEST_CASE("TESTING ARRAYLIST Class"){

    SECTION("Testing Functions"){
       ArrayList<int> a;
       ArrayList<int> b(5);

       int item = 5;
       const int& five = item;
       int item1 = 1;
       const int& one = item1;

// back
    //    b.pushBack(five);
    //    b.pushBack(one);
    //    b.pushBack(five);
    //    b.popBack();
    //    b.popBack();
    //    b.popBack();
       
//front
       int item2 = 3;
       const int& three = item2;

       b.pushFront(5);
       b.pushFront(one);
       b.pushFront(five);
       b.pushFront(three);
       b.pushFront(one);
       b.pushFront(five);
       b.pushFront(three);
       b.pushFront(7);
       
       cout << "Item at index " << b.getItem(3) << endl;

       for(int i = 0; i < b.getSize(); i++){
           cout << b.getItem(i);
       }



       ArrayList<string> st; 
       string s = "hello";
       st.pushFront(s);
       REQUIRE(st.getFront() == "hello");
       //b.popFront();

       cout << st.getFront() << endl;

       cout << "size: " << b.getSize() << endl;
       cout << "isEmpty b: " << b.isEmpty() << endl;
       cout << "isEmpty a: " << a.isEmpty() << endl;
       cout << "a capacity: " << a.getCapacity() << endl;
       cout << "b capacity: " << b.getCapacity() << endl; // how to get the capacity? memebr and parameter have the same name...
       //cout << "idx item: " << b.getItem(1) << endl; // --- does not work properly with index > 0
       cout << "first item: " << b.getFront() << endl;
       cout << "getBack " << b.getBack() << endl;

       b.setItem(0, one);
       cout << "first after set: " << b.getFront() << endl;

       ArrayList<Process*> arr;
       Process* p;
       CPUBoundProcess p1(0);
       p = &p1;        //make array a list of process*... push process* into it.
       arr.pushFront(p);
       //cout << "item at 0: " << arr.getItem(0) << endl;  
       REQUIRE(arr.getItem(0)->getID() == 0);

}
}
