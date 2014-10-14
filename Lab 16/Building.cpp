// Lab 15
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cstdlib>
using std::rand;
using std::srand; // seed
using std::abs;

#include <ctime>

#include <iostream>
using std::endl;
using std::ostream;
using std::cout; // TEMP

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
  out << "    Building conditions at second " << b.simulationTime << ":" << endl; // time

  for (int i=0; i < b.buildingElevators.size(); i++) // elevators
  {
    out << "Elevator " << i+1 << " " << *b.buildingElevators[i] << endl; // # riders, direction, door status.
  } // end for (elevators)

  for (int i=0; i < b.buildingFloors.size(); i++) // floors
  {
    if (b.buildingFloors[i]->hasRidersWaiting() == true) // only display floors with riders
    {
      out << *b.buildingFloors[i] << endl; // name, # up-, # down-riders
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

  // create 3 elevators
  buildingElevators.push_back(new Elevator(2, 22, *buildingFloors[1]));
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


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@             step() function           @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

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
      randomDestinationFloor = rand() % (buildingFloors.size()-1) + 1; // random number from 1 to (buildingFloors max -1)
    }
    else if (randomStartFloor == buildingFloors.size()) // Top case - no up
    {
      randomDestinationFloor = rand() % (buildingFloors.size()-1); // random number from 0 to (buildingFloors max -1)
    }
    else
    {
      while (randomDestinationFloor == randomStartFloor) // make sure starting != destination floor
      {
        randomDestinationFloor = rand() % buildingFloors.size();
      }
    }
    buildingFloors[randomStartFloor]->addNewRider(Rider(*buildingFloors[randomDestinationFloor])); // add rider on rand floor w/ rand dest.
  } // end for (adding riders to random floors)


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@                Elevator               @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int i = 0; i<buildingElevators.size(); i++) // checking all elevators one by one [3]
  {
    if (buildingElevators[i]->isDoorOpen() == false) // if doors are closed [3]
    {
      if (!buildingElevators[i]->isNearDestination()) // executed if elevator is not near destination [3]
      {
        if (buildingElevators[i]->isDirectionUp()) buildingElevators[i]->moveUp(); // move up [3]
        else if (buildingElevators[i]->isDirectionDown()) buildingElevators[i]->moveDown(); // move down [3]
      } // end 'if not near destination' loop

      else if (buildingElevators[i]->isNearDestination()) // if elevator is near to destination [4]
      {
        buildingElevators[i]->moveToDestinationFloor(); // [4]
        buildingElevators[i]->openDoor(); // [4]
        {
          buildingElevators[i]->removeRidersForDestinationFloor();// remove riders; ignore returned vector of removed riders [4]
        } // "{}" & cout are temp

        Floor* elevatorsCurrentFloor = const_cast<Floor*>(&(buildingElevators[i]->getDestination())); // [5]

        if (buildingElevators[i]->hasRiders() == false) // if elevator is empty [5]
        {
          if (elevatorsCurrentFloor->isPreferredDirectionUp() == true) // if floor direction = up [5]
          {
            buildingElevators[i]->setDirectionUp();
          }
          else // if floor direction != up [5]
          {
            buildingElevators[i]->setDirectionDown();
          }
        } // end if elevator = empty

        if (buildingElevators[i]->getAvailableSpace()!=0) // if space in elevator, board riders [6]
        {
          if (buildingElevators[i]->isDirectionUp() == true) // if the elevator is going up
          {
            if (elevatorsCurrentFloor->hasUpRiders() == true) // if there are up riders on the floor
            {
              buildingElevators[i]->addRiders(elevatorsCurrentFloor->removeUpRiders(buildingElevators[i]->getAvailableSpace())); // board up-riders [6]
            } // end if (has up riders)
          } // end if elevator direction == up
          else // for down elevators
          {
            if (elevatorsCurrentFloor->hasDownRiders() == true) // if there are down riders on the floor
            {
              buildingElevators[i]->addRiders(elevatorsCurrentFloor->removeDownRiders(buildingElevators[i]->getAvailableSpace()));// board down-riders [6]
            } // end if (has down riders)
          } // end else (for down riders)
        } // end if space in elevator

        buildingElevators[i]->setDestinationBasedOnRiders(); //reassess elevator's destination based on riders [8]
      } // end if 'near destination' loop
    } // end 'if elevator doors are closed' loop


    else // "isDoorOpen() == true" (it already let off riders, or is in its initial state) [7]
    {
      if (buildingElevators[i]->hasRiders() == true) // has riders [7]
      {
        buildingElevators[i]->closeDoor(); // close door [7]
      } // end if has riders
      else // if no riders
      {
        buildingElevators[i]->setIdle(); // go idle [7]
      }
    } // else (for already let off riders or is in initial state.
  } // end for loop checking all elevators


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@                 Floor                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int i = 0; i<buildingFloors.size(); i++) // check each floor (for waiting riders) [2]
  {
    if (buildingFloors[i]->hasRidersWaiting() == true) // if there are no riders waiting on this floor, continue with next floor [2]
    {
      for (int j = 0; j<buildingElevators.size(); j++) // look at each elevator to see if it needs to be sent here [2]
      {
        int relativeLocation = ((buildingElevators[j]->getLocation()) - (buildingFloors[i]->getLocation())); // get elevator's relative location (negative if elevator is below floor) [2]

        if (buildingElevators[j]->isIdle() == true) // if this elevator's idle... [2]
        {
          if (relativeLocation > 0) // if elevator is above the floor... [2]
          {
            buildingElevators[j]->setDirectionDown(); // ... set elevator direction to down [2]
          } // end if (elevator > floor)
          else if (relativeLocation < 0) // otherwise if it's below... [2]
          {
            buildingElevators[j]->setDirectionUp(); // ...set elevator direction to up [2]
          }
          buildingElevators[j]->setDestination(buildingFloors[i]); // set elevator's destination to this floor [2]
          buildingElevators[j]->closeDoor(); // tell elevator to close its door [2]
        } // end if elevator.isIdle()

        else if (buildingFloors[i]->hasUpRiders() == true && buildingElevators[j]->isDirectionUp() == true) //there are riders on this floor waiting to go up, and the elevator is going up... [10]
        {
          // distance from elevator's destination floor to this floor (positive if elevator destination is above this floor) [10]
          int elevatorDistance = ( (buildingElevators[j]->getDestination().getLocation()) - (buildingFloors[i]->getLocation()) );

          if ( (relativeLocation < 0) && (elevatorDistance > 0)) //elevator is below floor and elevator destination is above this floor [10]
          {
            buildingElevators[j]->setDestination(buildingFloors[i]); //set elevator's destination to this floor [10]
          } // end if (elevator is moving up past this floor)
        } // end else (riders on floor going up AND elevator going up)

        else if ( (buildingFloors[i]->hasDownRiders() == true) && (buildingElevators[j]->isDirectionDown() == true)) //there are riders on this floor waiting to go down, and the elevator is going down... [10]
        {
          // distance from elevator's destination floor to this floor (negative if elevator destination is below this floor) [10]
          int elevatorDistance = ( (buildingElevators[j]->getDestination().getLocation()) - (buildingFloors[i]->getLocation()) );

          if ( (relativeLocation > 0) && (elevatorDistance < 0)) //elevator is above floor and elevator destination is below this floor [10]
          {
            buildingElevators[j]->setDestination(buildingFloors[i]); //set elevator's destination to this floor [10]
          } // end if (elevator is moving down past this floor)
        } // end else (riders on floor going down AND elevator going down)
      } // end for loop checking all elevators
    } // end if Floor has riders waiting loop
  } // end for loop for checking all Floors

  simulationTime ++;
  return *this; // should return a reference to itself.
}
