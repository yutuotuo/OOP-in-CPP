//#include <iostream>
//using std::cout;
//using std::endl;
//using std::ostream;
//
//#include <vector>
//using std::vector;
//
//#include <algorithm>
//#include <iterator>
//
//struct Route
//{
//  int n;
//  Route(int n):n(n){}
//};
//
//bool compare(const Route&, const Route&){return true;}
//ostream& operator<<(ostream& o, const Route&){return o;}
//
//int main()
//{
//  vector<int> a;
//  a.push_back(1);
//  cout << "a.size()=" << a.size() << endl;
//  vector<Route> r(10, Route(0));
//
//  vector<Route> r2;
//  r2.push_back(Route(10));
//  r2.push_back(Route(20));
//  r2.push_back(Route(30));
//  cout << "r2.size()=" << r2.size() << endl;
//  cout << "r2.capacity()=" << r2.capacity() << endl;
//
//  vector<Route>::iterator it;  // Node* p;
//  it = std::max_element(r2.begin(), r2.end(), compare);
//  if (it != r2.end()) cout << it->n;
//  if (it != r2.end()) cout << *it;
//
//  it = std::min_element(r2.begin(), r2.end(), compare);
//  if (it != r2.end()) cout << "FOUND!\n";
//
//  cout << '[';
//  std::ostream_iterator<Route> out(cout, "]\n[");
//  std::copy(r.begin(), r.end(), out);
//  cout << ']' << endl;
//
//  cout << '[';
//  std::copy(r2.begin(), r2.end(), out);
//  cout << ']' << endl;
//
//  std::sort(a.begin(), a.end());
//  std::sort(r.begin(), r.end(), compare);
//
//  int x[100];
//  std::sort(x, x + 100);
//
//  cout << "DONE\n";
//}
