#include <bits/stdc++.h>
using namespace std;

stack<int>_push(int arr[],int n);


void _pop(stack<int>s);


 // } Driver Code Ends


//User function Template for C++

/* _push function to insert elements of array to
   stack
*/
stack<int>_push(int arr[],int n)
{
   long int i;
   stack<int> st;
   for(i = 0; i < n; i++){
       st.push(arr[i]);
   }
   return st;
   //return a stack with all elements of arr inserted in it
}

/* _pop function to print elements of the stack
   remove as well
*/
void _pop(stack<int>s)
{
    while(!s.empty()){
        long int x = s.top();
        cout << x << " "; 
        s.pop();
    }
    //print top and pop 
    //for each element until it becomes empty
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _pop(mys);
	    cout<<endl;    
	    
	}
	return 0;
}

  // } Driver Code Ends
