//Implement Circular Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Node Class 
template <typename T>
class Node
{
public:
    //data memebers
    T data;
    Node* nextNode;
    //constructor
    Node(T data = 0, Node* nextNode = 0)
    {
        this->data = data;
        this->nextNode = nextNode;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node ; Data = "<<this->data<<"\n";
    }

};

//Circular Singly Linked List
template <typename T>
class CirSinglyLinkedList
{
private:
    int totalNodes;
    Node<T> *head,*temp; 
public:
    //constructor
    CirSinglyLinkedList()
    {
        head = temp = 0;
        totalNodes = 0;
    }
    //destructor
    ~CirSinglyLinkedList()
    {
        system("CLS");
        temp = head;
        Node<T> *nextNodePtr;
        cout<<"Destroying The List\n";
        while(temp->nextNode != head)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        }
        delete temp;
        cout<<"\nDone.\n";
    }
    //member functions

    void search()
    {
        if(isEmpty())
        {
            //getting data value from User
            int query;
            int counter = 1;
            cout<<"Enter the data (*type - 'int') you want to Search : ";
            cin>>query;
            temp = head;
            do
            {
                if(temp->data == query)
                {
                    cout<<"Found @ Index - "<<counter<<"\n";
                    return;
                }
                temp = temp->nextNode;
                counter++;
            }while(temp != head);
            cout<<"Not Found\n";
        }
        else
        {
            cout<<"List Is Empty\n";
        }
        
    }

    //insert at begin
    void insertAtBegin()
    {
        //taking input from the user
        temp = new Node<T>();
        cout<<"Enter the Data of New Node : ";
        cin>>temp->data;
        //checking for empty list
        if(head == 0)
        {
            head = temp;
            head->nextNode = head;
            temp = 0;
        }
        else
        {
            //getting the tail
            Node<T>* tail = head;
            while(tail->nextNode != head)
            {
                tail = tail->nextNode;
            }
            //inserting the new node before head
            temp->nextNode = head;
            //changing head and tail
            head = temp;
            tail->nextNode = head;
            temp = tail = 0;
        }
        totalNodes++;  
    }

    //insert at end function
    void insertAtEnd()
    {
        //taking input from the user
        temp = new Node<T>();
        cout<<"Enter the Data of New Node : ";
        cin>>temp->data;
        //checking for empty list
        if(head == 0)
        {
            head = temp;
            head->nextNode = head;
            temp = 0;
        }
        else
        {
            //finding the tail of Linked List
            Node<T>* tail = head;
            while(tail->nextNode != head)
            {
                tail = tail->nextNode;
            }
            //inserting the Node at the End
            tail->nextNode = temp;
            tail->nextNode->nextNode = head;
            temp = tail = 0;
        }
        totalNodes++;
    }

    //insert at n-th location function
    void insertAtLoc()
    {
        //taking input from the user
        temp = new Node<T>();
        cout<<"Enter the Data of New Node : ";
        cin>>temp->data;
        temp->nextNode = 0;
        //taking location input
        int loc;
        cout<<"Enter Location : ";
        cin>>loc;
        if(loc < 0 || loc > totalNodes)
        {
            cout<<"Invalid Location\n";
            getch();
        }
        else if(loc == 1)
        {
            Node<T>* tail = head;
            while(tail->nextNode != head)
            {
                tail = tail->nextNode;
            }
            temp->nextNode = head;
            head = temp;
            tail->nextNode = head;
            tail = temp = 0;
            totalNodes++;
        }
        else
        {
            int counter = 1;
            Node<T>* requiredNode = head;
            while(counter != (loc-1))
            {
                requiredNode = requiredNode->nextNode;
                counter++;
            }
            temp->nextNode = requiredNode->nextNode;
            requiredNode->nextNode = temp;
            requiredNode = temp = 0;
            totalNodes++;
        }
    }

    //delete at begin
    void  deleteAtBegin()
    {
        if(totalNodes > 0)
        {
            if(head->nextNode == head)
            {
                temp = head;
                delete temp;
                head = temp = 0;
            }
            else
            {
                //get tail
                Node<T>* tail = head;
                while(tail->nextNode != head)
                {
                    tail = tail->nextNode;
                }
                temp = head;
                head = head->nextNode;
                tail->nextNode = head;
                delete temp;
                temp = 0;
            }
            totalNodes--;
        }
        else
        {
            cout<<"List is EMPTY\n";
            getch();
        }
    }

    //delete at the end
    void deleteAtEnd()
    {
        if(totalNodes > 0)
        {
            if(head->nextNode == head)
            {
                temp = head;
                delete temp;
                head = temp = 0;
            }
            else
            {
                //get that node behind the tail --->
                temp = head;
                while(temp->nextNode->nextNode != head)
                {
                    temp = temp->nextNode;
                }
                delete temp->nextNode;
                temp->nextNode = head;
                temp = 0;
            }
            totalNodes--;
        }
        else
        {
            cout<<"List is EMPTY\n";
            getch();
        }
        
    }

    //delete the n-th location function
    void deleteAtLoc()
    {
        //taking location input
        int loc;
        cout<<"Enter Location : ";
        cin>>loc;
        if(loc < 0 || loc > totalNodes)
        {
            cout<<"Invalid Location\n";
            getch();
        }
        else if(loc == 1)
        {
            temp = head;
            //finding tail
            Node<T>* tail = head;
            while (tail->nextNode != head)
            {
                tail = tail->nextNode;
            }
            //checking if the list has more than one item
            if(totalNodes == 1)
            {
                head = 0;
            }
            else
            {
                head = head->nextNode;
                tail->nextNode = head;
            }
            delete temp;
            totalNodes--;
        }
        else
        {
            int counter = 1;
            Node<T>* requiredNode = head;
            while (counter != (loc-1))
            {
                requiredNode = requiredNode->nextNode;
                counter++;
            }
            temp = requiredNode->nextNode;
            //checking if the next node is tail or not
            if(temp->nextNode == head)
            {
                requiredNode->nextNode = head;
            }
            requiredNode->nextNode = temp->nextNode;
            delete temp;
            temp = requiredNode = 0;
            totalNodes--;
        }
        
    }

    //traverse function
    void traverse()
    {
        //setting temp equal to head 
        //checking whether the List is Empty or Not
        if(head == 0)
        {
            cout<<"List is Empty\n";
        }
        else
        {
            temp = head;
            do
            {
                cout<<temp->data<<" ";
                temp = temp->nextNode;
            }
            while(temp != head);
            cout<<"\n";
            temp = 0;
        }
    }

    //isEmpty() function -> to check the number of Nodes in the Linked List
    int isEmpty()
    {
        if(totalNodes)
        {
            return totalNodes;
        }
        return 0;
    }
};


