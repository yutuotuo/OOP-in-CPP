// Lab 7a
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
  // Identifying output statements
  cout << "Programmer: Aaron Melocik\n";
  cout << "Description: This program finds strings and substrings.\n";
  cout << "-------------------------------\n" << endl;

  string string1("noon is 12 pm; midnight is not.");
  int location;

  // find "is" at location 5 and 24
  cout << "Original string:\n" << string1
       << "\n\n(find) \"is\" was found at: " << string1.find("is")
       << "\n(rfind) \"is\" was found at: " << string1.rfind("is");

  // find 'o' at location 1
  location = string1.find_first_of("misop");
  cout << "\n\n(find_first_of) found '" << string1[location]
       << "' from the group \"misop\" at: " << location;

  // find 'o' at location 29 <-- NOTE: Actually at 28
  location = string1.find_last_of("misop");
  cout << "\n\n(find_last_of) found '" << string1[location]
       << "' from the group \"misop\" at: " << location;

  // find '1' at location 8
  location = string1.find_first_not_of("noi spm");
  cout << "\n\n(find_first_not_of) '" << string1[location]
       << "' is not contained in \"noi spm\" and was found at: "
       << location;

  // find '.' at location 12 <-- NOTE: I think the book meant ";", and at 13
  location = string1.find_first_not_of("12noi spm");
  cout << "\n\n(find_first_not_of) '" << string1[location]
       << "' is not contained in \"12noi spm\" and was "
       << "found at: " << location << endl;

  // search for characters not in string1
  location = string1.find_first_not_of("noon is 12 pm; midnight is not.");
  cout << "\nfind_first_not_of(\"noon is 12 pm; midnight is not.\")"
       << " returned: " << location << endl;
} // end main
