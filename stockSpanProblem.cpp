// Span of an element is the number of contiguous elements that are less than or equal to that element including that element....

// 0(n) time and 0(n) space

// The idea is to find the position-wise closest greater element to the left of that element

// If you see a smaller element, you push it into the stack and if you see a greater element, you pop all the top smaller elements...

#include <bits/stdc++.h>
using namespace std;

void findstockSpan(int *arr,int n){
    stack <int> s;
    s.push(0);
    cout<<1<<" ";
    for(int i=1;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i])
            s.pop();
        int span=(s.empty())?(i+1):(i-s.top());
        cout<<span<<" ";
        s.push(i);
    }
}
// Every element goes into the stack and comes out of the stack exactly once. Hence 0(n)

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    findstockSpan(arr,n);

    delete [] arr;
    return 0;
}
