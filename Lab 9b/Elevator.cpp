// Lab 9b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iomanip>
using std::setw;

#include <iostream>
using std::ostream;

#include "Elevator.h" // include Elevator definition from header file
#include "Floor.h"

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                constants              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//// class-defined constants
int Elevator::elevatorID=0; // initialize to zero; use to assign unique ID to each elevator


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                functions              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// overloaded stream insertion friend function
ostream& operator<<(ostream& out, const Elevator& e) // location (inches above the ground), direction of movement (up, down, or idle), door status (open or closed)
{
  out << "Location: " << setw(4) << e.location
  << ",  Direction: ";
  if (e.direction == 0) out << "IDLE";
    else if (e.direction == 1) out << "UP  ";
    else if (e.direction == -1) out << "DOWN";

  out << ",  Door is currently ";
  e.doorOpen==true? out << "OPEN.  " : out << "CLOSED.";
  return out;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Definition             @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// OLD --> Rider::Rider(const Floor& floor) : riderID(UNIQUE_ID), destinationFloor(&floor)

Elevator::Elevator(const int cap, const int spd, const Floor& startFloor)
        : ID(Elevator::elevatorID), capacity(cap), speed(spd), toFloor(0)
{
  elevatorID++;
  location = startFloor.getLocation();
  direction = IDLE;
  doorOpen = true;
}

    // non-inline functions
bool Elevator::isNearDestination() const // true if distance to destination is less than or equal to the speed
{
  if (direction == UP)
  {
    return (toFloor->getLocation() - location) <= speed? true : false; // might need toFloor.getLocation()
  }
  else if (direction == DOWN)
  {
    return (location - toFloor->getLocation()) <= speed? true : false;
  }
}

void Elevator::moveToDestinationFloor() // set location to that of destination floor (if there is one)
{
  if(hasADestination()) location = toFloor->getLocation();
}
