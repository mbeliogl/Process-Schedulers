#ifndef SIMULATE_H 
#define SIMULATE_H

#include <chrono>
#include "Scheduler.hpp"


double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles);


#endif

