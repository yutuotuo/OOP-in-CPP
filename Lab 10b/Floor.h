// Lab 10b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef FLOOR_H
#define FLOOR_H

class Floor
{
public:
  Floor(int loc) : location(loc) {}// set floor location via public constructor

  // get functions
  int getLocation() const {return location;} // return location

private:
  const int location; // location of floor in inches above ground
}; // end class Floor

#endif // FLOOR_H
