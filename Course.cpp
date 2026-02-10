// TODO:  Course class methods implementation here.
#include "Course.hpp"

Course::Course() : courseName(""), location(""), next(nullptr) {}

Course::Course(const string& name, const string& loc)
    : courseName(name), location(loc), next(nullptr) {}

string Course::getCourseName() const { return courseName; }
string Course::getLocation() const { return location; }

void Course::setCourseName(const string& name) { courseName = name; }
void Course::setLocation(const string& loc) { location = loc; }
