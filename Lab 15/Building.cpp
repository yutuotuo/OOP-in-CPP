// Lab 15
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cstdlib>
using std::rand;
using std::srand; // seed
using std::abs; // CHECK

#include <ctime>       /* time */

#include <cassert>

#include <cstdlib>
using std::abs;

#include <iomanip>
using std::setw;

#include <iostream>
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include "Building.h"
#include "Elevator.h"
#include "Floor.h"
#include "Rider.h"



////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
////@@@@@@@@@@@@@@@@@@@@@@                functions              @@@@@@@@@@@@@@@@@@@@@@@@@@@
////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// friend function
ostream& operator<<(ostream& out, const Building& b) // time, then elevators, then floors
{
  out << "Building conditions at " << b.simulationTime << " seconds:" << endl; // time

  for (int i=0; i < b.buildingElevators.size(); i++) // elevators
  {
    out << "  " << *b.buildingElevators[i] << endl; // # riders, direction, door status.
  } // end for (elevators)

  for (int i=0; i < b.buildingFloors.size(); i++)
  {
    if (b.buildingFloors[i]->hasRidersWaiting() == true) // CHECK!!! Should be TRUE?!?!?
    {
      out << "  " << *b.buildingFloors[i] << endl; // name, # up-, # down-riders
    }
  } // end for (floors)

  return out;
} // end ostream& operator<<


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Definition             @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Building::Building(): simulationTime(0) // default constructor
{
  // create 7 floors
  buildingFloors.push_back(new Floor(-120, "Basement"));
  buildingFloors.push_back(new Floor(0, "Ground Floor"));
  buildingFloors.push_back(new Floor(120, "Second Floor"));
  buildingFloors.push_back(new Floor(240, "Third Floor"));
  buildingFloors.push_back(new Floor(360, "Fourth Floor"));
  buildingFloors.push_back(new Floor(480, "Fifth Floor"));
  buildingFloors.push_back(new Floor(600, "Sixth Floor"));

  buildingElevators.push_back(new Elevator(2, 22, *buildingFloors[1])); //
  buildingElevators.push_back(new Elevator(5, 14, *buildingFloors[6]));
  buildingElevators.push_back(new Elevator(8, 6, *buildingFloors[0]));
} // end default constructor

Building::~Building()
{
  for (int i=0; i<buildingFloors.size(); i++)
  {
    delete buildingFloors[i];
  }
  for (int i=0; i<buildingElevators.size(); i++)
  {
    delete buildingElevators[i];
  }
} // end destructor

