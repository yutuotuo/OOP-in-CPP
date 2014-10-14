// Lab 5a - Employee header
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
//using std::getline;
using std::string;

#include "Date.h" // include Date class definition
//using namespace std;

class Employee
{
public:
  Employee(const string &, const string &,
           const Date&, const Date&);
  void print() const;

private:
  string firstName; // composition: member object
  string lastName; // composition: member object
  const Date birthDate; // composition: member object
  const Date hireDate; // composition: member object
}; // end class Employee

#endif // EMPLOYEE_H
