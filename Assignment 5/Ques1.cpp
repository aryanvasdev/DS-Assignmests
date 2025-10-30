#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << data << " has been inserted at the beginning." << endl;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            cout << data << " has been inserted at the end." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << data << " has been inserted at the end." << endl;
    }

    void insertAfter(int targetValue, int newData) {
        Node* temp = head;
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Error: Node with value " << targetValue << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newData);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << newData << " has been inserted after " << targetValue << "." << endl;
    }

    void insertBefore(int targetValue, int newData) {
        if (head == nullptr) {
            cout << "Error: List is empty." << endl;
            return;
        }

        if (head->data == targetValue) {
            insertAtBeginning(newData);
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr && current->data != targetValue) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Error: Node with value " << targetValue << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newData);
        newNode->next = current;
        prev->next = newNode;
        cout << newData << " has been inserted before " << targetValue << "." << endl;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is already empty." << endl;
            return;
        }
        Node* temp = head;
        int deletedValue = head->data;
        head = head->next;
        delete temp;
        cout << deletedValue << " has been deleted from the beginning." << endl;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is already empty." << endl;
            return;
        }

        if (head->next == nullptr) {
            deleteFromBeginning();
            return;
        }

        Node* second_last = head;
        while (second_last->next->next != nullptr) {
            second_last = second_last->next;
        }
        
        int deletedValue = second_last->next->data;
        delete second_last->next;
        second_last->next = nullptr;
        cout << deletedValue << " has been deleted from the end." << endl;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        if (temp->data == value) {
            head = temp->next;
            delete temp;
            cout << "Node with value " << value << " has been deleted." << endl;
            return;
        }

        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Error: Node with value " << value << " not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Node with value " << value << " has been deleted." << endl;
    }

    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Node with value " << value << " found at position " << position << "." << endl;
                return;
            }
            current = current->next;
            position++;
        }
        cout << "Node with value " << value << " not found in the list." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void showMenu() {
    cout << "\n--- Singly Linked List Operations ---" << endl;
    cout << "1. Insertion at the beginning" << endl;
    cout << "2. Insertion at the end" << endl;
    cout << "3. Insertion in between" << endl;
    cout << "4. Deletion from the beginning" << endl;
    cout << "5. Deletion from the end" << endl;
    cout << "6. Deletion of a specific node" << endl;
    cout << "7. Search for a node" << endl;
    cout << "8. Display the list" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    LinkedList list;
    int choice, data, target, subChoice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "\n--- Insert In Between Menu ---\n";
                cout << "1. Insert AFTER a specific value\n";
                cout << "2. Insert BEFORE a specific value\n";
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    cout << "Enter the existing value to insert after: ";
                    cin >> target;
                    cout << "Enter the new data to insert: ";
                    cin >> data;
                    list.insertAfter(target, data);
                } else if (subChoice == 2) {
                    cout << "Enter the existing value to insert before: ";
                    cin >> target;
                    cout << "Enter the new data to insert: ";
                    cin >> data;
                    list.insertBefore(target, data);
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter the value of the node to delete: ";
                cin >> data;
                list.deleteNode(data);
                break;
            case 7:
                cout << "Enter the value to search for: ";
                cin >> data;
                list.search(data);
                break;
            case 8:
                list.display();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}