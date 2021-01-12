#ifndef Scheduler_H
#define Scheduler_H

#include "Process.hpp"
#include "List.hpp"
#include "LinkedList.hpp"
#include "BSTMultimap.hpp"

class Scheduler{

    public:

    virtual void addProcess(Process* proc) = 0;
    virtual Process* popNext(int curCycle) = 0;

    virtual ~Scheduler() { }

};

class RoundRobin : public Scheduler{

    protected:
        List<Process*>* procQueue;
    
    public:
        RoundRobin();
        virtual ~RoundRobin();
        virtual void addProcess(Process* proc);
        virtual Process* popNext(int curCycle);

};

class CompletelyFair : public Scheduler{

    protected:
        BSTMultimap<int, Process*>* procTree;

    public:
        CompletelyFair();
        virtual ~CompletelyFair();
        virtual void addProcess(Process* proc);
        Process* popNext(int curCycle);

};

#endif