/*
 id.cpp
 Nikolas Lennon
 9/20/17
*/
#include <id.h>
#include <cstdlib>
#include <iostream>
#include <cstring>

/*
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
  char * name_  // the name field
  int    age_   // the age field
};

std::ostream& operator<< (std::ostream& os, const ID& d);
*/

void ID::SetName ( const char* name )
{
  if (name_ != nullptr)
    delete [] name_;
  size_t size = strlen(name);
  name_ = new char [1+size];
  name_[size] = '\0';
  strcpy(name_, name);
}

void ID::SetAge  ( int age )
{
  age_ = age;
}

const char* ID::GetName () const
{
  return name_;
}

int ID::GetAge  () const
{
  return age_;
}

ID::ID() : name_(nullptr), age_(-1)
{
  name_ = new char [2];
  name_[0] = '#';
  name_[1] = '\0';
}

ID::ID(const char* name, int age) : name_(nullptr), age_(age)
{
  size_t size = strlen(name);
  name_ = new char [1+size];
  name_[size] = '\0';
  strcpy(name_, name);
}

ID::~ID()
{
  if (name_ != nullptr)
    delete [] name_;
}

ID::ID(const ID& d) : name_(nullptr), age_(d.age_)
{
  size_t size = strlen(d.name_);
  name_ = new char [1+size];
  d.name_[size] = '\0';
  strcpy(name_, d.name_);
}

ID& ID::operator= (const ID& d)
{
  if (this != &d)
  {
    if (name_ != nullptr)
      delete [] name_;
    size_t size = strlen(d.name_);
    name_ = new char [1+size];
    name_[size] = '\0';
    strcpy(name_, d.name_);
    age_ = d.age_; 
  }
  return *this;
}

std::ostream& operator<< (std::ostream& os, const ID& d)
{
return os << d.GetName() << '\t' 
     << d.GetAge();
}
