#include <iostream>
#include <algorithm>
#include <cmath>
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
class intSTACK
{
	int arr[SIZE];
	int top;
	
	public:
	intSTACK()
	{
		top = -1;
	}
	
	void push(int val)
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
	
	int pop()
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
	
	bool isEmpty()
	{
	    return top == -1;
	}
};

int main()
{
    STACK s; 
    
    
    string val;
    cout<<"enter infix expression: ";
    getline(cin,val);
    
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
                postfix = postfix + (char)s.pop();
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
                postfix = postfix + (char)s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.isEmpty())
    {
        postfix = postfix + (char)s.pop();
    }
    
    cout<<"Postfix expression: "<<postfix<<endl; 
    
    
    
    intSTACK t;
    
    
    
    for(char ch : postfix)
    {
        if((ch >= '1' && ch <= '9'))
        {
            t.push(ch - '0');
        }
        else if((ch == '+') || (ch =='-') || (ch == '*') || (ch == '/') || (ch == '^'))
        {
            int operand2 = t.pop();
            int operand1 = t.pop();
            
            int result = 0;
            
            switch (ch) 
            {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': 
                    result = 1;
                    for (int i = 0; i < operand2; i++)
                    {
                        result *= operand1;
                    }
                    break;
            }
            t.push(result);
        }
    }
    cout<<"result: "<<t.pop()<<endl;
}