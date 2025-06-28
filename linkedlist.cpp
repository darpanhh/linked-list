#include <iostream>
using namespace std;

struct SinglyLL {
    int data;
    SinglyLL* next;
};

SinglyLL* headptr = nullptr;
SinglyLL* newnode;
SinglyLL* p;

void menu() {
    cout << "\n Main menu:\n";
    cout << " 1- Create Singly Linked List\n";
    cout << " 2- Insert as First Node of SLL\n";
    cout << " 3- Insert as Last Node of SLL\n";
    cout << " 4- Insert a New Node before a Given node\n";
    cout << " 5- Insert a New Node after a Given node\n";
    cout << " 6- Insert a new node at given position\n";
    cout << " 7- Delete a first node of SLL\n";
    cout << " 8- Delete node from given position of the SLL\n";
    cout << " 9- Delete a node after a given node\n";
    cout << "10- Delete a last node\n";
    cout << "11- Display all nodes of SLL\n";
    cout << "12- Exit\n";
}

void Create_SinglyLL(int item) {
    newnode = new SinglyLL();
    newnode->data = item;
    newnode->next = nullptr;

    if (headptr == nullptr) {
        headptr = newnode;
    } else {
        p = headptr;
        while (p->next != nullptr)
            p = p->next;
        p->next = newnode;
    }
}

void Insert_As_First_Node(int item) {
    newnode = new SinglyLL();
    newnode->data = item;
    newnode->next = headptr;
    headptr = newnode;
}

void Display_All_Nodes() {
    if (headptr == nullptr) {
        cout << "\nList is empty.";
        return;
    }

    p = headptr;
    cout << "\nNodes of SLL:";
    while (p != nullptr) {
        cout << " " << p->data;
        p = p->next;
    }
}

void Insert_As_Last_Node(int item) {
    newnode = new SinglyLL();
    newnode->data = item;
    newnode->next = nullptr;

    if (headptr == nullptr) {
        headptr = newnode;
    } else {
        p = headptr;
        while (p->next != nullptr)
            p = p->next;
        p->next = newnode;
    }
}

void Insert_Before_Given_Node(int m, int item) {
    if (headptr == nullptr) return;

    newnode = new SinglyLL();
    newnode->data = item;
    newnode->next = nullptr;

    if (headptr->data == m) {
        newnode->next = headptr;
        headptr = newnode;
        return;
    }

    SinglyLL* temp = headptr;
    SinglyLL* prev = nullptr;

    while (temp != nullptr && temp->data != m) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "\nNode with value " << m << " not found.";
        delete newnode;
        return;
    }

    prev->next = newnode;
    newnode->next = temp;
}

void Insert_After_Given_Node(int m, int item) {
    if (headptr == nullptr) return;

    p = headptr;
    while (p != nullptr && p->data != m)
        p = p->next;

    if (p == nullptr) {
        cout << "\nNode with value " << m << " not found.";
        return;
    }

    newnode = new SinglyLL();
    newnode->data = item;
    newnode->next = p->next;
    p->next = newnode;
}

void Insert_At_Any_Position(int pos, int item) {
    newnode = new SinglyLL();
    newnode->data = item;
    newnode->next = nullptr;

    if (pos <= 1 || headptr == nullptr) {
        newnode->next = headptr;
        headptr = newnode;
        return;
    }

    p = headptr;
    for (int i = 1; i < pos - 1 && p->next != nullptr; ++i) {
        p = p->next;
    }

    newnode->next = p->next;
    p->next = newnode;
}

void Delete_First_Node() {
    if (headptr == nullptr) return;

    p = headptr;
    headptr = headptr->next;
    delete p;
}

void Delete_Any_Position(int pos) {
    if (headptr == nullptr || pos <= 1) {
        Delete_First_Node();
        return;
    }

    SinglyLL* temp = headptr;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "\nInvalid position.";
        return;
    }

    SinglyLL* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void Delete_After_Given_Node(int m) {
    p = headptr;
    while (p != nullptr && p->data != m)
        p = p->next;

    if (p == nullptr || p->next == nullptr) {
        cout << "\nNo node to delete after " << m;
        return;
    }

    SinglyLL* temp = p->next;
    p->next = temp->next;
    delete temp;
}

void Delete_Last_Node() {
    if (headptr == nullptr) return;

    if (headptr->next == nullptr) {
        delete headptr;
        headptr = nullptr;
        return;
    }

    p = headptr;
    while (p->next->next != nullptr)
        p = p->next;

    delete p->next;
    p->next = nullptr;
}

int main() {
    int choice, item, m, pos;
    menu();

    do {
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> item;
                Create_SinglyLL(item);
                break;
            case 2:
                cout << "Enter data to insert as first node: ";
                cin >> item;
                Insert_As_First_Node(item);
                break;
            case 3:
                cout << "Enter data to insert as last node: ";
                cin >> item;
                Insert_As_Last_Node(item);
                break;
            case 4:
                cout << "Enter data to insert: ";
                cin >> item;
                cout << "Enter the node value before which to insert: ";
                cin >> m;
                Insert_Before_Given_Node(m, item);
                break;
            case 5:
                cout << "Enter data to insert: ";
                cin >> item;
                cout << "Enter the node value after which to insert: ";
                cin >> m;
                Insert_After_Given_Node(m, item);
                break;
            case 6:
                cout << "Enter data to insert: ";
                cin >> item;
                cout << "Enter position: ";
                cin >> pos;
                Insert_At_Any_Position(pos, item);
                break;
            case 7:
                Delete_First_Node();
                break;
            case 8:
                cout << "Enter position to delete: ";
                cin >> pos;
                Delete_Any_Position(pos);
                break;
            case 9:
                cout << "Enter node value after which to delete: ";
                cin >> m;
                Delete_After_Given_Node(m);
                break;
            case 10:
                Delete_Last_Node();
                break;
            case 11:
                Display_All_Nodes();
                break;
            case 12:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!";
        }
    } while (true);

    return 0;
}
