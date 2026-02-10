// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "Course.hpp"

using std::string;
using std::ostream;

class Student {
private:
    int id;
    string name;
    double gpa;
    Course* courseHead;

    void clearCourses();
    void copyCoursesFrom(const Student& other);

public:
    Student();
    Student(int id, const string& name, double gpa);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    int getId() const;
    string getName() const;
    double getGpa() const;

    void setId(int id);
    void setName(const string& name);
    void setGpa(double gpa);

    bool hasCourses() const;

    void addCourse(const string& courseName, const string& location);
    void printCourses(ostream& out) const;
    void printSummary(ostream& out, bool showNoneIfEmpty) const;
};

#endif


