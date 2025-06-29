#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
};


class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr, head};
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        cout << " Inserted " << value << " at the beginning.\n";
    }

    
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << " Inserted " << value << " at the end.\n";
    }

    
    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;
        if (temp == nullptr) {
            cout << " Target " << target << " not found.\n";
            return;
        }
        Node* newNode = new Node{value, temp, temp->next};
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << " Inserted " << value << " after " << target << ".\n";
    }

    
    void insertBefore(int target, int value) {
        if (head == nullptr) {
            cout << " List is empty.\n";
            return;
        }
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;
        if (temp == nullptr) {
            cout << " Target " << target << " not found.\n";
            return;
        }
        Node* newNode = new Node{value, temp->prev, temp};
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << " Inserted " << value << " before " << target << ".\n";
    }

    
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << " List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        cout << " Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << " List is empty.\n";
            return;
        }
        Node* temp = head;
        if (temp->next == nullptr) {
            cout << " Deleted " << temp->data << " from end.\n";
            delete temp;
            head = nullptr;
            return;
        }
        while (temp->next != nullptr)
            temp = temp->next;
        temp->prev->next = nullptr;
        cout << " Deleted " << temp->data << " from end.\n";
        delete temp;
    }

    
    void deleteAfter(int target) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;
        if (temp == nullptr || temp->next == nullptr) {
            cout << " No node found after " << target << ".\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != nullptr)
            nodeToDelete->next->prev = temp;
        cout << " Deleted " << nodeToDelete->data << " after " << target << ".\n";
        delete nodeToDelete;
    }

    
    void deleteBefore(int target) {
        Node* temp = head;
        if (temp == nullptr || temp->data == target) {
            cout << " No node found before " << target << ".\n";
            return;
        }
        while (temp != nullptr && temp->data != target)
            temp = temp->next;
        if (temp == nullptr || temp->prev == nullptr) {
            cout << " No node found before " << target << ".\n";
            return;
        }
        Node* nodeToDelete = temp->prev;
        if (nodeToDelete->prev != nullptr)
            nodeToDelete->prev->next = temp;
        else
            head = temp;
        temp->prev = nodeToDelete->prev;
        cout << " Deleted " << nodeToDelete->data << " before " << target << ".\n";
        delete nodeToDelete;
    }

    
    void display() {
        if (head == nullptr) {
            cout << " List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << " List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};


int main() {
    DoublyLinkedList dll;
    int choice, value, target;

    do {
        cout << "\n======= DOUBLY LINKED LIST MENU =======\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete After a Node\n";
        cout << "8. Delete Before a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dll.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            dll.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter target node and value: ";
            cin >> target >> value;
            dll.insertAfter(target, value);
            break;
        case 4:
            cout << "Enter target node and value: ";
            cin >> target >> value;
            dll.insertBefore(target, value);
            break;
        case 5:
            dll.deleteFromBeginning();
            break;
        case 6:
            dll.deleteFromEnd();
            break;
        case 7:
            cout << "Enter target node: ";
            cin >> target;
            dll.deleteAfter(target);
            break;
        case 8:
            cout << "Enter target node: ";
            cin >> target;
            dll.deleteBefore(target);
            break;
        case 9:
            dll.display();
            break;
        case 0:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << " Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
        
    return 0;
}