#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <ostream>
using namespace std;
#include "Scheduler.hpp"
#include "Process.hpp"

TEST_CASE("TESTING ROUNDROBIN"){
    SECTION("BLANK"){
        RoundRobin r;
        Process* p;
        IOBoundProcess* i;
        r.addProcess(p);
        r.addProcess(i);


    }
}