#include "Simulate.hpp"
#include "Process.hpp"
#include "Scheduler.hpp"
#include <iostream>

using namespace std; 

int main(int argc, char** argv){
    int numIOBound = atoi(argv[1]);
    int numCPUBound = atoi(argv[2]);
    int numCycles = atoi(argv[3]);

    cout << endl <<"***** RoundRobin Scheduler: *****" << endl;
    cout << endl;

    RoundRobin* r = new RoundRobin(); 
    double* arr = new double[5];
    arr = simulate(r, numCPUBound, numIOBound, numCycles);

    cout << "Overhead: " << arr[0] << endl;
    cout << "Average CPU Time: " << arr[1] << endl;
    cout << "Average CPU Wait time: " << arr[2] << endl;
    cout << "Average IO Time: " << arr[3] << endl;
    cout << "Average IO Wait Time: " << arr[4] << endl;

    cout << endl <<"***** CompletelyFair Scheduler: ***** " << endl;
    cout << endl;
    
    CompletelyFair* c = new CompletelyFair();
    double* arr1 = new double[5];
    arr1 = simulate(c, numCPUBound, numIOBound, numCycles);
    
    cout << "Overhead: " << arr[0] << endl;
    cout << "Average CPU Time: " << arr[1] << endl;
    cout << "Average CPU Wait time: " << arr[2] << endl;
    cout << "Average IO Time: " << arr[3] << endl;
    cout << "Average IO Wait Time: " << arr[4] << endl;



}
