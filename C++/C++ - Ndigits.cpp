/*
program to find no. of digits in given no.
It can be done in many ways but i am showing only 2 ways

1st :-
ndigits :- Time complexity O(log(n)) log of base 10
2nd :-
constant :- Time complexity O(1)  using log10 algorithm which is constant time algorithm

*/
#include<bits/stdc++.h>
using namespace std;

int ndigits(int n);
int constant(int n);
int main()
{
	int n;
	cout<<"\nEnter the no. :: ";
	cin>>n;
	int res=ndigits(n);
	cout<<"\nAnswer from ndigits function "<<res;
	
	int ans=constant(n);
	cout<<"\nAnswer from constant operation "<<ans;
return 0;
}

// Driver code ends here

int ndigits(int n)
{
	int count=0;
	while(n)
	{
		count++;		//if you take remainder and add them at each step then you can find the sum of the digits of no.
		n/=10;
	}
	return count;
}

int constant(int n)
{
	return floor(log10(n))+1;
}
