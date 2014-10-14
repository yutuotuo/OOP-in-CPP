// Lab 1b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

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
//@@@@@@@@@@@@@@@@@@@@@@        GeometryCalculator  Class      @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class GeometryCalculator
  {
  public:
    // Constructor 4
    GeometryCalculator(string shape, string tk1, string tk2, string tk3)
      {
      setShapeName(shape);
      setNum1(tk1);
      setNum2(tk2);
      setNum3(tk3);
      Calculator();
      } // end constructor

    // Constructor 3
    GeometryCalculator(string shape, string tk1, string tk2)
      {
      setShapeName(shape);
      setNum1(tk1);
      setNum2(tk2);
      Calculator();
      } // end constructor

    // Constructor 2
    GeometryCalculator(string shape, string tk1)
      {
      setShapeName(shape);
      setNum1(tk1);
      Calculator();
      } // end constructor

    // Constructor 1
    GeometryCalculator(string shape)
      {
      setShapeName(shape);
      Calculator();
      } // end constructor

    // set private variable functions calls
    void setShapeName(string shape)
      {
      shapeName = shape;
      pi = 3.14159;
      }
    void setNum1(string tk1)
      {
      n1 = tk1;
      num1 = atof(tk1.c_str());
      num2 = 0;
      num3 = 0;
      }
    void setNum2(string tk2)
      {
      n2 = tk2;
      num2 = atof(tk2.c_str());
      num3 = 0;
      }
    void setNum3(string tk3)
      {
      n3 = tk3;
      num3 = atof(tk3.c_str());
      }

    // Calculations based on shape identity
    void Calculator()
      {
      if(!num1)n1="0";
      if(!num2)n2="0";
      if(!num3)n3="0";

      if(shapeName == "SQUARE") calcSquare();
      else if(shapeName == "RECTANGLE") calcRect();
      else if(shapeName == "CIRCLE") calcCircle();
      else if(shapeName == "CUBE") calcCube();
      else if(shapeName == "PRISM") calcPrism();
      else if(shapeName == "CYLINDER") calcCyl();
      else invalidShape();
      }

    void calcSquare() //side
      {
      cout << "SQUARE:     side=" << n1 << ", area=" << (num1*num1) << ", perimeter=" << (num1*4) << endl;
      }

    void calcRect() //length, width
      {
      cout << "RECTANGLE:  length=" << n1 << ", width=" << n2 << ", area=" << (num1*num2) << ", perimeter=" << ((2*num1)+(2*num2)) << endl;
      }

    void calcCircle() //radius
      {
      cout << "CIRCLE:     radius=" << n1 << ", area=" << (pi*(num1*num1)) << ", circumference=" << (2*(pi*num1)) << endl;
      }

    void calcCube() //side
      {
      cout << "CUBE:       side=" << n1 << ", surface area=" << (6*(num1*num1)) << ", volume=" << (num1*(num1*num1)) << endl;
      }

    void calcPrism() //length, width, height
      {
      cout << "PRISM:      length=" << n1 << ", width=" << n2 << ", height=" << n3 << ", surface area=" << ((2*(num1*num2)) + (2*(num2*num3)) + (2*(num3*num1))) << ", volume=" << ((num1*num2)*num3) << endl;
      }

    void calcCyl() //radius, height
      {
      cout << "CYLINDER:   radius=" << n1 << ", height=" << n2 << ", surface area=" << ((2*(pi*(num1*num1))) + (2*(pi*(num1*num2)))) << ", volume=" << (num2*(pi*(num1*num1))) << endl;
      }

    void invalidShape()
      {
      cout << "   ERROR:   " << shapeName << " is an invalid object" << endl;
      }


  private:
    double num1, num2, num3, pi;
    string shapeName, n1, n2, n3;
  }; // end class GeometryCalculator


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@           Tokenizer declares          @@@@@@@@@@@@@@@@@@@@@@@@@@@
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
  cout << "Description: access a file, tokenize,\n";
  cout << "and display calculations for geometric shapes.\n";
  cout << "-------------------------------\n\n";

  // Variable Declaration
  string filename, shape;
  filename = "geo.txt";

  // Set decimal precision to 2 digits
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2); // applies until set to something else

  // create a file-reading object
  ifstream fin;
  fin.open(filename.c_str()); // open a file
  if (!fin.good())
    return 1; // exit if file not found

  // read each line of the file
  while (!fin.eof())
    {
    string shape, buf2, buf3, buf4;

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

    // copy token values to data types... THIS IS SOME UGLY CODE! BE READY TO FIX THIS, DUDE...
    if (token[0]) // zero if line is blank
      {
      shape = token[0];
      if (token[1]) // zero if line is blank
        {
        buf2 = token[1];
        if (token[2]) // zero if line is blank
          {
          buf3 = token[2];
          if (token[3]) // zero if line is blank
            {
            buf4 = token[3];
            }
          }
        }
      }

    if(n==1) GeometryCalculator myGeometryCalculator(shape);
    if(n==2) GeometryCalculator myGeometryCalculator(shape, buf2);
    if(n==3) GeometryCalculator myGeometryCalculator(shape, buf2, buf3);
    if(n==4) GeometryCalculator myGeometryCalculator(shape, buf2, buf3, buf4);
    }

  // Pause Statement
  cout << endl << "Press ENTER to end..." << endl;
  cin.get();
  }
