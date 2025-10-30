#include <iostream>
#include <queue>

using namespace std;

class StackUsingOneQueue {
private:
    queue<int> q;

public:
    StackUsingOneQueue() {}

    void push(int x) {
        int s = q.size();
        
        q.push(x);

        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue s1;
    
    cout << "Pushing 10" << endl;
    s1.push(10);
    cout << "Pushing 20" << endl;
    s1.push(20);
    cout << "Pushing 30" << endl;
    s1.push(30);

    cout << "Top element is: " << s1.top() << endl; 
    s1.pop();
    cout << "Popped. Top element is: " << s1.top() << endl; 
    s1.pop();
    cout << "Popped. Top element is: " << s1.top() << endl; 
    s1.pop();
    
    cout << "Popped. Is stack empty? " << (s1.empty() ? "Yes" : "No") << endl;
    
    s1.pop(); 

    return 0;
}