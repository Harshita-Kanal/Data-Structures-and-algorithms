#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void push()
{   
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	
	    printf("enter data to be inserted");
		scanf("%d",&newnode->data);
		newnode->next=top;
		top=newnode;
	
}
void pop()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("Stack is Empty");
	}
	else
	{
	temp=top;
	top=top->next;
	free(temp);
    }
}
void display()
{   
    struct node *temp1;
    top=temp1;
     printf("enter data to display");
	    scanf("%d",&temp1->data);
	while(temp1!=NULL)
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
		printf("enter your choice:1 to push,2 to pop,3 to display,4 to exit");
		scanf("%d",&ch);
	switch(ch)
    {  

		case 1:push();
		break;
		case 2:pop();
		break;
		case 3:display();
		break;
		case 4:exit(0);
		break;
    }
    }
	while(ch!=4);
return 0;
}
