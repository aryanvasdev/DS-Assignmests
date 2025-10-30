#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << "->";
        }
        temp = temp->next;
    }
    std::cout << "->NULL" << std::endl;
}

int main() {
    Node* head = nullptr;
    int n;

    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;

    if (n > 0) {
        std::cout << "Enter " << n << " elements:" << std::endl;
        for (int i = 0; i < n; ++i) {
            int val;
            std::cout << "Enter element " << i + 1 << ": ";
            std::cin >> val;
            insertEnd(head, val);
        }
    }

    std::cout << "Input: ";
    printList(head);

    reverseList(head);

    std::cout << "Output: ";
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
