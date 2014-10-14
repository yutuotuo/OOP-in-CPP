// Lab 16
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

//#include "Floor.h"
//#include "Rider.h"
//#include "Elevator.h"
//#include "Building.h"

#include <cmath>

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Building.h"


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                function               @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int getArrivalsForThisSecond(double averageRiderArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageRiderArrivalRate); // for n=0 -- requires cmath
  for(double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib AND srand in main
      (randomValue -= probOfnArrivals) > 0.0;
      probOfnArrivals *= averageRiderArrivalRate / ++arrivals);
  return arrivals;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  main                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: ElevatorSimulation6 is designed to create a state of equilibrium" << endl;
  cout << "in a building object with floors and elevators of my design, using a step" << endl;
  cout << "function that adds riders at a random rate (where the average is defined by me)." << endl;
  cout << "-----------------------------------------------------------------------------\n" << endl;

  srand(time(0)); rand(); // requires cstdlib and ctime
  Building building;

  int simStep = 1;
  char userInput = 'a';
  bool userQuit = false;

  while (userQuit == false)// condition for do (building) to continue
  {
    cout << building.step(getArrivalsForThisSecond(0.21)) << endl;// add getArrivalsForThisSecond(#) riders per second

    simStep --;
    if (simStep < 1)
    {
      cout << endl << "      Enter next simulation step size:\n      (\"S\"econd, \"M\"inute, \"T\"hirty minutes, \"H\"our, or \"Q\"uit, or ENTER for default): ";
      cin.get(userInput);
      switch(userInput)
      {
      case 'S': simStep = 1; cin.ignore(); cout << endl; break;       // S = 83
      case 's': simStep = 1; cin.ignore(); cout << endl; break;      // s = 115
      case 'M': simStep = 60; cin.ignore(); cout << endl; break;      // M = 77
      case 'm': simStep = 60; cin.ignore(); cout << endl; break;     // m = 109
      case 'T': simStep = 1800; cin.ignore(); cout << endl; break;     // T = 84
      case 't': simStep = 1800; cin.ignore(); cout << endl; break;     // t = 116
      case 'H': simStep = 3600; cin.ignore(); cout << endl; break;    // H = 72
      case 'h': simStep = 3600; cin.ignore(); cout << endl; break;   // h = 104
      case 'Q': userQuit = true; cin.ignore(); cout << endl; break;   // Q = 81
      case 'q': userQuit = true; cin.ignore(); cout << endl; break;  // q = 113
      default: simStep = 10; cout << endl; break;
            } //End switch()
    } // end if (simStep < 1)
  } // end while loop

  cout << endl << "FINAL BUILDING STATE: " << endl;
  cout << building << endl;
} // end main
