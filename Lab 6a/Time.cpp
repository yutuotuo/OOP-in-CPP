// Lab 6a: Time.cpp
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

// Time class member function definitions.
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::setfill;
using std::setw;

#include "Time.h" // Time class definition

// Constructor function to initialize private data;
// Calls member function setTime to set variables;
// Default values are 0 (see class definition)
Time::Time(int hr, int min, int sec)
{
  setTime(hr, min, sec);
} // end Time constructor

// Set the values of hour, minute, and second.
Time &Time::setTime(int h, int m, int s) // note Time& return
{
  setHour(h);
  setMinute(m);
  setSecond(s);
  return *this; // enables cascading
} // end function setTime

// set hour value
Time &Time::setHour(int h) // note Time& return
{
  hour = (h >= 0 && h < 24)? h : 0; // validate hour
  return *this; // enables cascading
} // end function setHour

// set minute value
Time &Time::setMinute(int m) // note Time& return
{
  minute = (m >= 0 && m < 60)? m : 0; // validate minute
  return *this; // enable cascading
}

// set second value
Time &Time::setSecond(int s) // note Time& return
{
  second = (s >= 0 && s < 60)? s : 0; // validate second
  return *this; // enables cascading
} // end function setSecond

// get hour value
int Time::getHour() const
{
  return hour;
} // end function getHour

// get minute value
int Time::getMinute() const
{
  return minute;
} // end function getMinute

// get second value
int Time::getSecond() const
{
  return second;
} // end function getSecond

// print Time in universal-time format: (HH:MM:SS)
void Time::printUniversal() const
{
  cout << setfill('0') << setw(2) << hour << ":"
       << setw(2) << minute << ":" << setw(2) << second;
} // end function printUniversal

// print Time in standard-time format: (HH:MM:SS AM or PM)
void Time::printStandard() const
{
  cout << ((hour == 0 || hour == 12)? 12 : hour % 12)
       << ":" << setfill('0') << setw(2) << minute
       << ":" << setw(2) << second << (hour < 12? " AM" : " PM");
} // end function printStandard
