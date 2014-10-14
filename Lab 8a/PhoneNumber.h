// Lab 8a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
using std::istream;
using std::ostream;

#include <string>
using std::string;

class PhoneNumber
{
  friend ostream &operator<<(ostream&, const PhoneNumber&);
  friend istream &operator>>(istream&, PhoneNumber&);
private:
  string areaCode; // 3-digit area code
  string exchange; // 3-digit exchange
  string line; // 4-digit line
}; // end class PhoneNumber

#endif // PHONENUMBER_H
