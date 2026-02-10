#include <iostream>
#include <string>
#include <limits>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

static void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    LinkedList list;
    int choice;
    bool firstPrompt = true;

    cout << "1. Insert Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Search Student\n";
    cout << "4. Display All\n";
    cout << "5. Count Students\n";
    cout << "6. Add a course\n";
    cout << "7. Exit\n";

    while (true) {
        if (!firstPrompt) cout << "\n";
        cout << "Enter choice: ";
        cin >> choice;
        firstPrompt = false;

        if (choice == 7) break;

        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter GPA: ";
            cin >> gpa;

            Student s(id, name, gpa);
            list.insertEnd(s);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            if (list.deleteById(id)) {
                cout << "Deleted student with ID " << id << "\n";
            } else {
                cout << "Student not found\n";
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Student* s = list.searchById(id);
            if (s) {
                cout << "Found: " << s->getId() << " " << s->getName() << " " << s->getGpa() << "\n";
                cout << "Courses: ";
                s->printCourses(cout);
                cout << "\n";
            } else {
                cout << "Student not found\n";
            }
        }
        else if (choice == 4) {
            list.displayAll();
        }
        else if (choice == 5) {
            cout << "Total students: " << list.countStudents() << "\n";
        }
        else if (choice == 6) {
            int id;
            string courseName, location;

            cout << "Enter ID: ";
            cin >> id;

            Student* s = list.searchById(id);
            if (!s) {
                cout << "Student not found\n";
                continue;
            }

            cout << "Enter Course Name: ";
            cin >> ws;
            getline(cin, courseName);

            cout << "Enter location: ";
            getline(cin, location);

            s->addCourse(courseName, location);
        }
    }

    return 0;
}
