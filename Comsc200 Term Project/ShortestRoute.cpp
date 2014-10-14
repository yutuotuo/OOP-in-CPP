// Shortest Route Term Project
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cstdlib>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <iomanip>
using std::setprecision;
using std::setw;

#include <string>
using std::string;
using std::getline;

#include <cstring>

#include <vector>
using std:: vector;

#include <cassert>



class Route; // forward declaration
class ShortestRoute; // forward declaration



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  Leg class            @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Leg // declaration
{
  friend ostream& operator<<(ostream&, const Leg&); // const friendly print function
  friend ostream& operator<<(ostream&, const Route&);
  friend class Route; // friendly to Route so leg distance is accessible
  friend class ShortestRoute;

public:
  Leg(const string cityBegin, const string cityEnd,
      const double legDistance); //constructor prototype. NO DEFAULT for Leg
  // Dummy Overload
  void operator=(const Leg&)
  {
    assert(false); // should never be called
  }


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
  friend ostream& operator<<(ostream&, const Route&); // const friendly print function
  friend class ShortestRoute;

public:
  Route(const Leg& legBegin); // Constructor 1: simple route consisting of only one leg
  Route(const Route& routeBegin, const Leg& legAdd); // Constructor 2: create new route by adding leg to existing route.
  Route(const Route& routeToCopy); // Constructor 3: copy constructor
  ~Route(); // Destructor using the delete [] operator.
  double getDistance() const; // return distance of entire route
  bool isGreaterThan(const Route&) const; // bool comparison

  // Dummy Overload//
  void operator=(const Route&)
  {
    assert(false);
  } // should never be called//void operator=(const   Leg&){assert(false);}

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
//@@@@@@@@@@@@@@@@@@@@@@          ShortestRoute class          @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class ShortestRoute
{
private:

public:
  // class-defined static
  static vector<Leg> legs; // a vector of leg objects
  static const Route getAnyRoute(const string from, const string to);
  static const Route getShortestRoute(const string from, const string to);

  ShortestRoute(); // default constructor
  // Dummy Overload
  void operator=(const ShortestRoute&)
  {
    assert(false); // should never be called
  }
}; // end class ShortestRoute

vector<Leg> ShortestRoute::legs; // CHECK! Do I need to declare this outside the object?


const Route ShortestRoute::getAnyRoute(const string from, const string to)
{
  for (int i = 0; i < ShortestRoute::legs.size(); i++) // looping through all legs in vector...
  {
    if (ShortestRoute::legs[i].cityEnd.compare(to) == 0) // if "to" matches legs[i].cityEnd
    {
      if (ShortestRoute::legs[i].cityStart.compare(from) == 0)  return Route(legs[i]); // if "from" matches legs[i].cityStart
      else return Route(getAnyRoute(from, legs[i].cityStart), legs[i]); // end else (return recursive Route)
    } // end if ("to" matches legs[i].end)
  } // end for (legs loop)
  throw "No route possible from given vector of ShortestRoute::legs."; // if the full recursion runs with no joy...
} // end getAnyRoute


const Route ShortestRoute::getShortestRoute(const string from, const string to)
{
  static vector<Route> r;
  static const Route* shortestRoute;

  for (int i = 0; i < ShortestRoute::legs.size(); i++) // looping through all legs in vector...
  {
    try
    {
      if (ShortestRoute::legs[i].cityEnd.compare(to) == 0) // if "to" matches legs[i].cityEnd
      {
        if (ShortestRoute::legs[i].cityStart.compare(from) == 0)  r.push_back(Route(legs[i])); // if "from" matches legs[i].cityStart
        else
        {
          r.push_back(Route(getShortestRoute(from, legs[i].cityStart), legs[i]));
        }// end else (return recursive Route)
      } // end if ("to" matches legs[i].end)
    }
    catch (const char* ex)
    {
      continue;
    }
  } // end for (legs loop)


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@        Shortest Route Testing         @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  // convenient variables
  int sz = (legs.size() - 1);
  Route lastLeg(legs[sz]);
  shortestRoute = &lastLeg;  // set shortestRoute == "SF - NY" superhighway

  for (int i = 0; i < r.size(); i++) // looping through all legs in vector...
  {
    if (r[i].thisRoute[0]->cityStart.compare(from) == 0) // if (city starts match)
    {
      int thisRouteSize = ((r[i].arraySize) -1); // for convenience
      if (r[i].thisRoute[thisRouteSize]->cityEnd.compare(to) == 0) // if (city ends match)
      {
        if ( (shortestRoute->isGreaterThan(r[i])) == true) // if (shortestRoute > r[i])
        {
          shortestRoute = &r[i];
        } // end if (shortestRoute > r[i])
      } // end if (city ends match)
    }// end if (city starts match)
  } // end for

  return *shortestRoute;
} // end getShortestRoute


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                functions              @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// friend function
ostream& operator<<(ostream& out, const Leg& leg)
{
  out << leg.cityStart << " to " << leg.cityEnd << ", " << leg.distance << " miles." << endl;
  return out;
} // end ostream& operator<< (Leg)

ostream& operator<<(ostream& out, const Route& route)
{
  int routeSize = route.arraySize;

  out << route.thisRoute[0]->cityStart;
  for (int i=0; i<routeSize; i++) out << " to " << route.thisRoute[i]->cityEnd;
  out << "; Distance = " << route.getDistance() << " miles." << endl;
  return out;
} // end ostream& operator<< (Route)


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  main                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: Find the shortest route between\n";
  cout << "San Francisco and New York using a series of legs.\n";
  cout << "To be fair: Forrest Gump got from San Francisco to\n";
  cout << "New York with just two legs, but we can't all be him...\n";
  cout << "-------------------------------\n" << endl << endl << endl;

  // Variable Declaration & load "legs:"
  ShortestRoute::legs.push_back(Leg("San Francisco", "Carson City", 215));
  ShortestRoute::legs.push_back(Leg("San Francisco", "Phoenix", 754));
  ShortestRoute::legs.push_back(Leg("Carson City", "Boise", 449));
  ShortestRoute::legs.push_back(Leg("Carson City", "Salt Lake City", 547));
  ShortestRoute::legs.push_back(Leg("Phoenix", "Denver", 863));
  ShortestRoute::legs.push_back(Leg("Phoenix", "Santa Fe", 480));
  ShortestRoute::legs.push_back(Leg("Boise", "Cheyenne", 736));
  ShortestRoute::legs.push_back(Leg("Salt Lake City", "Denver", 517));
  ShortestRoute::legs.push_back(Leg("Santa Fe", "Denver", 391));
  ShortestRoute::legs.push_back(Leg("Santa Fe", "Oklahoma City", 535));
  ShortestRoute::legs.push_back(Leg("Santa Fe", "Austin", 687));
  ShortestRoute::legs.push_back(Leg("Cheyenne", "Lincoln", 443));
  ShortestRoute::legs.push_back(Leg("Cheyenne", "Topeka", 630));
  ShortestRoute::legs.push_back(Leg("Denver", "Oklahoma City", 677));
  ShortestRoute::legs.push_back(Leg("Denver", "Topeka", 538));
  ShortestRoute::legs.push_back(Leg("Oklahoma City", "Topeka", 294));
  ShortestRoute::legs.push_back(Leg("Oklahoma City", "Jefferson City", 420));
  ShortestRoute::legs.push_back(Leg("Oklahoma City", "Jackson", 607));
  ShortestRoute::legs.push_back(Leg("Austin", "Oklahoma City", 389));
  ShortestRoute::legs.push_back(Leg("Austin", "Jackson", 543));
  ShortestRoute::legs.push_back(Leg("Lincoln", "Des Moines", 187));
  ShortestRoute::legs.push_back(Leg("Lincoln", "Jefferson City", 349));
  ShortestRoute::legs.push_back(Leg("Lincoln", "Topeka", 164));
  ShortestRoute::legs.push_back(Leg("Jefferson City", "Springfield", 193));
  ShortestRoute::legs.push_back(Leg("Jefferson City", "Nashville", 439));
  ShortestRoute::legs.push_back(Leg("Topeka", "Des Moines", 257));
  ShortestRoute::legs.push_back(Leg("Topeka", "Jefferson City", 220));
  ShortestRoute::legs.push_back(Leg("Jackson", "Nashville", 415));
  ShortestRoute::legs.push_back(Leg("Des Moines", "Springfield", 337));
  ShortestRoute::legs.push_back(Leg("Springfield", "Indianapolis", 209));
  ShortestRoute::legs.push_back(Leg("Springfield", "Frankfort", 375));
  ShortestRoute::legs.push_back(Leg("Nashville", "Indianapolis", 287));
  ShortestRoute::legs.push_back(Leg("Nashville", "Frankfort", 209));
  ShortestRoute::legs.push_back(Leg("Nashville", "Charleston", 387));
  ShortestRoute::legs.push_back(Leg("Des Moines", "Lansing", 534));
  ShortestRoute::legs.push_back(Leg("Indianapolis", "Lansing", 254));
  ShortestRoute::legs.push_back(Leg("Indianapolis", "Columbus", 172));
  ShortestRoute::legs.push_back(Leg("Indianapolis", "Charleston", 311));
  ShortestRoute::legs.push_back(Leg("Indianapolis", "Frankfort", 166));
  ShortestRoute::legs.push_back(Leg("Frankfort", "Columbus", 186));
  ShortestRoute::legs.push_back(Leg("Frankfort", "Charleston", 198));
  ShortestRoute::legs.push_back(Leg("Lansing", "Harrisburg", 549));
  ShortestRoute::legs.push_back(Leg("Columbus", "Harrisburg", 372));
  ShortestRoute::legs.push_back(Leg("Columbus", "Trenton", 494));
  ShortestRoute::legs.push_back(Leg("Charleston", "Harrisburg", 367));
  ShortestRoute::legs.push_back(Leg("Charleston", "Trenton", 481));
  ShortestRoute::legs.push_back(Leg("Harrisburg", "New York City", 169));
  ShortestRoute::legs.push_back(Leg("Trenton", "New York City", 66.1));
  ShortestRoute::legs.push_back(Leg("San Francisco", "New York City", 21000.0));


  // run functions
  cout << "  Now running \"ShortestRoute::getAnyRoute\":\n" << endl;
  try
  {
    cout << ShortestRoute::getAnyRoute("San Francisco", "New York City");
  }
  catch (const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }

  cout << endl << endl << "  Now running \"ShortestRoute::getShortestRoute\":" << endl;
  try
  {
    cout << endl << ShortestRoute::getShortestRoute("San Francisco", "New York City");
  }
  catch (const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }

  cout << endl << endl << endl << endl << "  That's it! See you in COMSC210, I think! :-D" << endl << endl;
} // end main
