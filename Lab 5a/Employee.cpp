// Lab 5a - Employee class
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cout;
using std::endl;
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition
// using namespace std;

// constructor uses member initializer list to pass initializer
// values to constructors of member objects
Employee::Employee(const string& first, const string& last,
                   const Date& dateOfBirth, const Date& dateOfHire)
                   : firstName(first), // initialize firstName
                   lastName(last), // initialize lastName
                   birthDate(dateOfBirth), // initialize birthDate
                   hireDate(dateOfHire) // initialize hireDate
{
  // output Employee object to show when constructor is called
  cout << "Employee object constructor: "
    << firstName << ' ' << lastName << endl;
} // end Employee constructor

// print Employee object
void Employee::print() const
{
  cout << lastName << ", " << firstName << " Hired: ";
  hireDate.print();
  cout << " Birthday: ";
  birthDate.print();
  cout << endl;
} // end function print()
