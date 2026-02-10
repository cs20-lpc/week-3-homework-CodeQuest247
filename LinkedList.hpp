#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Student.hpp"

using std::cout;
using std::endl;

struct Node {
    Student data;
    Node* next;

    Node(const Student& s) : data(s), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
        head = nullptr;
    }

    bool insertEnd(const Student& s) {
        Node* newNode = new Node(s);

        if (head == nullptr) {
            head = newNode;
            return true;
        }

        Node* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = newNode;
        return true;
    }

    bool deleteById(int id) {
        if (head == nullptr) return false;

        if (head->data.getId() == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* prev = head;
        Node* cur = head->next;

        while (cur != nullptr) {
            if (cur->data.getId() == id) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    Student* searchById(int id) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data.getId() == id) return &cur->data;
            cur = cur->next;
        }
        return nullptr;
    }

    void displayAll() const {
    cout << "Students in List:\n";
    if (head == nullptr) return;

    Node* cur = head;
    bool isFirst = true;

    while (cur != nullptr) {
        cur->data.printSummary(cout, isFirst);
        cout << endl;
        isFirst = false;
        cur = cur->next;
    }
}


    int countStudents() const {
        int count = 0;
        Node* cur = head;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        return count;
    }
};

#endif
