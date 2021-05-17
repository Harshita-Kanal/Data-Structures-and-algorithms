#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int val)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		front=rear;
		rear=newnode;
	}
	else
	{   newnode->data=val;
		rear->next=newnode;
		rear=rear->next;
		rear->next=NULL;
		printf("data inserted is :%d",val);
	}
}
void dequeue()
{
	struct node *temp;
	if(front==NULL)
	{
	    printf("Queue is empty");
	}
	else
	{
		temp=front;
		front=front->next;
		free(temp);
	}
}
void display(struct node *temp1)
{ 
     while(temp1->next!=NULL)
     {
     	printf("%d",temp1->data);
        temp1=temp1->next;
     }
     
}
int main()
{
		int ch;
	do
	{
		printf("enter your choice:1 to insert,2 to delete,3 to display,4 to exit");
		scanf("%d",&ch);
	switch(ch)
    {  

		case 1:enqueue(12);
		       enqueue(13);
		       enqueue(14);
		break;
		case 2:dequeue();
		break;
		case 3:display(front);
		break;
		case 4:exit(0);
		break;
    }
    }
	while(ch!=4);
return 0;
}


