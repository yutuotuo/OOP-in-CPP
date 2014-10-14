// Lab 2b
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
//@@@@@@@@@@@@@@@@@@@@@@           structs definitions         @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
struct Square
  {
  double side;
  }; // end Square struct // "Square mySquare;"

struct Rectangle
  {
  double length;
  double width;
  }; // end Rectangle struct

struct Circle
  {
  double radius;
  }; // end Circle struct

struct Cube
  {
  double side;
  }; // end Cube struct

struct Prism
  {
  double length;
  double width;
  double height;
  }; // end Prism struct

struct Cylinder
  {
  double radius;
  double height;
  }; // end Cylinder struct


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

void printSquare(Square* s) //side
  {
  double num1 = s->side;
  cout << "SQUARE:    side=" << num1;
  setDecimal();
  cout << ", area=" << (num1*num1) << ", perimeter=" << (num1*4) << endl;
  resetDecimal();
  }

void printRectangle(Rectangle* r) //length, width
  {
  double num1 = r->length;
  double num2 = r->width;
  cout << "RECTANGLE: length=" << num1 << ", width=" << num2;
  setDecimal();
  cout << ", area=" << (num1*num2) << ", perimeter=" << ((2*num1)+(2*num2)) << endl;
  resetDecimal();
  }

void printCircle(Circle* c) //radius
  {
  double num1 = c->radius;
  cout << "CIRCLE:    radius=" << num1;
  setDecimal();
  cout << ", area=" << (PI*(num1*num1)) << ", circumference=" << (2*(PI*num1)) << endl;
  resetDecimal();
  }

void printCube(Cube* c) //side
  {
  double num1 = c->side;
  cout << "CUBE:      side=" << num1;
  setDecimal();
  cout << ", surface area=" << (6*(num1*num1)) << ", volume=" << (num1*(num1*num1)) << endl;
  resetDecimal();
  }

void printPrism(Prism* p) //length, width, height
  {
  double num1 = p->length;
  double num2 = p->width;
  double num3 = p->height;
  cout << "PRISM:     length=" << num1 << ", width=" << num2 << ", height=" << num3;
  setDecimal();
  cout << ", surface area=" << ((2*(num1*num2)) + (2*(num2*num3)) + (2*(num3*num1))) << ", volume=" << ((num1*num2)*num3) << endl;
  resetDecimal();
  }

void printCylinder(Cylinder* c) //radius, height
  {
  double num1 = c->radius;
  //cout << "Cylinder=" << c->radius << endl; // FOR TESTING
  double num2 = c->height;
  cout << "CYLINDER:  radius=" << num1 << ", height=" << num2;
  setDecimal();
  cout << ", surface area=" << ((2*(PI*(num1*num1))) + (2*(PI*(num1*num2)))) << ", volume=" << (num2*(PI*(num1*num1))) << endl;
  }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      main        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
  {
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: modify GeometryHomework1 so an array\n";
  cout << "of structs is accessible with void* pointer.\n";
  cout << "-------------------------------\n\n";

  // Variable Declaration
  string filename;
  int i=0; // index counter
  filename = "geo.txt";
  void* shapes[100];
  int shapeId[100] = {}; // 1=Square, 2=Rectangle, 3=Circle, 4=Cube, 5=Prism, and 6=Cylinder.

  // create a file-reading object
  ifstream fin;
  fin.open(filename.c_str()); // open a file
  if (!fin.good())
    return 1; // exit if file not found

  // read each line of the file
  while (!fin.eof())
    {
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);

    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index

    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
      {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
        {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
        }
      }

    if (token[0]) // struct maker
      {
      string shapeName = token[0];// make string from token for string comparison
      // create structs from tokens and point shapes[] to them.
      if(shapeName == "SQUARE")
        {
        Square* s = new Square;
        s->side = 0;
        if (token[1]) s->side = atof(token[1]);
        shapes[i] = s;
        shapeId[i] = 1;
        i++;
        }
      else if(shapeName == "RECTANGLE")
        {
        Rectangle* r = new Rectangle;
        r->length = 0; r->width = 0;
        if (token[1]) r->length = atof(token[1]);
        if (token[2]) r->width = atof(token[2]);
        shapes[i] = r;
        shapeId[i] = 2;
        i++;
        }
      else if(shapeName == "CIRCLE")
        {
        Circle* c = new Circle;
        c->radius = 0;
        if (token[1]) c->radius = atof(token[1]);
        shapes[i] = c;
        shapeId[i] = 3;
        i++;
        }
      else if(shapeName == "CUBE")
        {
        Cube* c = new Cube;
        c->side = 0;
        if (token[1]) c->side = atof(token[1]);
        shapes[i] = c;
        shapeId[i] = 4;
        i++;
        }
      else if(shapeName == "PRISM")
        {
        Prism* p = new Prism;
        p->length = 0;
        p->width = 0;
        p->height = 0;
        if (token[1]) p->length = atof(token[1]);
        if (token[2]) p->width = atof(token[2]);
        if (token[3]) p->height = atof(token[3]);
        shapes[i] = p;
        shapeId[i] = 5;
        i++;
        }
      else if(shapeName == "CYLINDER")
        {
        Cylinder* c = new Cylinder;
        c->radius = 0;
        c->height = 0;
        if (token[1]) c->radius = atof(token[1]);
        if (token[12]) c->height = atof(token[2]);
        shapes[i] = c;
        shapeId[i] = 6;
        i++;
        }
      else cout << "   ERROR:  " << token[0] << " is an invalid object" << endl;
      } // end struct maker
    } // end fin.open
  fin.close();
  fin.clear();


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@             print output                 @@@@@@@@@@@@@@@@@@@@@@@@@@@
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  for (int n=0; n<i; n++) // traverse array in loop and call print functions
    {
    switch(shapeId[n])
      {
    case 1: printSquare((Square*)shapes[n]); break;
    case 2: printRectangle((Rectangle*)shapes[n]); break;
    case 3: printCircle((Circle*)shapes[n]); break;
    case 4: printCube((Cube*)shapes[n]); break;
    case 5: printPrism((Prism*)shapes[n]); break;
    case 6: printCylinder((Cylinder*)shapes[n]); break;
    default: cout << "Error! Shape type not recognized (from shapeID[])" << endl;
      } //End switch()
    } // end for

  //* After printing all of the objects, deallocate all dynamically-allocated memory
  //in a loop (using for example, delete (Square*)shapes[i];).
  for (int n=0; n<i; n++) // traverse array in loop and call print functions
    {
    switch(shapeId[n])
      {
    case 1: delete (Square*)shapes[n]; break;
    case 2: delete (Rectangle*)shapes[n]; break;
    case 3: delete (Circle*)shapes[n]; break;
    case 4: delete (Cube*)shapes[n]; break;
    case 5: delete (Prism*)shapes[n]; break;
    case 6: delete (Cylinder*)shapes[n]; break;
    default: cout << "Error! Shape type not recognized (from shapeID[])" << endl;
      } //End switch()
    } // end for


  // Pause Statement
  cout << endl << "Press ENTER to end..." << endl;
  cin.get();
  } // end main
