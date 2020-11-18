#include<iostream>
#include<string>


class stack //created class name STACK
{
	private : 
		int top;
		int arr[5];
		
	public :
		stack()
		{
			top = -1;
			for(int i = 0; i<5; i++)
			{
				arr[i] = 0;
			}
		}
		
		
	// check Stack empty or not	
		bool isEmpty()
		{
			if(top == -1)
				return true;
			else
				return false;
		}
		
	// check Stack full or not 	
		bool isFull()
		{
			if(top == 4)
				return true;
			else
				return false;
		}
		
	// Push Operation	
		void push(int val)
		{
			if(isFull())
			{
				cout << "stack overflow" << endl;
			}
			else
			{
				top++;
				arr[top] = val;
			}
		}
		
	// Pop operation	
		int pop()
		{
			if(isEmpty())
			{
				cout << "stack underflow" << endl;
				return 0;	
			}	
			else
			{
				int popValue = arr[top];
				arr[top] = 0;
				top--;
				return popValue;
			}
		}
		
	// Count operation
		int count()
		{
			return(top+1);
		}

	// Peek operation
		int peek(int pos)
		{
			if(isEmpty())
			{
				cout << "Stack Underflow" << endl;
				return 0;
			}
			else
			{
				return arr[pos];
			}
		}
		
	// Change operation
		void change(int pos, int val)
		{
			arr[pos] = val;
			cout << "Value changed at location " << pos << endl ;
			for(int i = 4; i >= 0; i++)
			{
				cout << arr[i] << endl;
			}
		}
		
	// Display operation
		void display()
		{
			cout << "All the value in the stack are : ";
			
			for(int i = 4; i<=0; i++)
			{
				cout << arr[i] << endl ;
			}
		}
};

// Main Function.
int main()
{
	stack s1;
	int option, position, value;
	
	do
	{
		cout << "\n\nWhat operation you want to perform ? \n Enter 0 to exit \n";
		cout << "1. Push()" << endl;	
		cout << "2. Pop()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. isFull()" << endl;
		cout << "5. Peek()" << endl;
		cout << "6. Count()" << endl;
		cout << "7. Change()" << endl;
		cout << "8. Display()" << endl;
		cout << "9. Clear Screen()" << endl;
		
		cout << "\nEnter option : " ;
		cin >> option ;
		
		switch(option)
		{
			case 1 : cout << "\nEnter element to be pushed : ";
					 cin  >> value;
					 s1.push(value);
					 break;
					 
		    case 2 : cout << "\nPop done" << s1.pop() << endl ;
		    		 break;
		    
			case 3 : if(s1.isEmpty())
						cout << "\nStack Empty" << endl;
			         else
						cout << "\nStack is not empty" << endl;
				     break;
		    
		    case 4 : if(s1.isFull())
		             	cout << "\nStack is full " << endl;
					 else
					 	cout << "\nStack not full " << endl;
					 break;
					 
			case 5 : cout << "\nEnter the position of the item you want to peek : ";
				     cin >> position;
				     cout << "\npeek position called at positon " << position << "is"<< endl;
				     s1.peek(position);
				     break;
			
			case 6 : cout << "\nCount function called - Number of items in stack are : " << s1.count() << endl;
			         break;
			         
		    case 7 : cout << "\nChanged function called " << endl ;
		    		 cout << "\nEnter the position you want to change : ";
		    		 cin  >> position;
		    		 cout << "\nEnter the value of item : ";
		    		 cin  >> value;
		    		 
		    		 s1.change(position,value);
		    		 break;
		    		 
		    case 8 : cout << "\nDisplay function called - " << endl;
		             s1.display();
		             break;
		    
		    case 9 : system("cls");
		             break;
		    
		    default : cout << "Enter approcriate option ";
		    
		}
   }while(option != 0);

}
