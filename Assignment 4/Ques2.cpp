#include <iostream>
#define SIZE 5

class CircularQueue {
private:
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        if (front == rear + 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }

    void enqueue(int element) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            std::cout << "Inserted " << element << std::endl;
        }
    }

    int dequeue() {
        int element;
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return (-1);
        } else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
            std::cout << "Deleted -> " << element << std::endl;
            return (element);
        }
    }

    void peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
        } else {
            std::cout << "Front element is: " << items[front] << std::endl;
        }
    }

    void display() {
        int i;
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
        } else {
            std::cout << "Front -> " << front << std::endl;
            std::cout << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % SIZE) {
                std::cout << items[i] << " ";
            }
            std::cout << items[i] << std::endl;
            std::cout << "Rear -> " << rear << std::endl;
        }
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        std::cout << "\nCircular Queue Operations Menu\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. IsEmpty\n";
        std::cout << "4. IsFull\n";
        std::cout << "5. Peek\n";
        std::cout << "6. Display\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the value to enqueue: ";
                std::cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if (q.isEmpty()) {
                    std::cout << "Queue is empty.\n";
                } else {
                    std::cout << "Queue is not empty.\n";
                }
                break;
            case 4:
                if (q.isFull()) {
                    std::cout << "Queue is full.\n";
                } else {
                    std::cout << "Queue is not full.\n";
                }
                break;
            case 5:
                q.peek();
                break;
            case 6:
                q.display();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}