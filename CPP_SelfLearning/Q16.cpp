#include <iostream>
using namespace std;

class Student {
public:
    void display() {
        cout << "Student Display" << endl;
    }
};

template <class T>
class SmartPtr {
    T* ptr;

public:
    SmartPtr(T* p = NULL) {
        ptr = p;
    }

    ~SmartPtr() {
        delete ptr;
    }

    T* operator->() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }
};

int main() {
    try {
        SmartPtr<Student> s(new Student);
        s->display();
    }
    catch (...) {
        cout << "invalid input" << endl;
    }

    return 0;
}