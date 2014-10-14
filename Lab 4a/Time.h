// Lab 4a, Time.h, Time class definition
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef TIME_H
#define TIME_H

class Time
{
public:
  Time(int=0, int=0, int=0); // default constructor

  // set functions
  void setTime(int, int, int); // set time
  void setHour(int); // set hour
  void setMinute(int); // set minute
  void setSecond(int); // set second

  // get functions (normally declared const)
  int getHour() const; // return hour
  int getMinute() const; // return minute
  int getSecond() const; // return second

  // print functions (normally declared const)
  void printUniversal() const; // print universal time
  void printStandard() const; // print standard time

private:
  int hour; // 0 - 23 (24-hour clock format)
  int minute; // 0 - 59
  int second; // 0 - 59
}; // end class Time

#endif // TIME_H
