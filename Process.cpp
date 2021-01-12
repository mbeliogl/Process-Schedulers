#include "Process.hpp"
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

//creates a basic process with a unique id given as parameter. Default constructor
Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}
//returns the Id of the process. Simple get/set functionality
int Process::getID() const
{
   return id;
}
//returns the CpuTime of the process. Similar simple functionality
int Process::getCPUTime() const
{
   return cpuTime;
}
//takes the number of cycles and returns the amount of time the process has waited for the CPU. Uses lastTime to "begin" the countdown. 
//additionalWait is reset if the if # of cycles minues lasTime is < 0 and added to waitTime (waitTIme + 0)
//otherwise it is added to the waitTime 
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}
//creates subclass instance
CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}
//this kind of process is never blocked so always return false
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}
//takes the #cycles and the sliceSize (time)
//returns sliceSize (how mych time was the process given )
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}
//creates subclass instance 
IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}
//could be blocked so checks wether the time when the process will unblock is larger than the number of cycles so far
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}
//takes the num of cycles and the slice of time allocated
//assigns a random length for the next cpu burst as soom as the process becomes unblocked (there is input from user)
//keeps track of the time since the last time the process ran
//keeps track of wether the whole window was used or not and adjusts the timeUsed accondingly. 
//returns the amount of time used by process in this run and also adds that time to total cpuTime
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = rand()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + rand()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
