#include <iostream>
using namespace std;

#define MAX 3   

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() 
	{
        top = -1;
    }

    bool isFull() 
	{
        return top == MAX - 1;
    }

    bool isEmpty() 
	{
        return top == -1;
    }

    void push(int val) 
	{
        if (isFull()) 
		{
            cout << "Stack full" << endl;
        } 
		else 
		{
            arr[++top] = val;
        }
    }

    void pop() 
	{
        if (isEmpty()) 
		{
            cout << "Stack is empty" << endl;
        } 
		else 
		{
            cout << "Popped: " << arr[top--] << endl;
        }
    }
    
    int peek() 
	{
        if (!isEmpty())
            return arr[top];
        else {
            cout << "Stack is empty" << endl;
            return -1; 
        }
    }
};

int main()
{
    Stack s;
        
    cout<<"Pushing element: "<<11<<endl;
    s.push(11);
    cout<<"Pushing element: "<<22<<endl;
    s.push(22);
    cout<<"Pushing element: "<<33<<endl;
    s.push(33);
    cout<<"Pushing element: "<<44<<endl;
    s.push(44);
    s.pop();
    cout<<"Pushing element: "<<44<<endl;
    s.push(44);

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}