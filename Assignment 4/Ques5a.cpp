#include <iostream>
#include <queue>

using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1;
    queue<int> q2; 

public:
    StackUsingTwoQueues() {}

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues s2;

    cout << "Pushing 1" << endl;
    s2.push(1);
    cout << "Pushing 2" << endl;
    s2.push(2);
    cout << "Pushing 3" << endl;
    s2.push(3);

    cout << "Top element is: " << s2.top() << endl; 
    s2.pop();
    cout << "Popped. Top element is: " << s2.top() << endl; 
    s2.pop();
    cout << "Popped. Top element is: " << s2.top() << endl; 
    s2.pop();

    cout << "Popped. Is stack empty? " << (s2.empty() ? "Yes" : "No") << endl;

    s2.pop(); 

    return 0;
}