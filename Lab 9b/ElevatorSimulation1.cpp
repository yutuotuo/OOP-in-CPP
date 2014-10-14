//#include <iostream>
//using std::cout;
//using std::endl;
//
//#include "Floor.h"
//#include "Floor.h" // for testing
//
//#include "Rider.h"
//#include "Rider.h" // for testing
//
//int main()
//{
//  const Floor f(0); // a floor at ground level
//
//  const Rider a(f); // a rider whose destination is "f"
//  const Rider b(f); // a second rider whose destination is "f"
//  const Rider i(f); // 3
//  const Rider d(f); // 3
//  const Rider e(f); // 3
//  const Rider g(f); // 3
//  const Rider h(f); // 3
//
//  cout << "a == b test: ";
//  if (a == b) cout << "equal (INCORRECT)\n"; else cout << "unequal (correct)\n";
//  cout << "a <  b test: ";
//  if (a < b) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//
//  const Rider c(a); // a clone of the first rider
//  cout << "a == c test: ";
//  if (a == c) cout << "equal (correct)\n"; else cout << "unequal (INCORRECT)\n";
//  cout << "a <  c test: ";
//  if (a < c) cout << "less (INCORRECT)\n"; else cout << "greater or equal (correct)\n";
//
//  // checking the cloning of the Floor*
//  cout << "destination: ";
//  if (&(a.getDestination()) == &(c.getDestination())) cout << "equal (correct)\n"; else cout << "unequal (INCORRECT)\n";
//
//  // additional testing of your own, if you have any
//  //...
//
//  cout << endl << endl << endl;
////  cout << a.riderID << " " << b.riderID << " " << i.riderID << " " << d.riderID
////       << " " << e.riderID << " " << g.riderID << " " << h.riderID << endl;
//
//
//
//
////7. Provide a const member function named getDestination to return a const reference to the destination floor.
////This may be inline or not -- it's your choice. (Note that the constructor does not allow the destination
////floor pointer to be zero, because it is passed as a reference instead of a pointer.
////So there is no need for validation or error checking.)
//
//
//
//
//
//
//  if (a == b) cout << "equal (INCORRECT)\n"; else cout << "unequal (correct)\n";
//
//
//
//  cout << endl << endl << endl;
// // (&(a.getDestination()) == &(c.getDestination()));
//  if (&(a.getDestination()) == &(c.getDestination())) cout << "equal (correct)\n"; else cout << "unequal (INCORRECT)\n";
//
//
//
//
//
//  cout << "a <  d test: ";
//  if (a < d) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//  cout << "a <  g test: ";
//  if (a < g) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//  cout << "b <  a test: ";
//  if (b < a) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//  cout << "d <  g test: ";
//  if (d < g) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//  cout << "g <  g test: ";
//  if (g < g) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//  cout << "b <  h test: ";
//  if (b < h) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//  cout << "h <  b test: ";
//  if (h < b) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";
//
//
//
//  cout << endl;
//}
