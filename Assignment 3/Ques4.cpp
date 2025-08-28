#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 10

class STACK
{
	char arr[SIZE];
	int top;
	
	public:
	STACK()
	{
		top = -1;
	}
	
	void push(char val)
	{
		if(top == SIZE -1)
		{
			cout<<"stack is full"<<endl;
		}
		else
		{
			++top;
			arr[top] = val;
		}
	}
	
	char pop()
	{
		if(top == -1)
		{
			return '\0';
		}
		else
		{
			return arr[top--];
		}
	}
	
	char peek() 
	{
        if (top == -1) 
        {
            return '\0';
        }
        return arr[top];
	}
	
	bool isEmpty()
	{
	    return top == -1;
	}
};

int precedence(char op)
{
    if ((op == '+') || (op == '-'))
    {
        return 1;
    }
    if ((op == '*') ||(op == '/'))
    {
        return 2;
    }
    if (op == '^')
    {
        return 3;
    }
    return 0;
}
	
int main()
{
    STACK s;
    
    string val;
    cout<<"enter infix expression: "<<endl;
    cin>>val;
    
    string postfix;
    
    for(char ch : val)
    {
        if((ch >= '1' && ch <= '9') ||
          (ch >= 'a' && ch <= 'z') ||
          (ch >= 'A' && ch <= 'Z'))
        {
            postfix = postfix + ch;
        }
        
        else if(ch == '(')
        {
            s.push(ch);
        }
        
        else if(ch == ')')
        {
            while(!s.isEmpty() && s.peek() != '(')
            {
                postfix = postfix + s.pop();
            }
            s.pop();
        }
        
        else if((ch == '+') ||
               (ch == '-') ||
               (ch == '*') ||
               (ch == '/') ||
               (ch == '^'))
        {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
            {
                s.pop();
                postfix = postfix + ch;
            }
            s.push(ch);
        }
    }
    while(!s.isEmpty())
    {
        postfix = postfix + s.pop();
    }
    
    cout<<"Postfix expression"<<postfix<<endl;    
    return 0;
}