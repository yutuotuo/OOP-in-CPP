// Lab 4a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include "Time.h"
#include "Time.h" // testing ifndef

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: TestDriver program for testing\n";
  cout << "class Time as built in book, with changes.\n";
  cout << "-------------------------------\n\n";

  Time t; // this satisfies the Constructor test
  cout << "Default Universal time from constructor = ";
  t.printUniversal();
  cout << "\nDefault Standard time from constructor = ";
  t.printStandard();
  cout << endl;

  // test all getters and setters
  cout << "\n   Setting: hour = 16, minute = 45, Second = 22." << endl;
  t.setHour(16); t.setMinute(45); t.setSecond(22);
  cout << "Printed result (U, then S; expect \"16:45:22\" and \"4:45:22 PM\"):" << endl;
  t.printUniversal();
  cout << endl;
  t.printStandard();
  cout << endl;

  // object copy testing, with assignment UPON declaration
  {
    const Time copy = t;
    //...use getters to confirm that copy's contents match salesPerson's
    cout << endl << "   Copy's output below (should match original):" << endl;
    copy.printUniversal();
    cout << endl;
    copy.printStandard();
    cout << endl << endl;

    cout << "   Now calling individual getHour, getMinute, getSecond." << endl;
    cout << "" << copy.getHour() << " " << copy.getMinute() << " " << copy.getSecond() << endl;
  }

  // object copy testing, with assignment AFTER declaration
  {
    Time copy; copy = t;
    //...use getters to confirm that copy's contents match salesPerson's
    cout << endl << "   Copy 2's output below (should match original):" << endl;
    copy.printUniversal();
    cout << endl;
    copy.printStandard();
    cout << endl << endl;

    cout << "   Now calling individual getHour, getMinute, getSecond." << endl;
    cout << "" << copy.getHour() << " " << copy.getMinute() << " " << copy.getSecond() << endl << endl;

    cout << "   Now setting time as: setHour(23), setMinute(34), setSecond(45)." << endl;
    copy.setHour(23); copy.setMinute(34); copy.setSecond(45);
    cout << endl << "   Copy 2's updated output below (expect U, S: \"23:34:45\"):" << endl;
    copy.printUniversal();
    cout << endl;
    copy.printStandard();
    cout << endl << endl;
  }

}

