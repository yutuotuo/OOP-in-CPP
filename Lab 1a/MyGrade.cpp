// Lab #a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

// Class average problem with counter-controlled repetition.
#include <cstdlib>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: Prompt for input for 10 grades, then return\n";
  cout << "the total points and average of all ten scores. This will\n";
  cout << "also demonstrate adherence to universal lab requirements.\n";
  cout << "-------------------------------\n\n";

  int total; // sum of grades entered by user
  int gradeCounter; // number of the grade to be entered next
  int grade; // grade value entered by user
  int average; // average of grades
  string buf; // string buffer for input

  // initialization phase
  total = 0; // initialize total
  gradeCounter = 1; // initialize loop counter

  // processing phase
  while (gradeCounter <= 10) // loop 10 times
  {
    cout << "Enter grade: "; // prompt for input
    getline(cin, buf);
    grade = atoi(buf.c_str());
    total = total + grade; // add grade to total
    gradeCounter = gradeCounter + 1; // increment counter by 1
  } // end while

  // termination phase
  average = total / 10; // integer division yields integer result

  // display total and average of grades
  cout << "\nTotal of all 10 grades is " << total << endl;
  cout << "Class average is " << average << endl;
} // end main
