// Lab 13
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
using std::cin; //////////////////// TEMP!!!!!!!!!!!!!!!

#include <iomanip>
using std::setprecision;
using std::setw;
using std::fixed;

#include <string>
using std::getline;
using std::string;

#include <vector>
using std::vector;

#include "GeometryHomework.h"


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@           Constant declares           @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";


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
    }

    if (token[0]) // create classes from tokens and point shapes vector to them.
    {
      if((string)token[0] == "CIRCLE") shapes.push_back(new Circle(token));
      else if((string)token[0] == "CUBE") shapes.push_back(new Cube(token));
      else if((string)token[0] == "CYLINDER") shapes.push_back(new Cylinder(token));
      else if((string)token[0] == "PRISM") shapes.push_back(new Prism(token));
      else if((string)token[0] == "RECTANGLE") shapes.push_back(new Rectangle(token));
      else if((string)token[0] == "SQUARE") shapes.push_back(new Square(token));
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

  // PRINTING 2
  cout << endl << endl << endl << "----- Printing every even shape using << -----" << endl;
  for (int n=0; n<(shapes.size())-2; n++) // traverse vector and print all members
  {
    if(shapes[n]) cout << shapes[n];
    else cout << "Error! Cannot call \"shapes[" << n << "]->print(cout)\"!" << endl;
    n++;
  } // end for; all objects are printed

  for (int n=0; n<shapes.size(); n++)
  {
    delete shapes[n]; // Loop to deallocate all dynamically-allocated memory
  }


  // PRINTING 3
  cout << endl << endl << endl << "----- Declaring Circle object -----" << endl;

  const char* token[MAX_TOKENS_PER_LINE] = {}; // array to store memory addresses of the tokens in buf; initialize to 0
  token[0] = "0"; // parse the line: first token
  token[1] = "23.4"; // parse the line: first token
  token[2] = "2"; // parse the line: first token
  token[3] = "56"; // parse the line: first token
  Shape* c= new Circle(token);
  cout << "... And printing. Expect '23.4'." << endl;
  //cout << (Shape*)c;
  //cout << (Shape)c;
  //c.print();
  cout << c;
  delete c;



} // end main
