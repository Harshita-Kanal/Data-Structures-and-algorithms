#include<iostream>
#define MAX 100
using namespace std;

class Stack
{   
    private:int stack[MAX];
	int top;
    public:int push(int);
    int pop();
    int display();
};
int Stack::push(int data)
{   
    top=top+1;
    stack[top]=data;
}
int Stack::pop()
{   
    if(top==-1)
    {
    	cout<<"EMpty Stack GO bACk!"<<endl;
	}
	int temp=stack[top];
	top=top-1;
	
}
int Stack::display()
{   
    if(top==-1)
    {
    	cout<<"EMpty Stack Cant u SEee!"<<endl;
	}
	for(int i=top;i>0;i--)
	{
		cout<<stack[i]<<" ";
	}
}
int main()
{   
    Stack s;
	cout<<"Stack Elements are: ";
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.pop();
	s.pop();
	s.display();
	return 0;
}
