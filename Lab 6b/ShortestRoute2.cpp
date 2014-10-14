// Lab 6b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

const int LEG_ARRAY_SIZE = 6;

class Route; // forward declaration

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  Leg class            @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Leg // declaration
{
  friend void printLeg(ostream&, const Leg&); // const friendly print function
  friend void printRoute(ostream&, const Route&); // const friendly print function

public:
  Leg(const char* const cityBegin, const char* const cityEnd,
      const double legDistance); //constructor prototype. NO DEFAULT for Leg

private: // must initialize during creation
  const char* const cityStart;
  const char* const cityEnd;
  const double distance;
}; // end class Leg

// class Leg definitions
Leg::Leg(const char* const cityBegin, const char* const cityTerm,
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
  int getSize() const; // return size

private: // must initialize during creation
  const int arraySize;
  const Leg** const thisRoute; // dynamically-sized array of const Leg pointers (1)
}; // end class Route

Route::Route(const Leg& legBegin) : arraySize(1), thisRoute(new const Leg*[1])//constructor definition; this adds first leg
{
  thisRoute[0] = &legBegin;
} // end Route (leg)

Route::Route(const Route& routeBegin, const Leg& legAdd) : arraySize(routeBegin.getSize()+1),
                                                           thisRoute(new const Leg*[arraySize]) //: Route(routeBegin)// DON'T NEED starting city to match the ending city of the Route object yet
{
  for (int i=0; i<(arraySize-1); i++)
  {
    thisRoute[i] = routeBegin.thisRoute[i];
  } // end for
  thisRoute[arraySize-1] = &legAdd;
} // end Route (route, leg)

Route::Route(const Route& routeBegin) : arraySize(routeBegin.getSize()),
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

int Route::getSize() const
{
  return arraySize;
} // end getSize


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                functions              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void printLeg(ostream& out, const Leg& leg) // : ostream& out(thisOut), const Leg& leg(thisLeg);
{
  out << leg.cityStart << " to " << leg.cityEnd << ", " << leg.distance << " miles." << endl;
} // end printLeg

void printRoute(ostream& out, const Route& route) // print textual description of route
{
  int routeSize = route.getSize();
  double totalDistance = 0;

  out << route.thisRoute[0]->cityStart;
  for (int i=0; i<routeSize; i++)
  {
    out << " to " << route.thisRoute[i]->cityEnd;
    totalDistance += route.thisRoute[i]->distance;
  } // end for
  out << "; Distance = " << totalDistance << " miles." << endl;
} // end printRoute


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  main                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: add legs to Route objects to\n";
  cout << "create a route.\n";
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


  { // TESTING THE ROUTE CLASS COPY CONSTRUCTOR: start local scope
    Route rCopy = ra;
    printRoute(cout, rCopy);
  } // end local scope
  printRoute(cout, ra); // out of scope...

} // end main
