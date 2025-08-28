#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 10

class STACK
{
	string arr[SIZE];
	int top;

	public:
	STACK()
	{
		top = -1;
	}
	
	void push(string val)
	{
		if(top == SIZE - 1)
		{
			cout<<"stack is full"<<endl;
		}
		else
		{
			++top;
			arr[top] = val;
		}
	}
	
	void pop()
	{
		if(top == -1)
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			string str = arr[top];
			top--;
			reverse(str.begin() , str.end());
			cout<<"popped element="<<str<<endl;
			

		}
	}
};
int main()
{
	STACK s;
	
	string val;
	cout<<"enter string:"<<endl;
	cin>>val;
	
	s.push(val);
	
	s.pop();
	
}