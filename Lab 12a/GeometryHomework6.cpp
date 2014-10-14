// Lab 12
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

#include <vector>
using std::vector;


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

class Shape // declaration; will be abstract because of pure virtual function
{
protected: // for inheritance
  const double a; // generic value #1
  const double b; // generic value #2
  const double c; // generic value #3

public:
  Shape(const char* const token[]); // constructor declaration
  virtual void print(ostream&) const = 0; // matches derived classes' print()s.
  virtual ~Shape() {} //virtual destructor
}; // end class Shape

Shape::Shape(const char* const token[]): a((token[1])? atof(token[1]) : 0),
                                         b((token[2])? atof(token[2]) : 0),
                                         c((token[3])? atof(token[3]) : 0) {}// constructor declaration

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Circle : public Shape // derives from Shape
{
public:
  Circle(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Circle

Circle::Circle(const char* const token[]):Shape(token) {} // constructor definition with variable assigned
void Circle::print(ostream& out) const // print getter function definition
{
  out << "CIRCLE:    radius= " << a;
  out << set;
  out << ", area=" << (PI*(a*a)) << ", circumference=" << (2*(PI*a)) << endl;
  out << reset;
}


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Rectangle : public Shape // derives from Shape
{
public:
  Rectangle(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Rectangle

Rectangle::Rectangle(const char* const token[]):Shape(token) {}
void Rectangle::print(ostream& out) const // print getter function definition
{
  out << "RECTANGLE: length= " << a << ", width=" << b;
  out << set;
  out << ", area=" << (a*b) << ", perimeter=" << ((2*a)+(2*b)) << endl;
  out << reset;
}


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Square : public Shape // derives from Shape
{
public:
  Square(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Square

Square::Square(const char* const token[]): Shape(token) {}
void Square::print(ostream& out) const // print getter function definition
{
  out << "SQUARE:    side=   " << a;
  out << set;
  out << ", area=" << (a*a) << ", perimeter=" << (a*4) << endl;
  out << reset;
}


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Cube : public Square // derived from Square
{
public:
  Cube(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Cube

Cube::Cube(const char* const token[]):Square(token) {} // definition through inheritance
void Cube::print(ostream& out) const // print getter function definition
{
  out << "CUBE:      side=   " << a;
  out << set;
  out << ", surface area=" << (6*(a*a)) << ", volume=" << (a*(a*a)) << endl;
  out << reset;
}


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Cylinder : public Circle // derived from Circle
{
public:
  Cylinder(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Cylinder

Cylinder::Cylinder(const char* const token[]):Circle(token) {} // inherited constructor definition
void Cylinder::print(ostream& out) const // print getter function definition
{
  out << "CYLINDER:  radius= " << a << ", height=" << b;
  out << set;
  out << ", surface area=" << ((2*(PI*(a*a))) + (2*(PI*(a*b)))) << ", volume=" << (b*(PI*(a*a))) << endl;
  out << reset;
}


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

class Prism : public Rectangle // derived from Rectangle
{
public:
  Prism(const char* const token[]); // constructor declaration
  void print(ostream&) const; // print getter function declaration
}; // end class Prism

Prism::Prism(const char* const token[]):Rectangle(token) {}
void Prism::print(ostream& out) const // print getter function definition
{
  out << "PRISM:     length= " << a << ", width=" << b << ", height=" << c;
  out << set;
  out << ", surface area=" << ((2*(a*b)) + (2*(b*c)) + (2*(a*c))) << ", volume=" << ((a*b)*c) << endl;
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
  cout << "Polymorphism, abstract, and virtual ideas.\n";
  cout << "-------------------------------" << endl << endl;

  // Variable Declaration
  string const filename = "geo.txt";
  vector<const Shape*> shapes;
  char CIRCLE[] = "CIRCLE", CUBE[] = "CUBE", CYLINDER[]="CYLINDER", PRISM[] = "PRISM", RECTANGLE[]="RECTANGLE", SQUARE[]="SQUARE";

  // Read from file
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
    } // end if (tokenizer)

    if (token[0]) // create classes from tokens and point shapes vector to them.
    {
      if(strcmp(token[0],CIRCLE) == 0) shapes.push_back(new Circle(token));
      else if(strcmp(token[0],CUBE) == 0) shapes.push_back(new Cube(token));
      else if(strcmp(token[0],CYLINDER) == 0) shapes.push_back(new Cylinder(token));
      else if(strcmp(token[0],PRISM) == 0) shapes.push_back(new Prism(token));
      else if(strcmp(token[0],RECTANGLE) == 0) shapes.push_back(new Rectangle(token));
      else if(strcmp(token[0],SQUARE) == 0) shapes.push_back(new Square(token));
      else cout << "   ERROR:  \"" << token[0] << "\" is an invalid object" << endl;
    } // end if (class creator)
  } // end fin.open
  fin.close();
  fin.clear();


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@             print output              @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int n=0; n<shapes.size(); n++) // traverse vector and print all members
  {
    if(shapes[n]) shapes[n]->print(cout);
    else cout << "Error! Cannot call \"shapes[" << n << "]->print(cout)\"!" << endl;
  } // end for; all objects are printed

  for (int n=0; n<shapes.size(); n++)
  {
    delete shapes[n]; // Loop to deallocate all dynamically-allocated memory
  }
} // end main
