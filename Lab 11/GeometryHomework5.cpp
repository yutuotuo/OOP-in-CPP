// Lab 11
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cmath>
#include <cstdlib>
#include <cstring>

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <iomanip>
using std::setprecision;
using std::setw;
using std::fixed;

#include <string>
using std::getline;
using std::string;


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@           Constant declares           @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";
const double PI = atan(1.0)*4;


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@            functions           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// output stream manipulators
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                 Classes               @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Circle // declare
{
protected: // for inheritance
  const double radius;

public:
  Circle(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Circle

// class definitions:
Circle::Circle(const char* const token[]):radius(atof(token[1])) {} // constructor definition with variable assigned

void Circle::print(ostream& out) const // print getter function definition
{
  out << "CIRCLE:    radius= " << radius;
  out << set;
  out << ", area=" << (PI*(radius*radius)) << ", circumference=" << (2*(PI*radius)) << endl;
  out << reset;
}


/*//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

class Rectangle // declare
{
protected: // for inheritance
  const double length;
  const double width;

public:
  Rectangle(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Rectangle

// class definitions:
Rectangle::Rectangle(const char* const token[]): length(atof(token[1])), width(atof(token[2])) {}// constructor declaration

void Rectangle::print(ostream& out) const // print getter function definition
{
  out << "RECTANGLE: length= " << length << ", width=" << width;
  out << set;
  out << ", area=" << (length*width) << ", perimeter=" << ((2*length)+(2*width)) << endl;
  out << reset;
}


/*//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

class Square // declare
{
protected: // for inheritance
  const double side;

public:
  Square(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Square

// class definitions:
Square::Square(const char* const token[]):side(atof(token[1])) {}

void Square::print(ostream& out) const // print getter function definition
{
  out << "SQUARE:    side=   " << side;
  out << set;
  out << ", area=" << (side*side) << ", perimeter=" << (side*4) << endl;
  out << reset;
}


/*//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

class Cube : public Square // derived from Square
{
public:
  Cube(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Cube

// class definitions:
Cube::Cube(const char* const token[]):Square(token){} // definition through inheritance

void Cube::print(ostream& out) const // print getter function definition
{
  out << "CUBE:      side=   " << side;
  out << set;
  out << ", surface area=" << (6*(side*side)) << ", volume=" << (side*(side*side)) << endl;
  out << reset;
}


/*//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

class Cylinder : public Circle // derived from Circle
{
private:
  const double height;

public:
  Cylinder(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Cylinder

// class definitions:
Cylinder::Cylinder(const char* const token[]):Circle(token), height(atof(token[2])) {} // inherited constructor definition

void Cylinder::print(ostream& out) const // print getter function definition
{
  out << "CYLINDER:  radius= " << radius << ", height=" << height;
  out << set;
  out << ", surface area=" << ((2*(PI*(radius*radius))) + (2*(PI*(radius*height)))) << ", volume=" << (height*(PI*(radius*radius))) << endl;
  out << reset;
}


/*//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

class Prism : public Rectangle // derived from Rectangle
{
private:
  const double height;

public:
  Prism(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Prism

// class definitions:
Prism::Prism(const char* const token[]):Rectangle(token), height(atof(token[3])) {} // constructor implementing inheritance

void Prism::print(ostream& out) const // print getter function definition
{
  out << "PRISM:     length= " << length << ", width=" << width << ", height=" << height;
  out << set;
  out << ", surface area=" << ((2*(length*width)) + (2*(width*height)) + (2*(height*length))) << ", volume=" << ((length*width)*height) << endl;
  out << reset;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      main        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: modify GeometryHomework to apply\n";
  cout << "the techniques we've learned in class.\n";
  cout << "-------------------------------" << endl << endl;

  // Variable Declaration
  string const filename = "geo.txt";
  char CIRCLE[] = "CIRCLE", CUBE[] = "CUBE", CYLINDER[]="CYLINDER", PRISM[] = "PRISM", RECTANGLE[]="RECTANGLE", SQUARE[]="SQUARE";
  int i=0; // index counter
  const void* shapes [100] = {};
  int shapeId[100] = {}; // 1=Circle, 2=Cube, 3=Cylinder, 4=Prism, 5=Rectangle, 6=Square.

  ifstream fin; // create a file-reading object
  fin.open(filename.c_str()); // open a file
  if (!fin.good())
    return 1; // exit if file not found

  while (!fin.eof()) // read each line of the file
  {
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE); // read an entire line into memory

    int n = 0; // a for-loop index
    const char* token[MAX_TOKENS_PER_LINE] = {}; // array to store memory addresses of the tokens in buf; initialize to 0

    token[0] = strtok(buf, DELIMITER); // parse the line: first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }
    }

    if (token[0]) // create classes from tokens and point shapes[] to them.
    {
      // 1=Circle, 2=Cube, 3=Cylinder, 4=Prism, 5=Rectangle, 6=Square.
      if(strcmp(token[0],CIRCLE) == 0)
      {
        const Circle* const c = new Circle(token);
        shapes[i] = c;
        shapeId[i] = 1;
        i++;
      }

      else if(strcmp(token[0],CUBE) == 0)
      {
        const Cube* const c = new Cube(token);
        shapes[i] = c;
        shapeId[i] = 2;
        i++;
      }

      else if(strcmp(token[0],CYLINDER) == 0)
      {
        const Cylinder* const c = new Cylinder(token);
        shapes[i] = c;
        shapeId[i] = 3;
        i++;
      }

      else if(strcmp(token[0],PRISM) == 0)
      {
        const Prism* const p = new Prism(token);
        shapes[i] = p;
        shapeId[i] = 4;
        i++;
      }

      else if(strcmp(token[0],RECTANGLE) == 0)
      {
        const Rectangle* const r = new Rectangle(token);
        shapes[i] = r;
        shapeId[i] = 5;
        i++;
      }

      else if(strcmp(token[0],SQUARE) == 0)
      {
        const Square* const s = new Square(token);
        shapes[i] = s;
        shapeId[i] = 6;
        i++;
      }

      else cout << "   ERROR:  " << token[0] << " is an invalid object" << endl;
    } // end class maker
  } // end fin.open
  fin.close();
  fin.clear();


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@             print output              @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int n=0; n<i; n++) // traverse array in loop and call print functions
  {
    switch(shapeId[n]) // 1=Circle, 2=Cube, 3=Cylinder, 4=Prism, 5=Rectangle, 6=Square.
    {
    case 1: ((Circle*)shapes[n])->print(cout); break;
    case 2: ((Cube*)shapes[n])->print(cout); break;
    case 3: ((Cylinder*)shapes[n])->print(cout); break;
    case 4: ((Prism*)shapes[n])->print(cout); break;
    case 5: ((Rectangle*)shapes[n])->print(cout); break;
    case 6: ((Square*)shapes[n])->print(cout); break;
    default: cout << "Error! Shape type not recognized from shapeID[]" << endl;
    } //End switch()
  } // end for; all objects are printed

  // Loop to deallocate all dynamically-allocated memory
  for (int n=0; n<i; n++)
  {
    switch(shapeId[n])
    {
    case 1: delete ((Circle*)shapes[n]); break;
    case 2: delete (Cube*)shapes[n]; break;
    case 3: delete (Cylinder*)shapes[n]; break;
    case 4: delete (Prism*)shapes[n]; break;
    case 5: delete (Rectangle*)shapes[n]; break;
    case 6: delete (Square*)shapes[n]; break;
    default: cout << "Error! Shape type not recognized (from shapeID[])" << endl;
    } //End switch()
  }

} // end main
