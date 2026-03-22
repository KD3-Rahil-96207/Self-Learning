#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int value) {
        data = value;
        next = NULL;
    }

    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void add_first(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void add_last(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.add_first(30);
    list.add_first(20);
    list.add_first(10);

    list.add_last(40);
    list.add_last(50);

    cout << "Linked List: ";
    list.display();

    return 0;
}