// Lab 3a, SalesPerson.h , SalesPerson class definition
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef SalesPerson_h
#define SalesPerson_h

// Member functions defined in SalesPerson.cpp.
class SalesPerson
{
public:
  static const int monthsPerYear = 12; // months in one year
  SalesPerson(); // constructor
  void getSalesFromUser(); // input sales from keyboard
  void setSales(int, double); // set sales for a specific month
  void printAnnualSales(); // summarize and print sales

private:
  double totalAnnualSales(); // prototype for utility function
  double sales[monthsPerYear]; // 12 monthly sales figures
}; // end class SalesPerson

#endif
