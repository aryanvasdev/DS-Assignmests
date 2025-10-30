#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int countAndDelete(Node*& head, int key) {
    int count = 0;
    Node* dummy = new Node(0); // <-- This is the corrected line
    dummy->next = head;

    Node* prev = dummy;
    Node* current = head;

    while (current != nullptr) {
        if (current->data == key) {
            count++;
            prev->next = current->next;
            Node* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }

    head = dummy->next;
    delete dummy;
    return count;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << "->";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;
    int n;

    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> val;
        insertEnd(head, val);
    }

    std::cout << "Input Linked List: ";
    printList(head);

    int key;
    std::cout << "Enter the key to delete: ";
    std::cin >> key;

    int totalCount = countAndDelete(head, key);

    std::cout << "Count: " << totalCount << std::endl;
    std::cout << "Updated Linked List: ";
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}