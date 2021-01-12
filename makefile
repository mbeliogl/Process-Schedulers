OPTS := -Wall -std=c++11 


tests: ArrayList_TEST BSTMultimap_TEST BSTNode_TEST

all: ArrayList_TEST RoundRobin_TEST BSTNode_TEST BSTNode.o BSTMultimap_TEST  Scheduler.o Process.o LinkedList_TEST RBTMultimap_TEST BSTNode_TEST RBTNode_TEST schedulesim CompletelyFair_TEST

ArrayList_TEST: ArrayList_TEST.cpp catch.hpp ArrayList.hpp
	g++ ${OPTS} -o ArrayList_TEST ArrayList_TEST.cpp Process.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp catch.hpp Scheduler.hpp Scheduler.o Process.o
	g++ ${OPS} -o RoundRobin_TEST RoundRobin_TEST.cpp Process.cpp Scheduler.cpp

BSTNode_TEST: BSTNode.tpp BSTNode.hpp catch.hpp 
	g++ ${OPTS} -o BSTNode_TEST BSTNode_TEST.cpp

BSTNode.o: BSTNode.tpp BSTNode.hpp
	g++ ${OPTS} -c BSTNode.tpp

BSTMultimap_TEST: BSTNode.hpp BSTForwardIterator.hpp BSTMultimap.tpp BSTMultimap.hpp catch.hpp
	g++ ${OPTS} -o BSTMultimap_TEST BSTMultimap_TEST.cpp

Scheduler.o: Scheduler.cpp Scheduler.hpp
	g++ ${OPTS} -c Scheduler.cpp

Process.o: Process.hpp Process.hpp
	g++ ${OPTS} -c Process.cpp

LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp LinkedListNode.hpp catch.hpp
	g++ ${OPTS} -o LinkedList_TEST LinkedList_TEST.cpp

RBTMultimap_TEST: RBTMultimap_TEST.cpp BSTMultimap.tpp RBTNode.hpp BSTForwardIterator.hpp catch.hpp
	g++ ${OPTS} -o RBTMultimap_TEST RBTMultimap_TEST.cpp

BSTNode_TEST: BSTNode_TEST.cpp catch.hpp
	g++ ${OPTS} -o BSTNode_TEST BSTNode_TEST.cpp

RBTNode_TEST: RBTNode_TEST.cpp BSTNode.hpp catch.hpp
	g++ ${OPTS} -o RBTNode_TEST RBTNode_TEST.cpp

schedulesim: schedulesim.cpp Process.hpp simulate.hpp Scheduler.hpp catch.hpp
	g++ ${OPTS} schedulesim.cpp Process.cpp simulate.cpp Scheduler.cpp -std=c++11

CompletelyFair_TEST: CompletelyFair_TEST.cpp catch.hpp Scheduler.hpp
	g++ ${OPTS} -o CompletelyFair_TEST CompletelyFair_TEST.cpp Process.cpp Scheduler.cpp


clean: 
	rm *.o
