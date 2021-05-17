#include <iostream>
using namespace std;

class Node{
    private:int data;
    Node* next;
    friend class LinkedList; 
};
class LinkedList{
    private:Node* head;
    Node* prev;
    public:
    LinkedList(){    //class constructor initializing value of head 
        head=NULL;
    }
    int addFront(int);
    int removeFront();
    int printList();
    int addElement(int,int);
    int deleteElement(int);
    int deletePosition(int);
    int sizeofList();
    int reverseList();
    int swapData(int,int);
    bool searchElement(int);
};

int LinkedList::addFront(int a)  //Using scope resolution to access member funcs outside class. 
{
    Node* newnode=new Node;
    newnode->data=a;
    newnode->next=head;
    head=newnode; //Making newnode the head.
}

int LinkedList::addElement(int a,int pos)
{   Node* temp=head; //If not use temp and go with head it will replaces head values of addFront values.
    while(pos>0)
    {  
        temp=temp->next;
        pos--;
    }
    Node* newnode=new Node;
    newnode->data=a;
    newnode->next=temp->next; //Order should be always this first define the address(next) of newnode then point any other node to it. 
    temp->next=newnode;        
    
}

int LinkedList::deleteElement(int data)
{   
    Node *ele=head;   
	while(ele->data!=data){
		prev=ele;  //prev demolish the need to have another node temp.
		ele=ele->next;
	}
	prev->next=ele->next;  //Breaking the link of ele node from the linked list.
	delete ele;
}

int LinkedList::deletePosition(int pos)
{   
    Node *ele=head;
	while(pos>0)
	{
		prev=ele;
		ele=ele->next;
		pos--;
	}
	prev->next=ele->next;
	delete ele;
}
int LinkedList::removeFront(){
    Node *temp=head;  
    head=temp->next; //Making temp(head)->next the new head.
    delete temp;
}


int LinkedList::sizeofList(){
    int count=0;
    Node* curr=head;
    while(curr!=NULL){
    	count++;
   	    curr=curr->next;
    }	
    cout<<"\n";
    cout<<"Size of List: "<<count<<endl;
}

int LinkedList::printList(){
    Node* list=head;   //Name Overriding sol'n: Dont take head directly store it in another node otherwise outof sizeof function and this function only one will print.
	while(list!=NULL){
        cout<<list->data<<"-->";
        list=list->next;
    }
}

int LinkedList::reverseList()
{   
    Node* prev=NULL;            //Convert HEAD-100-200-300-400-500-NULL
    Node* current=head;
	Node* another;              //Into HEAD-500-400-300-200-100-NULL
	while(current!=NULL && current->data% 2==0)
	{   
	    another= current->next;  //stores the next(address) of current in a variable another.
	    current->next=prev;        //Stores current->next in "another" so it will not point to NULL again in second step.
	    prev=current;  
		current=another;	
	}
	
	head=prev; //Storing our prev-address in the head.(means making prev our head).
	
}
// Need to make changes in swapData func.
int LinkedList::swapData(int x,int y)
{   
    Node* curra;
	Node* currb;
	Node* swap;   
    while(head!=NULL)
	{
        if(curra->data==x && currb->data==y)
        {
            swap=curra->next;
    	    curra->next=currb->next;
    	    currb->next=swap->next;
	    }head=head->next;
    }
}

bool LinkedList::searchElement(int data)
{   
    Node *curr2=head;
	while(curr2!=NULL)
	{ 
        if(curr2->data==data){
		    return true;
		}
		curr2=curr2->next;	  
	}
	return false;
}

int main()
{   
    LinkedList p;
    cout<<"Linked List: ";
    p.addFront(12);
    p.addFront(6);
    p.addFront(9);
    p.addFront(7);
    p.addFront(5);
    p.addFront(3);
    p.addFront(24);
    p.addFront(18);
    p.addFront(2);
    p.removeFront();
    p.addElement(6,4);
    p.deleteElement(9);
    p.deletePosition(3);
    p.printList();
    p.sizeofList();
    p.searchElement(24)?cout<<"Yes Found":cout<<"Not Found";
    p.reverseList();
    cout<<"\n"<<"Reversed Linked List: ";
    p.printList();
    p.swapData(5,15);
    return 0;
}

