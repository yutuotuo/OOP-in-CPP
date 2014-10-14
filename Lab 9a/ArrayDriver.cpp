// Lab 9a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;
using std::istream;

#include "Array.h" // for including custom classes
#include "Array.h" // testing ifndef

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "TestDriver for Array class.\n";
  cout << "-------------------------------\n" << endl;

  // Variable Declaration
  istringstream sin;
  sin.str("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17\n1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17");

  Array integers1(7);
  Array integers2;

  cout << "Size of Array integers1 is " << integers1.getSize()
       << "\nArray after initialization:\n" << integers1;

  cout << "Size of Array integers2 is " << integers2.getSize()
       << "\nArray after initialization:\n" << integers2;

  cout << "\nEnter 27 integers:" << endl;

  sin >> integers1 >> integers2;
  cout << "\nAfter input, the Arrays contain:\n"
       << "integers1:\n" << integers1
       << "integers2:\n" << integers2;

  cout << "\nEvaluating: integers1 != integers2" << endl;

  if (integers1 != integers2)
    cout << "integers1 & integers2 are not equal" << endl;

  Array integers3(integers1);
  cout << "\nSize of Array integers3 is " << integers3.getSize() << "\nArray after init:\n" << integers3;
  cout << "\nAssigning integers2 to integers1:" << endl;

  integers1 = integers2;
  cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;
  cout << "\nEvaluating: integers1 == integers2" << endl << endl;

  if ( integers1 == integers2) cout << "int1 == int2" << endl;
  cout << "\nintegers[5] is " << integers1[5];
  cout << "\n\nAssigning 1000 to int1[5]" << endl;

  integers1[5] = 1000;
  cout << "int1:\n" << integers1;
  cout << "\nAttempt to assign 1000 to integers1[15]" << endl;

  integers1[15] = 1000; // ERROR
} // end main
