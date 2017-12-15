/*
 id.h
 Nikolas Lennon
 9/20/17
*/

#include <iostream>
#include <cstdlib>

#ifndef _ID_H
#define _ID_H

class ID
{
public:
  void        SetName ( const char* ); // sets the name field
  void        SetAge  ( int );         // sets the age field
  const char* GetName () const;        // returns a const pointer to the name field
int         GetAge  () const;        // returns the age field by value

  ID(); // name "#" age= -1
  ID(const char* name, int age);
  ~ID();
  ID(const ID& d);
  ID& operator= (const ID& d);

private:
  char * name_;  // the name field
  int    age_;   // the age field
};

std::ostream& operator<< (std::ostream& os, const ID& d);

#endif
