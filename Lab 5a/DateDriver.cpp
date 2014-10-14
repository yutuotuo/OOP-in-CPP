// Lab 5a - Date Test Driver
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include "Date.h"
#include "Date.h" // testing ifndef

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: Test Driver for Date class\n";
  cout << "-------------------------------\n" << endl;

  cout << "Creating Date object (should read \"10/20/1981\")" << endl;
  Date testDate(10,20,1981);
  cout <<  "  Now calling \"print()\": ";
  testDate.print();

  // const object copy testing, with assignment UPON declaration
  {
    const Date copy = testDate;
    cout << "\n\nCopy created, with assignment upon declaration. Reads: ";
    copy.print();
  }

  // object copy testing, with assignment AFTER declaration
  {
    cout << "\n\nCreating copy with default constructor. Should" << endl;
    cout << "read \"1/1/1900\": " << endl;
    Date copy;
    cout << "  Now calling \"print()\": ";
    copy.print();

  }

  // invalid object created, then assigned valid values
  {
    cout << "\n\nCreating copy with invalid values \"15/40/-905\". Should" << endl;
    cout << "print warnings and read \"1/1/-905\":" << endl;
    Date copy(15,40,-905);
    cout << "  Now \"print()\"ing: ";
    copy.print();

    copy = testDate;
    cout << "\n  Copy assigned value of Original. Now \"print()\"ing: ";
    copy.print();
  }

  // leap year object created, then assigned valid values
  {
    cout << "\n\nCreating copy in Leap Year \"2/29/2000\":" << endl;
    Date copy(2,29,2000);
    cout << "\n  Now \"print()\"ing: ";
    copy.print();

    copy = testDate;
    cout << "\n  Copy assigned value of Original. Now \"print()\"ing: ";
    copy.print();
  }

    // invalid leap year object created, then assigned valid values
  {
    cout << "\n\nCreating an invalid non-Leap Year: \"2/29/1981\":" << endl;
    Date copy(2,29,1981);
    cout << "\n  Now \"print()\"ing: (Expect \"2/28/1981\"): ";
    copy.print();

    copy = testDate;
    cout << "\n  Copy assigned value of Original. Now \"print()\"ing: ";
    copy.print();
  }
} // end main
