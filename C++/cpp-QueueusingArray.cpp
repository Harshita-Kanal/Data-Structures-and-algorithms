#include<iostream>
//#define MAX 100
using namespace std;
class Queue
{
	int front=0,rear=0,queue[10];
	public:
		int enqueue(int);
		int dequeue();
		int print();
};
int Queue::enqueue(int val)
{   
    rear=rear+1;
	queue[rear]=val;
}
int Queue::dequeue()
{   
    int temp=queue[front];
	front=front-1;
}
int Queue::print()
{   
    for(int i=front;i<=rear;i++)
    {
       cout<<queue[i]<<"<--";	
	}
}
int main()
{
	Queue p;
	p.enqueue(23);
	p.enqueue(25);
	p.enqueue(27);
	p.dequeue();
	p.print();
}
