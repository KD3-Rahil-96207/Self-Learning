#include <iostream>
using namespace std;

class Product {
protected:
    string title;
    double price;

public:
    virtual void accept() {
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Price: ";
        cin >> price;
    }

    virtual void display() {
    }

    virtual ~Product() {}
};

class Book : public Product {
private:
    int pages;

public:
    void accept() {
        Product::accept();
        cout << "Enter Pages: ";
        cin >> pages;
    }

    void display() {
        cout << "Pages: " << pages << endl;
    }
};

class Tape : public Product {
private:
    int playtime;

public:
    void accept() {
        Product::accept();
        cout << "Enter Playtime: ";
        cin >> playtime;
    }

    void display() {
        cout << "Playtime: " << playtime << endl;
    }
};

int main() {
    Product **arr = new Product*[5];
    int choice;

    for (int i = 0; i < 5; i++) {
        cout << "1. Book, 2. Tape, Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr[i] = new Book;
                arr[i]->accept();
                break;
            case 2:
                arr[i] = new Tape;
                arr[i]->accept();
                break;
        }
    }

    cout << "\nOutput:\n";

    for (int i = 0; i < 5; i++) {
        arr[i]->display();
    }

    return 0;
}