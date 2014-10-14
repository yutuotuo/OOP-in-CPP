// Lab 15
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

class Floor; // forward declaration, only uses * and &
class Elevator; // forward declaration, only uses * and &


class Building
{
private:
  int simulationTime;
  vector<Floor*> buildingFloors; // a vector of Floor*s
  vector<Elevator*> buildingElevators; // a vector of Elevator*s

public:
  Building(); // default constructor;
  ~Building();        // destructor

  Building& step(int); // moves elevators and riders each second

  int getFloorCount() const {return buildingFloors.size();}// return #of floors in the vector of Floor*'s
  int getElevatorCount() const {return buildingElevators.size();}// return #of elevators in the vector of Elevator*'s
  const Floor& getFloor(int index) const {return *buildingFloors[index];}// return a reference to the "indexth" floor
  const Elevator& getElevator(int index) const {return *buildingElevators[index];}// return a reference to the "indexth" elevator

  // friend function
  friend ostream& operator<<(ostream&, const Building&); // overloaded operator<< friend function
}; // end class Building

#endif // BUILDING_H_INCLUDED
