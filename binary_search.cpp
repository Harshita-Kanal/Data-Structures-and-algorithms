#include <iostream>
#include <cassert>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
long int binary_search_1(vector<long int> a, int x) {
 long int left = 0, right = (int)a.size();
 int mid ;
int i = 0;
 while(left < right){
    mid = (left + right) / 2;
    if(a[mid] == x){
        return mid;
    }
    else if(a[mid] < x){
        left= mid + 1;
    }
    else {
        right = mid - 1;
    }

 }
 return -1;

 }
  //write your code here


int linear_search(vector<long int> a, int x) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

//5 1 5 8 12 13
//5 8 1 23 1 11

int main() {
  int n;
  cin >> n;
  vector<long int> a(n);
  for (int i = 0; i < a.size(); i++) {
   cin >> a[i];
  }
  int m;
  cin >> m;
  vector<long int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
   // cout << linear_search(a, b[i]) << ' ';
    //cout<<endl;
    cout << binary_search_1(a, b[i]) << ' ';

  }
}
