// Lab 13
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cmath>
#include <cstdlib>

#include <iostream>
using std::endl;
using std::ios;
using std::ostream;

#include <iomanip>
using std::setprecision;
using std::setw;
using std::fixed;

#include "GeometryHomework.h"

const double PI = atan(1.0)*4;


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@   output stream manipulators   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ostream& reset(ostream& out)
{
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  return out;
}

ostream& set(ostream& out)
{
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  return out;
}

ostream& operator<<(ostream& out, const Shape* s)
{
  s->print(out);
  return out;
}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                 Classes               @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Shape::Shape(const char* const token[]): a(atof(token[1])), b(setMeasurement(token[2])), c(setMeasurement(token[3])) {}// constructor declaration
double Shape::setMeasurement(const char* const m)
{
  return m?atof(m):0; // end setMeasurement
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Circle::Circle(const char* const token[]):Shape(token) {} // constructor definition with variable assigned
void Circle::print(ostream& out) const // print getter function definition
{
  out << "CIRCLE:    radius= " << a;
  out << set;
  out << ", area=" << (PI*(a*a)) << ", circumference=" << (2*(PI*a)) << endl;
  out << reset;
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Rectangle::Rectangle(const char* const token[]):Shape(token) {}
void Rectangle::print(ostream& out) const // print getter function definition
{
  out << "RECTANGLE: length= " << a << ", width=" << b;
  out << set;
  out << ", area=" << (a*b) << ", perimeter=" << ((2*a)+(2*b)) << endl;
  out << reset;
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Square::Square(const char* const token[]): Shape(token) {}
void Square::print(ostream& out) const // print getter function definition
{
  out << "SQUARE:    side=   " << a;
  out << set;
  out << ", area=" << (a*a) << ", perimeter=" << (a*4) << endl;
  out << reset;
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Cube::Cube(const char* const token[]):Square(token) {} // definition through inheritance
void Cube::print(ostream& out) const // print getter function definition
{
  out << "CUBE:      side=   " << a;
  out << set;
  out << ", surface area=" << (6*(a*a)) << ", volume=" << (a*(a*a)) << endl;
  out << reset;
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Cylinder::Cylinder(const char* const token[]):Circle(token) {} // inherited constructor definition
void Cylinder::print(ostream& out) const // print getter function definition
{
  out << "CYLINDER:  radius= " << a << ", height=" << b;
  out << set;
  out << ", surface area=" << ((2*(PI*(a*a))) + (2*(PI*(a*b)))) << ", volume=" << (b*(PI*(a*a))) << endl;
  out << reset;
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

Prism::Prism(const char* const token[]):Rectangle(token) {}
void Prism::print(ostream& out) const // print getter function definition
{
  out << "PRISM:     length= " << a << ", width=" << b << ", height=" << c;
  out << set;
  out << ", surface area=" << ((2*(a*b)) + (2*(b*c)) + (2*(a*c))) << ", volume=" << ((a*b)*c) << endl;
  out << reset;
}
