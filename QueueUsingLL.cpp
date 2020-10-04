#include<bits/stdc++.h>
using namespace std;

// class Node
template<typename T>
class Node{
	public:
	T data;
	Node<T>* next;
	
	Node(T data)
	{
		this -> data=data;
		next = NULL;
	}
};

//class queue
template<typename T>
class Queue{
	Node<T>*head;
	Node<T>*tail;
	T size;
	public:
		Queue(){
			head=NULL;
			tail=NULL;
			size=0;
		}
		
		// size of the queue
		T getSize()
		{
				return size;
		}
	
		//to check if the queue is empty or not
		bool isEmpty()
		{
			return size==0;
		}
		
		// to insert element 
		void push(T ele)
		{ Node<T>*n=new Node<T>(ele);
			  if(head==NULL)
			  {
			  	head =n;
			  	tail=n;
			  	
			  }
			  else
			  {
			  	   tail->next=n;
			  	   tail=n;
			  	   
			  }
			  size++;
		}
		
		// to get front element
		T front()
		{   if(isEmpty())
		{
			cout<<"queue is empty"<<endl;
			return 0;
		}
		    return head->data;
			
		}
		
		// to pop(delete) element from the front of the queue
		void pop()
		{ 
		if(isEmpty())
		{
			cout<<"queue is empty"<<endl;
			return ;
		}
		Node<T>*temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
		size--;
		}
};

int main()
{   Queue<int> q;
  q.push(10);
  q.push(20);
  cout<<q.front()<<endl;
 
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.getSize()<<endl;
  cout<<q.isEmpty()<<endl;
 
  q.push(60);
  q.push(70);
  q.push(80);
  q.pop();
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.getSize()<<endl;  
  
	return 0;
}
