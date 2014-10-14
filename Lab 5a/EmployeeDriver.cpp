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
#include "Employee.h"
#include "Employee.h" // testing ifndef

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: Test Driver for Employee class\n";
  cout << "-------------------------------\n" << endl;

  cout << "Birthday Date object: ";
  Date bDay(10,20,1981);
  cout << "Hire Date object: ";
  Date hDay(8,12,2013);

  cout << endl << endl << "Creating Employee object with assignment upon declaration:" << endl;
  Employee aaron("Aaron", "Melocik", bDay, hDay);
  cout << "  \"print()\" should read \"Melocik, Aaron, hire: 8/12/13, birthday: 10/20/1981\": " << endl;
  aaron.print();

  // object copy testing, with assignment UPON declaration
  {
    Employee copy = aaron;
    cout << "\n   Copy created, with assignment upon declaration. Reads: ";
    copy.print();
  }
} // end main
