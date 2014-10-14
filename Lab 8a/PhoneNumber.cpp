// Lab 8a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iomanip>
using std::setw;

#include <iostream>
using std::istream;
using std::ostream;
using std::ios;

#include "PhoneNumber.h"

// overloaded stream insertion operator
ostream &operator<<(ostream &output, const PhoneNumber &number)
{
  output << "(" << number.areaCode << ")"
         << number.exchange << "-" << number.line;
  return output; // enables cout << a << b << c;
} // end function operator<<

// overloaded stream extraction operator
istream &operator>>(istream &input, PhoneNumber &number)
{
  input.ignore(); // skip (
  input >> setw(3) >> number.areaCode; // input area code
  input.ignore(2); // skip ) and space
  input >> setw(3) >> number.exchange; // input exchange
  input.ignore(); // skip dash(-)
  input >> setw(4) >> number.line; // input line
  return input; // enables cin >> a >> b >> c;
} // end function operator>>
