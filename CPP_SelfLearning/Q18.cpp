#include <iostream>
using namespace std;

template <class T>
class Array {
    T* arr;
    int size;

public:
    Array(int s = 0) {
        size = s;
        arr = new T[size];
    }

    ~Array() {
        delete[] arr;
    }

    Array(const Array& other) {
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new T[size];
            for (int i = 0; i < size; i++)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    T& operator[](int index) {
        return arr[index];
    }

    int getSize() {
        return size;
    }

    void accept() {
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Student {
    int roll;
    float marks;

public:
    friend istream& operator>>(istream& in, Student& s) {
        in >> s.roll >> s.marks;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "[" << s.roll << ", " << s.marks << "]";
        return out;
    }
};

int main() {
    Array<int> a1(3);
    cout << "Enter integers:\n";
    a1.accept();
    a1.display();

    Array<Student> a2(2);
    cout << "Enter students (roll marks):\n";
    a2.accept();
    a2.display();

    return 0;
}