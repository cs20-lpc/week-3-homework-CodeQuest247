// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using std::string;

class Course {
private:
    string courseName;
    string location;

public:
    Course* next;

    Course();
    Course(const string& name, const string& loc);

    string getCourseName() const;
    string getLocation() const;

    void setCourseName(const string& name);
    void setLocation(const string& loc);
};

#endif
