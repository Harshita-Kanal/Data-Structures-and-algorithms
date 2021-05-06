/*
program to find maximum and minimum in array

STL library of C++ provides builtin method to find maximum and minimum in array,vector,string and many other data structures

#include<algorithm>
int mx=*max_element(ar,ar+n) // n is length of array
int mx=*max_element(vec.begin(),vec.end()) // for vector and string

similarly minimum can be found just replace max with min

*/
#include<iostream>
using namespace std;
int maximum(int ar[],int n);
int minimum(int ar[],int n);
int main()
{
	int n;
	cout<<"\nEnter the size of array :: ";
	cin>>n;
	int ar[n];
	cout<<"Enter the element of array \n";
	for(int i=0;i<n;i++)
	cin>>ar[i];
	cout<<"\nMaximum element in array is :: "<<maximum(ar,n);
	cout<<"\nMinimum element in array is :: "<<minimum(ar,n);
return 0;
}

//Driver code end here

int maximum(int ar[],int n)
{
	int mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(mx<ar[i])		// the statement can also be written as mx=max(ar[i],mx) or mx=(mx<ar[i])? ar[i] : mx;
		{
			mx=ar[i];
		}
	}
	return mx;
}

int minimum(int ar[],int n)
{
	int mi=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(mi>ar[i])		// the statement can also be written as mi=min(ar[i],mi) or mi=(mi>ar[i])? ar[i] : mi;
		{
			mi=ar[i];
		}
	}
	return mi;
}
