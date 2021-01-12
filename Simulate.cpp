#include <chrono>
#include "Scheduler.hpp"
#include <cstdlib>
#include <iostream>
#include "ArrayList.hpp"

using namespace std;

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles){
    
    ArrayList<Process*>* list = new ArrayList<Process*>;
    //CREATE AND ALLOCATE CPU BOUND PROCESSES
    for(int i = 0; i < numCPUBound; i++){
        CPUBoundProcess* cp;
        cp = new CPUBoundProcess(i);
        sched->addProcess(cp);
        list->pushFront(cp);
        cout << "Pushed: " << cp << endl;
    }

    for(int i = 0; i<numIOBound; i++){
        IOBoundProcess* ip;
        ip = new IOBoundProcess(i);
        sched->addProcess(ip);
        list->pushFront(ip);
        cout << "Pushed: " << ip << endl;
    }

    int cpuTime = 0;
    int IOBoundTime = 0;
    int cputWaitTime = 0;
    int IOWaitTime = 0;
    int count = 0;

    int cycleNum = 0;
    while(cycleNum <= numCycles){
        Process* next = sched->popNext(cycleNum);
        if(next == 0){
            cycleNum += 10;
        }
        else{
            cycleNum += next->useCPU(cycleNum, 10);
            sched->addProcess(next);
            count += 1;
        }

    }
    while(list->isEmpty() == false){
        Process* next = list->getFront();
        cout << "Popped: " << next << endl;
        if(dynamic_cast<CPUBoundProcess*>(next)){
            cpuTime += next->getCPUTime();
            cputWaitTime += next -> getWaitTime(cycleNum);
        }
        else{
            IOBoundTime += next->getCPUTime();
            IOWaitTime += next -> getWaitTime(cycleNum);
        }
        list->popFront();
    }
    auto t1 = std::chrono::system_clock::now();
    auto t2 = std::chrono::system_clock::now();
    auto dur = t1-t2;
    auto durns = std::chrono::duration_cast<std::chrono::nanoseconds>(dur);
    double elapsed = durns.count();
    double t = elapsed/count;

    double* arr = new double[5];

    arr[0] = t;
    arr[1] = cpuTime/numCPUBound;
    arr[2] = cputWaitTime/numCPUBound;
    arr[3] = IOBoundTime/numIOBound;
    arr[4] = IOWaitTime/numIOBound;
    return arr;

}
