// Lab 8a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cstdlib>

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include "PhoneNumber.h" // for including custom classes
#include "PhoneNumber.h" // testing ifndef

const int ARRAY_SIZE = 4;

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: Test Driver for PhoneNumber.\n";
  cout << "PhoneNumber overloads stream operators.\n" << endl;
  cout << "-------------------------------\n" << endl;

  istringstream sin; // string input object
  sin.str("(925) 685-1230(800) 555-1234(559) 916-2426(555) 867-5309"); // string input sequence
  PhoneNumber phone[ARRAY_SIZE]; // array of phone objects

  cout << "Enter phone numbers (will be entered in string in cpp):" << endl;
  sin >> phone[0] >> phone[1] >> phone[2] >> phone[3];

  cout << "The phone numbers were: ";
  cout << phone[0];
  for (int i=1; i<ARRAY_SIZE; i++) cout << ", " << phone[i];
  cout << "." << endl;
} // end main
