// TODO:  Student class methods implementation here.
#include "Student.hpp"

Student::Student() : id(0), name(""), gpa(0.0), courseHead(nullptr) {}

Student::Student(int idVal, const string& nameVal, double gpaVal)
    : id(idVal), name(nameVal), gpa(gpaVal), courseHead(nullptr) {}

Student::Student(const Student& other)
    : id(other.id), name(other.name), gpa(other.gpa), courseHead(nullptr) {
    copyCoursesFrom(other);
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        gpa = other.gpa;
        clearCourses();
        copyCoursesFrom(other);
    }
    return *this;
}

Student::~Student() {
    clearCourses();
}

void Student::clearCourses() {
    Course* cur = courseHead;
    while (cur != nullptr) {
        Course* temp = cur;
        cur = cur->next;
        delete temp;
    }
    courseHead = nullptr;
}

void Student::copyCoursesFrom(const Student& other) {
    if (other.courseHead == nullptr) {
        courseHead = nullptr;
        return;
    }

    courseHead = new Course(other.courseHead->getCourseName(), other.courseHead->getLocation());

    Course* newCur = courseHead;
    Course* oldCur = other.courseHead->next;

    while (oldCur != nullptr) {
        newCur->next = new Course(oldCur->getCourseName(), oldCur->getLocation());
        newCur = newCur->next;
        oldCur = oldCur->next;
    }
}

int Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }

void Student::setId(int idVal) { id = idVal; }
void Student::setName(const string& nameVal) { name = nameVal; }
void Student::setGpa(double gpaVal) { gpa = gpaVal; }

bool Student::hasCourses() const {
    return courseHead != nullptr;
}

void Student::addCourse(const string& cName, const string& loc) {
    Course* newCourse = new Course(cName, loc);

    if (courseHead == nullptr) {
        courseHead = newCourse;
        return;
    }

    Course* cur = courseHead;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = newCourse;
}

void Student::printCourses(ostream& out) const {
    if (courseHead == nullptr) {
        out << "None";
        return;
    }

    Course* cur = courseHead;
    while (cur != nullptr) {
        out << cur->getCourseName() << " " << cur->getLocation();
        if (cur->next != nullptr) out << "\n         ";
        cur = cur->next;
    }
}

void Student::printSummary(ostream& out, bool showNoneIfEmpty) const {
    out << id << " " << name << " " << gpa;
    if (showNoneIfEmpty && courseHead == nullptr) out << " None";
}
