// Lab 15
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Rider.h"

//Note that the H file will require the compiler directives, declarations, and includes, which you must determine.

class Floor
{
  const int location; // inches above ground level
  const string NAME; // name of floor, for example: Mezzanine
  vector<Rider> upRiders; // affected by: addNewRider, removeUpRiders, removeDownRiders
  vector<Rider> downRiders; // affected by: addNewRider, removeUpRiders, removeDownRiders

public:
  Floor(const int, const char* const = "unnamed"); // name and location (inches above ground) of floor

  // inline functions
  int getLocation() const {return location;}
  bool hasRidersWaiting() const {return !upRiders.empty()?true : (!downRiders.empty()? true: false);}
  bool hasUpRiders() const{return !upRiders.empty()? true: false;}
  bool hasDownRiders() const{return !downRiders.empty()? true: false;}
  int getUpRiderCount() const{return upRiders.size();}
  int getDownRiderCount() const{return downRiders.size();}
  string getName() const{return NAME;}

  // non-inline functions
  bool isPreferredDirectionUp() const; // based on Rider with smallest ID
  void addNewRider(const Rider&); // add to up- or down-vector
  vector<Rider> removeUpRiders(int); // int is max #of riders...
  vector<Rider> removeDownRiders(int); //...to move onto elevator

  // just in case you prefer to use "if (...== *toFloor)" in Elevator::removeRidersForDestinationFloor(), instead of "...== toFloor)"
  bool operator==(const Floor& floor) const{return NAME == floor.NAME;}

  // friend function
  friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};


#endif // FLOOR_H
