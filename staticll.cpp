#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int data;
    int next;
};

Node node[SIZE];
int list = -1;     
int avail = 0;     


void initialize() {
    for (int i = 0; i < SIZE - 1; i++) {
        node[i].next = i + 1;
    }
    node[SIZE - 1].next = -1;
    list = -1;
    avail = 0;
}


int getNode(int x) {
    if (avail == -1) {
        cout << "Overflow: No available node.\n";
        return -1;
    }
    int index = avail;
    avail = node[avail].next;
    node[index].data = x;
    node[index].next = -1;
    return index;
}

void freeNode(int index) {
    node[index].next = avail;
    avail = index;
    if (index == list) list = -1;
}


void insertBeg(int x) {
    int index = getNode(x);
    if (index == -1) return;
    node[index].next = list;
    list = index;
}


void insertEnd(int x) {
    if (list == -1) {
        insertBeg(x);
        return;
    }
    int index = getNode(x);
    if (index == -1) return;

    int i = list;
    while (node[i].next != -1) {
        i = node[i].next;
    }
    node[i].next = index;
}


void insertAfter(int x, int ref) {
    int i = list;
    while (i != -1 && node[i].data != ref) {
        i = node[i].next;
    }
    if (i == -1) {
        cout << "Reference value not found.\n";
        return;
    }
    int q = getNode(x);
    if (q == -1) return;
    node[q].next = node[i].next;
    node[i].next = q;
}


int deleteBeg() {
    if (list == -1) {
        cout << "Underflow: List is empty.\n";
        return -1;
    }
    int index = list;
    int delItem = node[index].data;
    list = node[list].next;
    freeNode(index);
    return delItem;
}


int deleteEnd() {
    if (list == -1) {
        cout << "Underflow: List is empty.\n";
        return -1;
    }
    int i = list, q = -1;
    while (node[i].next != -1) {
        q = i;
        i = node[i].next;
    }
    int delItem = node[i].data;
    freeNode(i);
    if (q == -1) list = -1;
    else node[q].next = -1;
    return delItem;
}


int deleteAfter(int ref) {
    if (list == -1) {
        cout << "Underflow: List is empty.\n";
        return -1;
    }
    int i = list;
    while (i != -1 && node[i].data != ref) {
        i = node[i].next;
    }
    if (i == -1 || node[i].next == -1) {
        cout << "No element found after given reference.\n";
        return -1;
    }
    int q = node[i].next;
    int delItem = node[q].data;
    node[i].next = node[q].next;
    freeNode(q);
    return delItem;
}


void displayList() {
    int i = list;
    cout << "List: ";
    while (i != -1) {
        cout << node[i].data << " ";
        i = node[i].next;
    }
    cout << "\n";
}


int main() {
    initialize();
    int choice, x, ref, result;

    do {
        cout << "\n----- Static Linked List Menu -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Value\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete After a Value\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> x;
            insertBeg(x);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> x;
            insertEnd(x);
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> x;
            cout << "Enter reference value after which to insert: ";
            cin >> ref;
            insertAfter(x, ref);
            break;

        case 4:
            result = deleteBeg();
            if (result != -1)
                cout << "Deleted value: " << result << "\n";
            break;

        case 5:
            result = deleteEnd();
            if (result != -1)
                cout << "Deleted value: " << result << "\n";
            break;

        case 6:
            cout << "Enter reference value after which to delete: ";
            cin >> ref;
            result = deleteAfter(ref);
            if (result != -1)
                cout << "Deleted value: " << result << "\n";
            break;

        case 7:
            displayList();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}