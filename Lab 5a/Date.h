// Lab 5a - Date header
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef DATE_H
#define DATE_H

class Date
{
public:
  static const int monthsPerYear = 12; // number of months in a year
  Date(int = 1, int = 1, int = 1900); // default constructor
  void print() const; // print date in month/day/year format
private:
  int month; // 1 - 12 (January - December)
  int day; // 1 - 31 based on month
  int year; // any year

  // Utility function to check if day is proper for month and year
  int checkDay(int) const;
}; // end class Date

#endif // DATE_H
