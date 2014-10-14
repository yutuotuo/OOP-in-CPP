// Lab 15
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include "Floor.h"
#include "Rider.h" // include Rider definition from header file

#include <iostream>
using std::ostream;
      using std::endl; // TEMP
      using std::cout; // TEMP

#include <string>
using std::string;

#include <vector>
using std::vector;







//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Definition             @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Floor::Floor(const int loc, const char* const floorName) : location(loc), NAME(floorName) // name and location (inches above ground) of floor
{
  //empty body
  //cout << "TEMP: floor constructed, floorName = " << floorName<< "; NAME = " << NAME << endl;
}


bool Floor::isPreferredDirectionUp() const // based on Rider with smallest ID
{
  if (hasUpRiders())
  {
    Rider firstRider=upRiders[0];
    for (int i=0; i<upRiders.size(); i++)
    {
      if (upRiders[i]<firstRider) firstRider=upRiders[i];
    } // end for

    if (hasDownRiders())
    {
      for (int i=0; i<downRiders.size(); i++)
      {
        if (downRiders[i]<firstRider) return false; // return false if any downRider is < firstRider
      } // end for
    } // end if hasDownRiders
    return true; // returns true if firstRider is from upRiders list & < all downRiders
  } // end if hasUpRiders
  else return false; // returns false if there are no upRiders
} // end isPreferredDirectionUp


void Floor::addNewRider(const Rider& tempRider) // add to up- or down-vector
{
  int tempLocation = tempRider.getDestination().getLocation();  // compare Floor.location;
//cout << "   Floor data: tempLocation(floor) = " << location << "; rider's destination = " << tempLocation << endl;
//cout << "     tempRider.getDestination() = " << tempRider.getDestination() << endl;
//cout << "     tempRider.getDestination().getLocation() = " << tempRider.getDestination().getLocation() << endl;
  if (location < tempLocation) upRiders.push_back(tempRider);
  else  downRiders.push_back(tempRider);
} // end addNewRider


vector<Rider> Floor::removeUpRiders(int availableSpace) // int is max #of riders to move onto elevator
{
  vector<Rider> boardingRiders;
  int vecLoc=0;

  for (int i=0; i < availableSpace; i++)
  {
    if (!upRiders.empty())
    {
      boardingRiders.push_back(upRiders[0]);
      vecLoc=0;
      for (int j=0; j < upRiders.size(); j++)
      {
        if (upRiders[j]<boardingRiders[i])
        {
          boardingRiders[i] = upRiders[j];
          vecLoc = j; // upRider vector location for removal after smallest ID is found
        } // end if (ID comparison)
      } // end for (Rider comparison)
      upRiders.erase(upRiders.begin() + vecLoc);
    } // end if (not empty)
  } // end for (available space)

  return boardingRiders;
} // end removeUpRiders


vector<Rider> Floor::removeDownRiders(int availableSpace) // int is max #of riders to move onto elevator
{
  vector<Rider> boardingRiders;
  int vecLoc=0;


  for (int i=0; i < availableSpace; i++)
  {
    if (!downRiders.empty())
    {
      boardingRiders.push_back(downRiders[0]);
      vecLoc=0;
      for (int j=0; j < downRiders.size(); j++)
      {
        if (downRiders[j]<boardingRiders[i])
        {
          boardingRiders[i] = downRiders[j];
          vecLoc = j; // downRiders vector location for removal after smallest ID is found
        } // end if (ID comparison)
      } // end for (Rider comparison)
      downRiders.erase(downRiders.begin() + vecLoc);
    } // end if (not empty)
  } // end for (available space)

  return boardingRiders;
} // end removeDownRiders


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Operators              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ostream& operator<<(ostream& out, const Floor& f) // say name, location, #'s of up/down riders waiting
{
  out << f.NAME << ", Location: " << f.location << ", Riders up: "
      << f.upRiders.size() << ", Riders down: " << f.downRiders.size() << ".";
  return out;
}
