//cpp program for union of two array
#include<iostream>
 
using namespace std;
 
int main()
{
	int a1[20],a2[20],u[40],i,j,k,n,m;
	
	cout<<"Enter size of first array:";
	cin>>n;
	cout<<"Enter elements of first array in ascending order:\n";
	for(i=0;i<n;++i){
		cin>>a1[i];
	}
	
	cout<<"\nEnter size of second array:";
	cin>>m;
	cout<<"Enter elements of second array in ascending order:\n";
	for(i=0;i<m;++i){
		cin>>a2[i];
	}
	
	for(i=0,j=0,k=0;i<n&&j<m;){
		if(a1[i]<a2[j]){
			u[k]=a1[i];
			i++;
			k++;
		}
		else if(a1[i]>a2[j]){
			u[k]=a2[j];
			j++;
			k++;
		}
		else{
			u[k]=a1[i];
			i++;
			j++;
			k++;
		}
	}
	
	if(i<n){
		for(;i<n;++i){
			u[k]=a1[i];
			k++;
		}
	}
	else if(j<m){
		for(;j<m;++j){
			u[k]=a2[j];
			k++;
		}
	}
	
	cout<<"\nUnion of two arrays is:\n";
	for(i=0;i<k;++i){
		cout<<u[i]<<" ";
	}
 
    return 0;
}