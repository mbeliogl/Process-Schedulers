Scheduler Simulator 
--- 

---

The program uses various data structures to implement 2 different Process Schedulers. First utilizes an <ArrayList> to implement the *RoundRobin* Scheduler for *CPUBound* and *IOBound* Processes. Second Utilizes a <Binary Search Tree> to perform the same tasks. The use of various data structures and algorithms associated with them allows us to compare how these implementations differ in their efficiency in real time. 

---

#### ----Schedulesim----

	To compile: make all 
	To run: ./a.out <number of IOBound Processes> <number of CPUBound Processes> <number of 	 							desired cycles>

Description: The program simulates a scheduling load and outputs efficiency characteristics for each scheduler. 

The information includes:

1. CPU Overhead Average 
2. CPU Wait Time
3. Average CPU Time
4. Average IO Time
5. Average IO Wait Time.

---