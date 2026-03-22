#include <iostream>
using namespace std;

class InvalidMarksException {
public:
    const char* what() {
        return "Marks cannot be negative";
    }
};

class Student {
    int marks;

public:
    void setMarks(int m) {
        if (m < 0)
            throw InvalidMarksException();
        marks = m;
    }

    void display() {
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;

    try {
        s.setMarks(-10);
        s.display();
    }
    catch (InvalidMarksException e) {
        cout << e.what() << endl;
    }

    return 0;
}