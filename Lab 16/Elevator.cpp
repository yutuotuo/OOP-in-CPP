// Lab 15
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cstdlib>
using std::abs;

#include <iomanip>
using std::setw;

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

#include "Elevator.h" // include Elevator definition from header file
#include "Floor.h"
#include "Rider.h"

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                constants              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// class-defined constants
int Elevator::elevatorID=0; // initialize to zero; use to assign unique ID to each elevator


////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
////@@@@@@@@@@@@@@@@@@@@@@                functions              @@@@@@@@@@@@@@@@@@@@@@@@@@@
////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// overloaded stream insertion friend function
ostream& operator<<(ostream& out, const Elevator& e) // location (inches above the ground), direction of movement (up, down, or idle), door status (open or closed)
{
  out << "Location: " << setw(4) << e.location << ", Direction: ";
  if (e.direction == 0) out << "IDLE,";
  else if (e.direction == 1) out << "UP,  ";
  else if (e.direction == -1) out << "DOWN,";

  out << " Door is currently ";
  e.doorOpen==true? out << "OPEN,   " : out << "CLOSED, ";

  out << "Occupancy: ";
  if (e.r.size() == 0) out << "empty.";
  else if (e.r.size() == 1) out << "1 rider.";
  else if (e.r.size() > 1) out << e.r.size() << " riders.";
  return out;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Definition             @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

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
    return (toFloor->getLocation() - location) <= speed? true : false;
  }
  else return (location - toFloor->getLocation()) <= speed? true : false;
}

void Elevator::moveToDestinationFloor() // set location to that of destination floor (if there is one)
{
  if(hasADestination()) location = toFloor->getLocation();
}

vector<Rider> Elevator::removeRidersForDestinationFloor() // remove riders from vector whose destination is reached
{
  vector<Rider> stay, leave;  // ... make 2 new vectors: stay & leave;

  for (int i=0; i<r.size(); i++) // Query each rider in vector "Do you leave here?"
  {
    if (toFloor == &(r[i].getDestination())) // if elevator's floor is rider's destination floor:
    {
      leave.push_back(r[i]);
    }
    else
    {
      stay.push_back(r[i]);
    }
  }

  r = stay; // update vector r so it's now the 'value' of 'stay'.
  return leave; // REMOVE the people being removed
}

void Elevator::addRiders(const vector<Rider>& source) // copy riders from parameter vector to riders vector
{
  for (int i = 0; i < source.size(); i++)
  {
    if (r.size() >= capacity) break; //1) skip if at capacity
    else r.push_back(source[i]); //2) if not at capacity, add riders.
  }
}

void Elevator::setDestinationBasedOnRiders() // reset toFloor based on riders' destinations
{
  if (hasRiders()==true)
  {
    setDestination(&(r[0].getDestination()));
  }
  for (int i=0; i<r.size(); i++) //1) Query each rider in vector
  {
    if ((abs(toFloor->getLocation() - location)) >
        (abs( r[i].getDestination().getLocation() - location)))
    {
      setDestination(&(r[i].getDestination()));
    }
  }
}
