#include "Scheduler.hpp"
#include "ArrayList.hpp"
#include <cstdlib>
#include <iostream>
#include "BSTForwardIterator.hpp"

using namespace std;

RoundRobin::RoundRobin(){
    procQueue = new ArrayList<Process*>();
}

RoundRobin::~RoundRobin(){
    delete procQueue;
}

void RoundRobin::addProcess(Process*proc){
    procQueue->pushFront(proc);

}


Process* RoundRobin::popNext(int curCycle){
    for(int i = 0; i < procQueue->getSize(); i ++)
    {
        if(procQueue->getItem(i)->isBlocked(curCycle) == true)
        {
            procQueue->pushBack(procQueue->getItem(i));
        }
        if(procQueue->getItem(i)->isBlocked(curCycle) == false)
        {
            procQueue->remove(i);
            return procQueue->getItem(i);
        }
    }
    return 0;
}

//COMPLETELY FAIR BEGIN

CompletelyFair::CompletelyFair(){
    procTree = new BSTMultimap<int, Process*>();

}

CompletelyFair::~CompletelyFair(){
    delete procTree;
}

void CompletelyFair::addProcess(Process* proc){
    procTree->insert(proc->getCPUTime(), proc);
}

Process* CompletelyFair::popNext(int curCycle){
    BSTForwardIterator<int, Process*> iter = procTree->getMin();
    
    while(iter.getValue()->isBlocked(curCycle) == true){
        iter.next();
    
    }
    
    procTree->remove(iter);
    return iter.getValue();
}


