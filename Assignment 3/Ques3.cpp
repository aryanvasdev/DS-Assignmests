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
	
	bool isEmpty()
	{
	    return top == -1;
	}
};
	
bool isMatching(char open , char close)
{
	return (open == '(' && close == ')') || 
		   (open == '{' && close == '}') || 
		   (open == '[' && close == ']');
}


int main()
{
	STACK s;
	string val;
	
	cout<<"enter string:"<<endl;
	cin>>val;
	
	for(char ch : val)
	{
		if(ch == '(' || ch == '{' || ch == '[')
		{
			s.push(ch);
		}
		else if(ch == ')' || ch == '}' || ch == ']')
		{
			if(s.isEmpty())
			{
				cout<<"stack is empty"<<ch<<endl;
				return 0;
			}
			
			char popped = s.pop();
			
			if(!isMatching(popped , ch))
			{
			    cout<<"Unmatched brackets "<<popped<<" and "<<ch<<endl;
			    return 0;
			}
		}
	}
	
	if(s.isEmpty())
	{
		cout<<"balanced brackets"<<endl;
	}
	else
	{
		cout<<"unbalanced brackets:extra brackets"<<endl;
	}
}