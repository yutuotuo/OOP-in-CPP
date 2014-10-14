// Lab 3a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "SalesPerson.h"
#include "SalesPerson.h" // testing ifndef

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: TestDriver for SalesPerson.cpp for\n";
  cout << "testing functionality.\n\n";

  SalesPerson salesPerson; // this satisfies the Constructor test
  cout << "   Input: 123 234 345 456 567 678 789 890 901 1012 1123 1234\n"
  << "   (Expect $8352.00): " << endl;

  // ...test all getters and setters
  salesPerson.getSalesFromUser(); // input sales from keyboard
  salesPerson.printAnnualSales();

  // object copy testing, with assignment UPON declaration
  {
    SalesPerson copy = salesPerson;
    cout << "\n\n  Copy 1 created with assignment upon declaration."
    << "\n  Print of copy 1 below:"<< endl;
    // ...use getters to confirm that copy's contents match salesPerson's
    copy.printAnnualSales();

    // test the setSales function
    cout << "\n   Let's make sure everything is still functioning. NEW input:\n"
    << "   110.7 210.6 310.5 410.4 510.3 610.2 710.1 801 810.9 910.8 1010.7 1110.6\n"
    << "   (Expect $7516.80): " << endl;
    copy.getSalesFromUser(); // input sales from keyboard
    cout << "\n   Original = ";
    salesPerson.printAnnualSales();
    cout << "\n   Updated copy = ";
    copy.printAnnualSales();
  } // end of scope: "copy" is gone, can be re-created and re-assigned below.

  // object copy testing, with assignment AFTER declaration
  {
    SalesPerson copy; copy = salesPerson;
    cout << "\n\n  Copy 2 created of original with assignment AFTER declaration."
    << "\n  Print of copy 2 below:" << endl;
    //...use getters to confirm that copy's contents match salesPerson's
    copy.printAnnualSales();

    // test the setSales function
    cout << "\n   Make sure everything is still functioning. Last input:\n"
    << "   135.3 257.4 379.5 501.6 623.7 745.8 867.9 979 991.1 1113.2 1235.3 1357.4\n"
    << "   (Expect $9187.20): " << endl;
    copy.getSalesFromUser(); // input sales from keyboard
    cout << "\n   Original = ";
    salesPerson.printAnnualSales();
    cout << "\n   Updated copy = ";
    copy.printAnnualSales();
  }

  cout << "\n\nFinally, we'll call salesPerson.setSales directly and change\n"
  << "May (5) from \"567\" to \"8265\". We will expect \"$16050.00\":" << endl;
  salesPerson.setSales(5, 8265);
  salesPerson.printAnnualSales();
}
