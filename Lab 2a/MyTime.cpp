// Lab #a
// Prograaammer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;


// Time class definition
class Time
  {
  public:
    Time(); // constructor
    void setTime( int, int, int ); // set hour, minute, and second
    void printUniversal(); // print time in universal-time format
    void printStandard(); // print time in standard-time format

  private:
    int hour; // 0 - 23 (24 hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
  }; // end class Time

// Time constructor initializes each data member to zero.
// Ensures all Time objects start in a consistent state.
Time::Time()
  {
  hour = minute = second = 0;
  } // end Time constructor

// set new Time value using universal time, ensure that
// the data remains consistent by setting invalid values to zero
void Time::setTime( int h, int m, int s )
  {
  hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
  minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
  second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
  } // end function setTime

// print Time in universal format (HH:MM:SS)
void Time::printUniversal()
  {
  cout << setfill( '0' ) << setw( 2 ) << hour << ":"
       << setw( 2 ) << minute << ":" << setw( 2 ) << second;
  } // end function printUniversal

// print Time in standard format (HH:MM:SS AM or PM)
void Time::printStandard()
  {
  cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":"
       << setfill( '0' ) << setw( 2 ) << minute << ":" << setw( 2 )
       << second << ( hour < 12 ? " AM" : " PM" );
  } // end function printStandard


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                  main                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
  {
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Create a class \"Time\" as shown in Dietel book,\nand modify as per class requirements.\n";
  cout << "-------------------------------\n\n";

  // Variable Declaration
  Time t; // instantiate object t of class Time

  // output Time object t's initial values
  cout << "The initial universal time is ";
  t.printUniversal(); // 00:00:00
  cout << "\nThe initial standard time is ";
  t.printStandard(); // 12:00:00 AM

  t.setTime( 13, 27, 6); // change time

  // output Time object t's new values
  cout << "\n\nUniversal time after setTime is ";
  t.printUniversal(); // 13:27:06
  cout << "\nStandard time after setTime is ";
  t.printStandard(); // 1:27:06 PM

  t.setTime( 99, 99, 99 ); // attempt invalid settings

  // output t's values after specifying invalid values
  cout << "\n\nAfter attempting invalid settings:"
       << "\nUniversal time: ";
  t.printUniversal(); // 00:00:00
  cout << "\nStandard time: ";
  t.printStandard(); // 12:00:00 AM
  cout << endl;

  // Pause Statement
  cout << endl << "Press ENTER to end..." << endl;
  cin.get();
  }
