//#include <iostream>
//using namespace std;
//
//struct Shape
//{
//  friend ostream& operator<<(ostream&, const Shape*);
//  Shape(){cout << "new Shape at " << (int)this << endl;}
//  virtual void print(ostream& out) const {out << "There's a shape at " << (int)this;}
//};
//
//struct Square : public Shape
//{
//  void print(ostream& out) const {out << "There's a Square at " << (int)this;}
//};
//
//ostream& operator<<(ostream& out, const Shape* s)
//{
//  s->print(out);
//  return out;
//}
//
//int main()
//{
//  Shape s;
//  cout << &s << endl;
//
//  Square sq;
//  cout << &sq << endl;
//}
