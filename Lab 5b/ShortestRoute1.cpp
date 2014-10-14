// Lab 5b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

const int LEG_ARRAY_SIZE = 6;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  Leg class            @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Leg // declaration
{
  friend void printLeg(ostream&, const Leg&); // const friendly print function

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
//@@@@@@@@@@@@@@@@@@@@@@                function               @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  void printLeg(ostream& out, const Leg& leg) // : ostream& out(thisOut), const Leg& leg(thisLeg);
{
  out << leg.cityStart << " to " << leg.cityEnd << ", " << leg.distance << " miles." << endl;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  main                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: Use objects and friend functions to\n";
  cout << "solve the 'shortest route' problem.\n";
  cout << "-------------------------------\n" << endl;

  // Variable Declaration
  Leg a("San Francisco", "Sacramento", 87.2);
  Leg b("Sacramento", "Reno", 135);
  Leg c("Reno", "Salt Lake City", 518);
  Leg d("Salt Lake City", "Fort Collins", 454);
  Leg e("Fort Collins", "Omaha", 538);
  Leg f("Omaha", "Chicago", 472);

  printLeg(cout, a);
  printLeg(cout, b);
  printLeg(cout, c);
  printLeg(cout, d);
  printLeg(cout, e);
  printLeg(cout, f);
}
