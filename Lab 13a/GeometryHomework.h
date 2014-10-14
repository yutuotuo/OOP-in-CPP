// Lab 13
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::ios;
using std::ostream;

#ifndef GEOMETRYHOMEWORK_H_INCLUDED
#define GEOMETRYHOMEWORK_H_INCLUDED


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                 Classes               @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Shape // declaration; will be abstract because of pure virtual function
{
protected: // for inheritance
  const double a; // generic value #1
  const double b; // generic value #2
  const double c; // generic value #3

public:
  Shape(const char* const token[]); // constructor declaration
  virtual void print(ostream&) const = 0; // matches derived classes' print()s.
  double setMeasurement(const char* const m);
  virtual ~Shape() {} //virtual destructor
}; // end class Shape

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Circle : public Shape // derives from Shape
{
public:
  Circle(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Circle

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Rectangle : public Shape // derives from Shape
{
public:
  Rectangle(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Rectangle

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Square : public Shape // derives from Shape
{
public:
  Square(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Square

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Cube : public Square // derived from Square
{
public:
  Cube(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Cube

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Cylinder : public Circle // derived from Circle
{
public:
  Cylinder(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Cylinder

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Prism : public Rectangle // derived from Rectangle
{
public:
  Prism(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Prism


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@  stream manipulator prototypes  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ostream& reset(ostream& out);

ostream& set(ostream& out);

ostream& operator<<(ostream& out, const Shape* s);

#endif // GEOMETRYHOMEWORK_H_INCLUDED
