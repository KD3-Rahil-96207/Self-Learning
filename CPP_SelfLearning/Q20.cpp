#include <iostream>
#include <memory>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor\n"; }
    ~Demo() { cout << "Destructor\n"; }

    void show() {
        cout << "Inside Demo\n";
    }
};

int main() {

    unique_ptr<Demo> p1 = make_unique<Demo>();
    p1->show();

    unique_ptr<Demo> p2 = move(p1);

    if (!p1)
        cout << "p1 is now empty after transfer\n";

    p2->show();


    shared_ptr<Demo> s1 = make_shared<Demo>();
    cout << "s1 count: " << s1.use_count() << endl;

    shared_ptr<Demo> s2 = s1;
    cout << "s1 count after sharing: " << s1.use_count() << endl;

    s2->show();


    weak_ptr<Demo> w1 = s1;

    cout << "Weak pointer created\n";
    cout << "s1 count (weak_ptr does not increase): " << s1.use_count() << endl;

    if (auto temp = w1.lock()) {
        temp->show();
    } else {
        cout << "Object expired\n";
    }

    return 0;
}