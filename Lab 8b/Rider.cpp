// Lab 8b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include "Floor.h" // include Floor definition from header file
#include "Rider.h" // include Rider definition from header file

static int UNIQUE_ID = 0; // track and assign ID #s


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Definition             @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Rider::Rider(const Floor& floor) : riderID(UNIQUE_ID), destinationFloor(&floor)
{
  UNIQUE_ID++;
}

Rider::Rider(const Rider& riderToCopy) : riderID(riderToCopy.riderID), destinationFloor(riderToCopy.destinationFloor) // copy constructor
{
  // empty body - all members defined upon initialization.
}

Floor& Rider::getDestination() const
{
  return (Floor&)*destinationFloor;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Operators              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

bool Rider::operator< (const Rider& riderBeingCompared) const
{
  return riderID < riderBeingCompared.riderID?true:false; // combined function?????????
} // end function operator<

bool Rider::operator== (const Rider& riderBeingCompared) const
{
  return riderID == riderBeingCompared.riderID?true:false; // combined function?????????
} // end function operator==
