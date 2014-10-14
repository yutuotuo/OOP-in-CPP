//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//#include <vector>
//using std::vector;
//
//#include <algorithm>
//using std::sort;
//
//#include "Floor.h" //from lab 8
//#include "Rider.h"
//#include "Elevator.h"
//
//int main()
//{
//  // create an elevator (capacity 12, speed 5 in/sec)
//  const Floor startingFloor(0); // ground floor
//  Elevator e(12, 5, startingFloor);
//  cout << "The only elevator in this test: " << e << endl;
//
//  // testing the getCapacity function
//  cout << "Capacity is " << e.getCapacity();
//  if (e.getCapacity() == 12) cout << "(correct)\n"; else cout << "(INCORRECT)\n";
//
//  // move the elevator up for 20 seconds
//  e.closeDoor();
//  e.setDestination(0);
//  e.setDirectionUp();
//  int i, count = 0;
//  for (i = 0; i < 20; i++)
//    e.moveUp();
//  e.setIdle();
//  e.openDoor();
//  cout << "Moved up for 20 seconds: " << e << endl;
//
//
//
//
//                    //cout << endl << endl << endl << "line 41" << endl << endl << endl;
//
//
//
//
//  // add riders to the elevator, to capacity
//  vector<Rider> riders;
//  int n = e.getAvailableSpace();
//  for (i = 0; i < n; i++)
//    riders.push_back(Rider(startingFloor));
//  e.addRiders(riders);
//  cout << "Added riders to capacity: " << e << endl;
//  cout << "#of riders is " << e.getRiderCount();
//  if (e.getRiderCount() == 12) cout << "(correct)\n"; else cout << "(INCORRECT)\n";
//  vector<Rider> originalRiders(riders);
//
//  // move down to first floor until it reaches
//  e.setDestinationBasedOnRiders();
//  e.closeDoor();
//  e.setDirectionDown();
//  cout << e << endl;
//
//
//
//
//
//                    //cout << endl << endl << endl << "line 67; rider vector size = " << riders.size() << "originalRiders vector size = " << originalRiders.size() << endl << endl << endl;
//
//
//
//
//
//  while(!e.isNearDestination())
//  {
//    if (e.isDirectionUp()) e.moveUp();
//    else if (e.isDirectionDown()) e.moveDown();
//    cout << e << endl;
//    if (!(++count % 20)) {cout << "Press ENTER to continue...\n"; cin.get();}
//  }
//  e.moveToDestinationFloor();
//  cout << "Moved to destination floor: " << e << endl;
//
//  // done
//  e.openDoor();
//  riders = e.removeRidersForDestinationFloor();
//  cout << "Opened door, let out " << riders.size() << " riders: " << e << endl;
//  cout << "#of riders is " << e.getRiderCount();
//  if (e.getRiderCount() == 0) cout << "(correct)\n"; else cout << "(INCORRECT)\n";
//  e.setIdle();
//
//
//
//
//
//                    //cout << endl << endl << endl << "line 95" << endl << endl << endl;
//
//
//
//
//
//  // see if same riders got off who got on originally
//  if (riders.size() < originalRiders.size())
//    cout << "ERROR: LOST RIDERS!\nriders.size = " << riders.size() << ", originalRiders.size = " << originalRiders.size();
//  else if (riders.size() > originalRiders.size())
//    cout << "ERROR: MYSTERIOUSLY-CREATED RIDERS!\n";
//  else
//  {
//    sort(riders.begin(), riders.end());
//    sort(originalRiders.begin(), originalRiders.end());
//    n = riders.size();
//    for (i = 0; i < n; i++)
//    {
//      if (!(riders[i] == originalRiders[i]))
//        cout << "ERROR: RIDER#" << i << " HAS NEW IDENTITY!\n";
//  } }
//
//
//
//
//
//                    //cout << endl << endl << endl << "line 121" << endl << endl << endl;
//
//
//
//
//
//  // now, move the elevator down for 20 seconds
//  e.closeDoor();
//  e.setDestination(0);
//  e.setDirectionDown();
//  for (i = 0; i < 20; i++)
//    e.moveDown();
//  e.setIdle();
//  e.openDoor();
//  cout << "Moved down for 20 seconds: " << e << endl;
//
//  // add a rider going up
//  riders.clear();
//  riders.push_back(Rider(startingFloor));
//  e.addRiders(riders);
//  cout << "#of riders is " << e.getRiderCount();
//  if (e.getRiderCount() == 1) cout << "(correct)\n"; else cout << "(INCORRECT)\n";
//
//
//
//
//
//                    //cout << endl << endl << endl << "line 148" << endl << endl << endl;
//
//
//
//
//
//  // move up to first floor until it reaches
//  e.setDestinationBasedOnRiders();
//  e.closeDoor();
//  e.setDirectionUp();
//  cout << e << endl;
//  while(!e.isNearDestination())
//  {
//    if (e.isDirectionUp()) e.moveUp();
//    else if (e.isDirectionDown()) e.moveDown();
//    cout << e << endl;
//    if (!(++count % 20)) {cout << "Press ENTER to continue...\n"; cin.get();}
//  }
//  e.moveToDestinationFloor();
//  cout << "Move to starting floor: " << e << endl;
//
//
//
//
//
//                    //cout << endl << endl << endl << "line 173" << endl << endl << endl;
//
//
//
//
//
//  // done
//  e.openDoor();
//  e.removeRidersForDestinationFloor();
//  e.setIdle();
//  cout << "Test end: " << e << endl;
//  cout << "#of riders is " << e.getRiderCount();
//  if (e.getRiderCount() == 0) cout << "(correct)\n"; else cout << "(INCORRECT)\n";
//
//  // additional testing of your own, if you have any
//  //...
//}
