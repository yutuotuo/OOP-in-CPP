// Lab 6a: TimeDriver.cpp
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

/* Common Library Includes
from cctype: toupper, tolower
from cmath: sqrt, pow, exp
from cstdlib: abs, atoi, atof, rand
from cstring: strlen, strcpy, strcmp
from iostream: cin, cout, endl, ios
from string: string, getline */

//#include <cstdlib>
#include <iostream>
//using std::cin;
using std::cout;
using std::endl;
//using std::ios;
//#include <iomanip>
//using std::setprecision;
//
//#include <string>
//using std::string;
//using std::getline;
#include "Time.h"
#include "Time.h" // testing ifndef

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: implementation of \"Time\" class\n";
  cout << "from text book to use cascading function calls.\n";
  cout << "-------------------------------\n" << endl;

  cout << "Creating Time object of \"13:57:26\"..." << endl;
  Time t(13,57,26);
  cout << "Calling print functions (expect \"13:57:26\", then \"1:57:26 PM\"):" << endl;
  cout << "Universal = ";
  t.printUniversal();
  cout << ";   Standard = ";
  t.printStandard();

  cout << "\nCalling getters for Hour, Minute, Second: ";
  cout << t.getHour() << ", " << t.getMinute() << ", " << t.getSecond();

  // object copy testing, with assignment upon declaration
  {
    cout << "\n\nCreating copy of Time object. Should read \"13:57:26\": " << endl;
    Time copy = t;
    cout << "Universal = ";
    copy.printUniversal();
    cout << ";   Standard = ";
    copy.printStandard();
  }

  // object testing: default constructor AND assignment after declaration
  {
    cout << "\n\nCreating Time object with default constructor. Should read \"00:00:00\": " << endl;
    Time t2;
    cout << "Universal = ";
    t2.printUniversal();
    cout << ";   Standard = ";
    t2.printStandard();

    cout << "\n\nNow assigning this Time object to original Time object." << endl;
    cout << "Should read \"13:57:26\": " << endl;
    t2 = t;
    cout << "Universal = ";
    t2.printUniversal();
    cout << ";   Standard = ";
    t2.printStandard();

    cout << "\n\nNow assigning this Time object to \"12:11:10\"" << endl;
    cout << "using \"setTime()\" function call: " << endl;
    t2.setTime(12, 11, 10);
    cout << "Universal = ";
    t2.printUniversal();
    cout << ";   Standard = ";
    t2.printStandard();

    cout << "\n\nFinally, assigning this Time object to \"01:23:45\"" << endl;
    cout << "using cascading function member calls: " << endl;
    t2.setHour(1).setMinute(23).setSecond(45);
    cout << "Universal = ";
    t2.printUniversal();
    cout << ";   Standard = ";
    t2.printStandard();
  } // end copy testing

  cout << endl << endl;

} // end main
