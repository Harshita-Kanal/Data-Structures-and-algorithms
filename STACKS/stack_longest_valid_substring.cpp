// C++ program to find length of the longest valid 
// substring 
#include<bits/stdc++.h> 
using namespace std; 

int findMaxLen(string str) 
{ 
	int n = str.length(); 

	// Create a stack and push -1 as initial index to it. 
	stack<int> stk; 
	stk.push(-1); 

	// Initialize result 
	int result = 0; 

	// Traverse all characters of given string 
	for (int i=0; i<n; i++) 
	{ 
		// If opening bracket, push index of it 
		if (str[i] == '(') 
		stk.push(i); 

		else // If closing bracket, i.e.,str[i] = ')' 
		{ 
			// Pop the previous opening bracket's index 
			stk.pop(); 

			// Check if this length formed with base of 
			// current valid substring is more than max 
			// so far 
			if (!stk.empty()) 
				result = max(result, i - stk.top()); 

			// If stack is empty. push current index as 
			// base for next valid substring (if any) 
			else stk.push(i); 
		} 
	} 

	return result; 
} 

int main() 
{ 
	string str = "((()()"; 
	cout << findMaxLen(str) << endl; 

	str = "()(()))))"; 
	cout << findMaxLen(str) << endl ; 

	return 0; 
} 
