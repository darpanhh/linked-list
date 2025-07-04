#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = nullptr, *p, *newnode;

void createSingleLL(int item) {
    newnode = new node;
    newnode->data = item;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
        head->next = head;
    } else {
        p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = newnode;
        newnode->next = head;
    }
}

void insertAsFirstNode(int item) {
    newnode = new node;
    newnode->data = item;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
        head->next = head;
        return;
    }

    p = head;
    while (p->next != head) {
        p = p->next;
    }

    newnode->next = head;
    head = newnode;
    p->next = head;
}

void insertAsLastNode(int item) {
    newnode = new node;
    newnode->data = item;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
        head->next = head;
        return;
    }

    p = head;
    while (p->next != head) {
        p = p->next;
    }
    p->next = newnode;
    newnode->next = head;
}

void displayAllNodes() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    p = head;
    do {
        cout << p->data << " -> ";
        p = p->next;
    } while (p != head);
    cout << "(back to head)" << endl;
}

void deleteFirstNode() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    node* temp = head;
    p = head;
    while (p->next != head) {
        p = p->next;
    }

    head = head->next;
    p->next = head;
    delete temp;
}

void deleteLastNode() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    p = head;
    while (p->next->next != head) {
        p = p->next;
    }

    node* temp = p->next;
    p->next = head;
    delete temp;
}

int main() {
    int choice, value;
    do {
        cout << "\n------Circular Singly Linked List Menu-----" << endl;
        cout << "1. Create CSLL and add element at last" << endl;
        cout << "2. Insert node at beginning" << endl;
        cout << "3. Insert node at last" << endl;
        cout << "4. Delete node at beginning" << endl;
        cout << "5. Delete node at last" << endl;
        cout << "6. Display all nodes" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                createSingleLL(value);
                break;
            case 2:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAsFirstNode(value);
                break;
            case 3:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAsLastNode(value);
                break;
            case 4:
                cout << "Deleted node from the beginning." << endl;
                deleteFirstNode();
                break;
            case 5:
                cout << "Deleted node from the last." << endl;
                deleteLastNode();
                break;
            case 6:
                cout << "The elements of the list are:" << endl;
                displayAllNodes();
                break;
            case 0:
                cout << "Exiting.....Good Bye!!!!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
