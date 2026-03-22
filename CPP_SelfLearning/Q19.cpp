#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    list<int> l;

    for (int i = 0; i < 10; i++) {
        l.push_back(rand() % 100);
    }

    cout << "Reverse Order: ";
    for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        *it = *it + 5;
    }

    cout << "Using const iterator: ";
    for (list<int>::const_iterator it = l.cbegin(); it != l.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    l.sort();

    cout << "Sorted List: ";
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}