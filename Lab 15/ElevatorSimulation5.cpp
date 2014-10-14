//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//#include <vector>
//using std::vector;
//
//#include "Floor.h"
//#include "Rider.h"
//#include "Elevator.h"
//#include "Building.h"

//
////To test your code, compile, build, and run with all previous ElevatorSimulation CPPs, and the following
//ElevatorSimulation4.cpp. Here's what it should do: (1) take 2 riders from the 1st floor to the
//2nd floor, then (2) take 5 riders from the 2nd floor to the basement, then (3) take 3 riders from
//the basement to the 2nd floor, and (4) end with 4 riders stranded on the 1st floor. All this should
//be a 5 inches per second movement of the elevator, without sudden jumps that might injure or kill its passengers:


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>

#include "Building.h"

int main()
{
  srand(time(0)); rand(); // requires cstdlib and ctime
  Building building;

  // add one rider per second for 10 seconds
  for (int i = 0; i < 10; i++)
    cout << building.step(1) << endl;

  // continue the simulation for 600 more seconds (expect all riders to be gone by then)
  for (int i = 0; i < 600; i++)
  {
    if (!(i % 10)) // pause every 10 seconds
    {
       cout << "Press ENTER to continue, X-ENTER to quit...\n";
      if (cin.get() > 31) break;
    }
    cout << building.step(0) << endl; // time-step with no riders added
  }
  cout << "DONE: All riders should be gone, and all elevators idle\n";
}


/*
Building myBuilding;

cout << "building called" << endl;

cout << endl << myBuilding << endl;
int elevatorCount = myBuilding.getElevatorCount();
cout << "elevatorCount = " << elevatorCount << endl;

myBuilding.step(10);
cout << "|||||||||||||   PAUSE 1   |||||||||||||||||||" << endl;
cin.get();

myBuilding.step(0);
cout << "|||||||||||||   PAUSE 2   |||||||||||||||||||" << endl;
cin.get();

myBuilding.step(0);
cout << "|||||||||||||   PAUSE 3   |||||||||||||||||||" << endl;
cin.get();

myBuilding.step(0);
cout << "|||||||||||||   PAUSE 4   |||||||||||||||||||" << endl;
cin.get();

myBuilding.step(0);
*/
