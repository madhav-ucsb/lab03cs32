#include "student.h"
#include <cstring>
#include <iostream>
#include <string>

Student::Student(const char *const named, int perm) {
  this->name = new char[strlen(named)+1];

  strcpy(this->name, named );
  this->setPerm(perm);
}

int Student::getPerm() const { return perm; }

char const* Student::getName() const { return name; }

void Student::setPerm(const int permNumber) { perm = permNumber; }

void Student::setName(const char *const named) {


  delete [] this->name;
  this->name = new char[strlen(named) + 1];
  strcpy(this->name, named);
}

Student::Student(const Student &orig) {
  name = 0;
  this->setName(orig.getName());
  this->setPerm(orig.getPerm());
}

Student::~Student() {
  delete [] name;
}

Student &Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this)
    return (*this);
  this->setName(right.getName());
  this->setPerm(right.getPerm());

  // TODO... Here is where there is code missing that you need to
  // fill in...

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this);
}

std::string Student::toString() const {
  std::string integer = std::to_string(perm);

  return "[" + (std::string)name + "," + integer + "]";
}
