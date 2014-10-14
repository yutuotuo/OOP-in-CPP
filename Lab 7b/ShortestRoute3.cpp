// Lab 7b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <string>
using std::string;

const int LEG_ARRAY_SIZE = 6;

class Route; // forward declaration

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  Leg class            @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Leg // declaration
{
  friend void printLeg(ostream&, const Leg&); // const friendly print function
  friend void printRoute(ostream&, const Route&); // const friendly print function
  friend class Route; // friendly to Route so leg distance is accessible

public:
  Leg(const string cityBegin, const string cityEnd,
      const double legDistance); //constructor prototype. NO DEFAULT for Leg

private: // must initialize during creation
  const string cityStart;
  const string cityEnd;
  const double distance;
}; // end class Leg

// class Leg definitions
Leg::Leg(const string cityBegin, const string cityTerm,
         const double legDistance) : cityStart(cityBegin),
  cityEnd(cityTerm), distance(legDistance) //constructor definition
{
  //empty body
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                Route class            @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Route // Declaration. A route of multiple connecting legs between two non-adjacent cities.
{
  friend void printRoute(ostream&, const Route&); // const friendly print function

public:
  Route(const Leg& legBegin); // Constructor 1: simple route consisting of only one leg
  Route(const Route& routeBegin, const Leg& legAdd); // Constructor 2: create new route by adding leg to existing route.
  Route(const Route& routeToCopy); // Constructor 3: copy constructor
  Route& operator=(const Route&); // assignment operator
  ~Route(); // Destructor using the delete [] operator.
  double getDistance() const; // return distance of entire route
  bool isGreaterThan(const Route&) const; // bool comparison

private: // must initialize during creation
  const int arraySize;
  const Leg** const thisRoute; // dynamically-sized array of const Leg pointers
}; // end class Route


Route::Route(const Leg& legBegin) : arraySize(1), thisRoute(new const Leg*[1]) //constructor definition; this adds first leg
{
  thisRoute[0] = &legBegin;
} // end Route (leg)

Route::Route(const Route& routeBegin, const Leg& legAdd) : arraySize(routeBegin.arraySize+1),
  thisRoute(new const Leg*[arraySize])
{
  for (int i=0; i<(arraySize-1); i++)
  {
    thisRoute[i] = routeBegin.thisRoute[i];
  } // end for
  thisRoute[arraySize-1] = &legAdd;

  if (thisRoute[arraySize-2]->cityEnd != thisRoute[arraySize-1]->cityStart)
  {
    delete[] thisRoute; // deconstruct dynamically-allocated memory
    throw "End City of Route not same as Start City of Leg.";
  }
} // end Route (route, leg)

Route::Route(const Route& routeBegin) : arraySize(routeBegin.arraySize),
  thisRoute(new const Leg*[arraySize]) // copy constructor
{
  for (int i=0; i<(arraySize); i++)
  {
    thisRoute[i] = routeBegin.thisRoute[i];
  } // end for
} // end Route copier

Route::~Route() // destructor using the delete [] operator.
{
  delete[] thisRoute;
} // ~Route()

double Route::getDistance() const
{
  double totalDistance = 0;

  for (int i=0; i<arraySize; i++) totalDistance += thisRoute[i]->distance;
  return totalDistance;
}

bool Route::isGreaterThan(const Route& route) const // bool to compare distance of host object to another object
{
  double thisDistance = this->getDistance();
  double comparedDistance = route.getDistance();

  if (thisDistance > comparedDistance) return true;
  else return false;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                functions              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void printLeg(ostream& out, const Leg& leg)
{
  out << leg.cityStart << " to " << leg.cityEnd << ", " << leg.distance << " miles." << endl;
} // end printLeg

void printRoute(ostream& out, const Route& route) // print textual description of route
{
  int routeSize = route.arraySize;

  out << route.thisRoute[0]->cityStart;
  for (int i=0; i<routeSize; i++) out << " to " << route.thisRoute[i]->cityEnd;
  out << "; Distance = " << route.getDistance() << " miles." << endl;
} // end printRoute


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  main                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: Apply 'const' keywords and\n";
  cout << "strings to existing Shortest Route solution.\n";
  cout << "-------------------------------\n" << endl;

  // Variable Declaration
  const Leg a("San Francisco", "Sacramento", 87.2);
  const Route ra(a); // route from San Francisco to Sacramento

  const Leg b("Sacramento", "Reno", 135);
  const Route rb(ra, b); // route from San Francisco to Reno

  const Leg c("Reno", "Salt Lake City", 518);
  const Route rc(rb, c); // route from San Francisco to Salt Lake City

  const Leg d("Salt Lake City", "Fort Collins", 454);
  const Route rd(rc, d); // route from San Francisco to Fort Collins

  const Leg e("Fort Collins", "Omaha", 538);
  const Route re(rd, e); // route from San Francisco to Omaha

  const Leg f("Omaha", "Chicago", 472);
  const Route rf(re, f); // route from San Francisco to Chicago

  printRoute(cout, rf);

  {
    // TESTING THE ROUTE CLASS COPY CONSTRUCTOR: start local scope
    cout << endl << endl << "  Now testing the class copy constructor:" << endl;
    Route rCopy = ra;
    printRoute(cout, rCopy);
  } // end local scope
  printRoute(cout, ra); // out of scope...

  //  test the new compare function, by comparing at least 3 pairs of routes, and printing some result indicating which route is longer and which is shorter.
  cout << endl << endl << "  Now comparing route distances; \"1\" means the first"
       << "\n  route is longer than the second route:\n" << endl;

  cout << "SF-Sac longer than SF-Reno?   (expect 0)   " << ra.isGreaterThan(rb) << endl;
  cout << "SF-Omaha longer than SF-SLC?   (expect 1)   " << re.isGreaterThan(rc) << endl;
  cout << "SF-Chicago longer than SF-FC?   (expect 1)   " << rf.isGreaterThan(re) << endl;

  cout << endl << endl << "  Now comparing, one line at a time, as follows:"
       << "\n  ra > ra? ra > rb? ra > rc? etc..."
       << "\n  rb > ra? rb > rb? rb > rc? etc... to rf > rf?\n" << endl;

  cout << ra.isGreaterThan(ra) << ra.isGreaterThan(rb) << ra.isGreaterThan(rc) << ra.isGreaterThan(rd) << ra.isGreaterThan(re) << ra.isGreaterThan(rf) << endl;
  cout << rb.isGreaterThan(ra) << rb.isGreaterThan(rb) << rb.isGreaterThan(rc) << rb.isGreaterThan(rd) << rb.isGreaterThan(re) << rb.isGreaterThan(rf) << endl;
  cout << rc.isGreaterThan(ra) << rc.isGreaterThan(rb) << rc.isGreaterThan(rc) << rc.isGreaterThan(rd) << rc.isGreaterThan(re) << rc.isGreaterThan(rf) << endl;
  cout << rd.isGreaterThan(ra) << rd.isGreaterThan(rb) << rd.isGreaterThan(rc) << rd.isGreaterThan(rd) << rd.isGreaterThan(re) << rd.isGreaterThan(rf) << endl;
  cout << re.isGreaterThan(ra) << re.isGreaterThan(rb) << re.isGreaterThan(rc) << re.isGreaterThan(rd) << re.isGreaterThan(re) << re.isGreaterThan(rf) << endl;
  cout << rf.isGreaterThan(ra) << rf.isGreaterThan(rb) << rf.isGreaterThan(rc) << rf.isGreaterThan(rd) << rf.isGreaterThan(re) << rf.isGreaterThan(rf) << endl;

  //  test the try exception statement
  cout << endl << endl << "  Now testing the Route constructor exception catching code"
       << "\n  to ensure Route's starting city == Leg's ending city:\n" << endl;

  cout << "  Test 1 with good Routes executing now (should be no error):" << endl;
  try // legs match - no error generated
  {
    Route(Route(Leg("a", "b", 0)), Leg("b", "d", 0));
  }
  catch (const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }

  cout << "  Test 2 with bad Routes executing now (should throw exception):" << endl;
  try // legs do not match - error generated
  {
    Route(Route(Leg("a", "b", 0)), Leg("c", "d", 0));
  }
  catch (const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }
} // end main