Building& Building::step(int numRiders) // moves elevators and riders each second. numRiders = riders to randomly add to floors
{
  int count = 0; // screen counter for pausing.

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@                 Riders                @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int i=0; i < numRiders; i++) // add riders on random floors
  {
    int randomStartFloor = rand() % buildingFloors.size(); // random number from 0 to buildingFloors max
    int randomDestinationFloor = rand() % buildingFloors.size(); // random number from 0 to buildingFloors max

    if (randomStartFloor == 0) // Basement case - no down
    {
      //cout << "           ADDING rider to basement" << endl;
      randomDestinationFloor = rand() % (buildingFloors.size()-1) + 1; // random number from 1 to (buildingFloors max -1)
      //randomDestinationFloor = buildingFloors[randomDestinationFloor]->getLocation();
    }
    else if (randomStartFloor == buildingFloors.size()) // Top case - no up
    {
      //cout << "           ADDING rider to top" << endl;
      randomDestinationFloor = rand() % (buildingFloors.size()-1); // random number from 0 to (buildingFloors max -1)
      //randomDestinationFloor = buildingFloors[randomDestinationFloor]->getLocation();
    }
    else
    {
      while (randomDestinationFloor == randomStartFloor) // make sure starting != destination floor
      {
        randomDestinationFloor = rand() % buildingFloors.size();
      }
      //cout << "           ADDING rider to other floor" << endl;
      //randomDestinationFloor = buildingFloors[randomDestinationFloor]->getLocation();
    }
    buildingFloors[randomStartFloor]->addNewRider(Rider(*buildingFloors[randomDestinationFloor])); // add rider on rand floor w/ rand dest.
  } // end for (adding riders to random floors)


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@                 Floor                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int i = 0; i<buildingFloors.size(); i++) // checking floor by floor
  {
    if (buildingFloors[i]->hasRidersWaiting() == true) // floor has riders waiting
    {
      for (int j = 0; j<buildingElevators.size(); j++) // checking all elevators for isIdle()
      {
        if (buildingElevators[j]->isIdle() == true) // if there is an idle elevator
        {
          if ( (buildingElevators[j]->getLocation()) > (buildingFloors[i]->getLocation()) ) // if elevator's height > floor's height
          {
            buildingElevators[j]->setDirectionDown();
            buildingElevators[j]->setDestination(buildingFloors[i]);
            buildingElevators[j]->closeDoor();
          } // end if elevator height > floor height
          else if ( (buildingElevators[j]->getLocation()) < (buildingFloors[i]->getLocation()) ) // if elevator's height < floor's height
          {
            buildingElevators[j]->setDirectionUp();
            buildingElevators[j]->setDestination(buildingFloors[i]);
            buildingElevators[j]->closeDoor();
          } // end if elevator height < floor height
        } // end if elevator.isIdle()


        else if (buildingFloors[i]->hasUpRiders() == true && buildingElevators[j]->isDirectionUp() == true) //there are riders on this floor waiting to go up, and the elevator is going up... [10]
        {
          int elevatorDistance = (buildingElevators[j]->getDestination().getLocation() -
                                  buildingFloors[i]->getLocation());
          //get distance from elevator's destination floor to this floor (positive if elevator destination is above this floor) [10]

          if ((buildingElevators[j]->getLocation()) < (buildingFloors[i]->getLocation()) && (elevatorDistance > 0)) //elevator is below floor and elevator destination is above this floor [10]
          {
            buildingElevators[j]->setDestination(buildingFloors[i]); //set elevator's destination to this floor [10]
          } // end if (elevator is moving up past this floor)
        } // end else (riders on floor going up AND elevator going up)
        else if (buildingFloors[i]->hasDownRiders() == true && buildingElevators[j]->isDirectionDown() == true)//there are riders on this floor waiting to go down, and the elevator is going down... [10]
        {
          //get distance from elevator's destination floor to this floor (negative if elevator destination is below this floor) [10]
          int elevatorDistance = (buildingElevators[j]->getDestination().getLocation() -
                                  buildingFloors[i]->getLocation());

          if ((buildingElevators[j]->getLocation()) > (buildingFloors[i]->getLocation()) && (elevatorDistance < 0)) //elevator is above floor and elevator destination is below this floor [10]
          {
            buildingElevators[j]->setDestination(buildingFloors[i]); //set elevator's destination to this floor [10]
          } // end if (elevator is moving down past this floor)
        } // end else (riders on floor going down AND elevator going down)
      } // end for loop checking all elevators
    } // end if Floor has riders waiting loop
  } // end for loop for checking all Floors


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@                Elevator               @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int i = 0; i<buildingElevators.size(); i++) // checking all elevators for closed doors
  {
    if (buildingElevators[i]->isDoorOpen() == false) // if doors are closed
    {
      if (!buildingElevators[i]->isNearDestination()) // executed if elevator is not near destination
      {
        if (buildingElevators[i]->isDirectionUp()) buildingElevators[i]->moveUp();
        else if (buildingElevators[i]->isDirectionDown()) buildingElevators[i]->moveDown();
      } // end 'if not near destination' loop
      else if (buildingElevators[i]->isNearDestination()) // if elevator is near to destination
      {
        buildingElevators[i]->moveToDestinationFloor();
        buildingElevators[i]->openDoor();
        buildingElevators[i]->removeRidersForDestinationFloor();// remove riders; ignore returned vector of removed riders

        Floor* elevatorsCurrentFloor = const_cast<Floor*>(&(buildingElevators[i]->getDestination())); // CHECK HERE!

        if (buildingElevators[i]->hasRiders() == false) // if elevator is empty
        {
          if (elevatorsCurrentFloor->isPreferredDirectionUp() == true) // go through up riders
          {
            buildingElevators[i]->setDirectionUp();
          }
          else
          {
            buildingElevators[i]->setDirectionDown();
          }
        } // end if elevator = empty


        // LET OFF RIDERS first!?!?
        int elevatorSpace = buildingElevators[i]->getAvailableSpace();
        //vector<Rider> ridersLeavingElevator = elevatorsCurrentFloor->removeUpRiders(elevatorSpace);
        buildingElevators[i]->removeRidersForDestinationFloor(); // ignore returned vector // remove riders for basement, add waiting riders, and go to 2nd floor

        if (elevatorSpace!=0) // if space in elevator, board riders
        {
          if (buildingElevators[i]->isDirectionUp() == true) // if the elevator is going up
          {
            if (elevatorsCurrentFloor->hasUpRiders() == true) // if there are up riders on the floor
            {
              buildingElevators[i]->addRiders(elevatorsCurrentFloor->removeUpRiders(elevatorSpace)); // CHECK
            } // end if (has up riders)
          } // end if elevator=up
          else // for down elevators
          {
            if (elevatorsCurrentFloor->hasDownRiders() == true) // if there are down riders on the floor
            {
              buildingElevators[i]->addRiders(elevatorsCurrentFloor->removeDownRiders(elevatorSpace));
            } // end if (has down riders)
          } // end else (for down riders)
        } // end if space in elevator

        buildingElevators[i]->setDestinationBasedOnRiders();
      } // end if 'near destination' loop

      else // otherwise (then it already let off riders, or is in its initial state) [7]
      {
        if (buildingElevators[i]->hasRiders() == true) // has riders
        {
          buildingElevators[i]->closeDoor();
        } // end if has riders
        else
        {
          buildingElevators[i]->setIdle();
        }
      } // else (for already let off riders or is in initial state.
    } // end 'if elevator doors are closed' loop
  } // end for loop checking all elevators





  simulationTime ++;
  return *this; // should return a reference to itself. CHECK
}
