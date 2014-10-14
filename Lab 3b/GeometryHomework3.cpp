// Lab 3b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <cmath>
#include <cstdlib>
#include <cstring>

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;

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
void resetDecimal()
{
  // 2-line code to unformat, so show a number "as is"
  cout.unsetf(ios::fixed|ios::showpoint); // undoes "fixed" and "showpoint"
  cout << setprecision(6); // resets precision to its default
}
void setDecimal()
{
  // Set decimal precision to 2 digits
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2); // applies until set to something else
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@                 Classes               @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Circle // declare
{
private:
  double radius;

public:
  Circle(const char* token[]); // constructor declaration
  void print() const; // print getter function declaration
}; // end class Circle

// class definitions:
Circle::Circle(const char* token[]) //  constructor definition with variable assigned
{
  radius = token[1]?atof(token[1]):0;
}
void Circle::print() const // print getter function definition
{
  cout << "CIRCLE:    radius=" << radius;
  setDecimal();
  cout << ", area=" << (PI*(radius*radius)) << ", circumference=" << (2*(PI*radius)) << endl;
  resetDecimal();
}


class Cube // declare
{
private:
  double side;

public:
  Cube(const char* token[]); // constructor declaration
  void print() const; // print getter function declaration
}; // end class Cube

// class definitions:
Cube::Cube(const char* token[]) // constructor definition
{
  side = token[1]?atof(token[1]):0;
}
void Cube::print() const // print getter function definition
{
  cout << "CUBE:      side=" << side;
  setDecimal();
  cout << ", surface area=" << (6*(side*side)) << ", volume=" << (side*(side*side)) << endl;
  resetDecimal();
}


class Cylinder // declare
{
private:
  double radius;
  double height;

public:
  Cylinder(const char* token[]); // constructor declaration
  void print() const; // print getter function declaration
}; // end class Cylinder

// class definitions:
Cylinder::Cylinder(const char* token[]) // constructor definition
{
  radius = token[1]?atof(token[1]):0;
  height = token[2]?atof(token[2]):0;
}
void Cylinder::print() const // print getter function definition
{
  cout << "CYLINDER:  radius=" << radius << ", height=" << height;
  setDecimal();
  cout << ", surface area=" << ((2*(PI*(radius*radius))) + (2*(PI*(radius*height)))) << ", volume=" << (height*(PI*(radius*radius))) << endl;
  resetDecimal();
}

class Prism // declare
{
private:
  double length;
  double width;
  double height;

public:
  Prism(const char* token[]); // constructor declaration
  void print() const; // print getter function declaration
}; // end class Prism

// class definitions:
Prism::Prism(const char* token[]) // constructor definition
{
  length = token[1]?atof(token[1]):0;
  width = token[2]?atof(token[2]):0;
  height = token[3]?atof(token[3]):0;
}
void Prism::print() const // print getter function definition
{
  cout << "PRISM:     length=" << length << ", width=" << width << ", height=" << height;
  setDecimal();
  cout << ", surface area=" << ((2*(length*width)) + (2*(width*height)) + (2*(height*length))) << ", volume=" << ((length*width)*height) << endl;
  resetDecimal();
}


class Rectangle // declare
{
private:
  double length;
  double width;

public:
  Rectangle(const char* token[]); // constructor declaration
  void print() const; // print getter function declaration
}; // end class Rectangle

// class definitions:
Rectangle::Rectangle(const char* token[]) // constructor declaration
{
  length = token[1]?atof(token[1]):0;
  width = token[2]?atof(token[2]):0;
}
void Rectangle::print() const // print getter function definition
{
  cout << "RECTANGLE: length=" << length << ", width=" << width;
  setDecimal();
  cout << ", area=" << (length*width) << ", perimeter=" << ((2*length)+(2*width)) << endl;
  resetDecimal();
}


class Square // declare
{
private:
  double side;

public:
  Square(const char* token[]); // constructor declaration
  void print() const; // print getter function declaration
}; // end class Square

// class definitions:
Square::Square(const char* token[]) // constructor definition
{
  side = token[1]?atof(token[1]):0;
}
void Square::print() const // print getter function definition
{
  cout << "SQUARE:    side=" << side;
  setDecimal();
  cout << ", area=" << (side*side) << ", perimeter=" << (side*4) << endl;
  resetDecimal();
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      main        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: modify GeometryHomework2 so shapes are\n";
  cout << "objects rather than structs.\n";
  cout << "-------------------------------\n\n";

  // Variable Declaration
  string filename = "geo.txt";
  int i=0; // index counter
  void* shapes[100];
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
      if((string)token[0] == "CIRCLE")
      {
        Circle* c = new Circle(token);
        shapes[i] = c;
        shapeId[i] = 1;
        i++;
      }

      else if((string)token[0] == "CUBE")
      {
        Cube* c = new Cube(token);
        shapes[i] = c;
        shapeId[i] = 2;
        i++;
      }

      else if((string)token[0] == "CYLINDER")
      {
        Cylinder* c = new Cylinder(token);
        shapes[i] = c;
        shapeId[i] = 3;
        i++;
      }

      else if((string)token[0] == "PRISM")
      {
        Prism* p = new Prism(token);
        shapes[i] = p;
        shapeId[i] = 4;
        i++;
      }

      else if((string)token[0] == "RECTANGLE")
      {
        Rectangle* r = new Rectangle(token);
        shapes[i] = r;
        shapeId[i] = 5;
        i++;
      }

      else if((string)token[0] == "SQUARE")
      {
        Square* s = new Square(token);
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
    case 1: ((Circle*)shapes[n])->print(); break;
    case 2: ((Cube*)shapes[n])->print(); break;
    case 3: ((Cylinder*)shapes[n])->print(); break;
    case 4: ((Prism*)shapes[n])->print(); break;
    case 5: ((Rectangle*)shapes[n])->print(); break;
    case 6: ((Square*)shapes[n])->print(); break;
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
  } // end for

} // end main
