#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int rollNo;
    char name[50];
    double marks;

public:
    void accept() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1, s2;

    ofstream fout("student.dat", ios::binary);
    s1.accept();
    fout.write((char*)&s1, sizeof(s1));
    fout.close();

    ifstream fin("student.dat", ios::binary);
    fin.read((char*)&s2, sizeof(s2));
    fin.close();

    cout << "\nData read from file:\n";
    s2.display();

    return 0;
}