int main()
{
    CirSinglyLinkedList<int>* A = new CirSinglyLinkedList<int>();
    char flag = 'y';
    int choice;
    //menu
    do{
        // system("CLS");
        cout<<setw(20)<<setfill(' ')<<"CIRCULAR LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"List -> ";A->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Search \n"
            <<"2. Insert a Node at the Beginning\n"
            <<"3. Insert a Node at the End\n"
            <<"4. Insert a Node at a Certain Location\n"
            <<"5. Delete a Node at the Beginning\n"
            <<"6. Delete a Node at the End\n"
            <<"7. Delete a Node at a Certain Location\n"
            <<"8. Display Count\n"
            <<"9. Exit\n";
        //getting user input
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        //switch cases
        switch (choice)
        {
            case 1:
                A->search();
                getch();
                break;
            case 2:
                A->insertAtBegin();
                break;
            case 3:
                A->insertAtEnd();
                break;
            case 4:
                A->insertAtLoc();
                break;
            case 5:
                A->deleteAtBegin();
                break;
            case 6:
                A->deleteAtEnd();
                break;
            case 7:
                A->deleteAtLoc();
                break;
            case 8:
                cout<<A->isEmpty()<<"\n";
                getch();
                break;
            case 9:
                flag = 'n';
                break;
            default:
                break;
        }
        system("CLS");
    }
    while(flag == 'y');
    delete A;
    return 0;
}