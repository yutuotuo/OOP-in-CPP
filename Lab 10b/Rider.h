// Lab 10b
// Programmer: Aaron Melocik
// Editor(s) used: Code::Blocks 12.11
// Compiler(s) used: GNU GCC

#ifndef RIDER_H
#define RIDER_H

class Floor;

class Rider
{
public:
  Rider(const Floor&); // constructor; takes one Floor&
  Rider(const Rider&); // copy constructor

  bool operator< (const Rider&) const;
  bool operator== (const Rider&) const;
  Rider& operator=(const Rider&);

  // get functions (normally declared const). No setters.
  const Floor& getDestination() const; // return a const reference to the destination floor

private:
  const int riderID; // ID to uniquely identify rider
  const Floor* const destinationFloor; // const ptr to const object of Floor class
}; // end class Rider

#endif // RIDER_H
