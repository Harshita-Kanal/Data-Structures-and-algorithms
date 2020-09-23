#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long int get_majority_element(vector<long int> a,int left, int right) {
 // if (left == right) return -1;
  //if (left + 1 == right) return a[left];
  //else
  /*{
      int mid = (left + right) / 2;
      left = mid + 1;
      get_majority_element(a, left, mid - 1);
      right =  mid - 1;
      get_majority_element(a, mid + 1, right);

  }*/
 long int n = a.size();
 long int temp = a[0], tag = 1, i;
  sort(a.begin(), a.end());
  for(i = 0; i < a.size() - 1; i++){
    if(a[i + 1] == a[i] && tag <= n /2){
        temp = a[i];
        tag++;
    }
    else if(tag > n/2){
        return temp;
    }

   else if(a[i + 1] != a[i] && tag <= n /2){
        temp = a[i];
        tag = 1;
    }
  }

}

int main() {
  int n;
  cin >> n;
  vector<long int> a(n);
  for (int i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
 cout << get_majority_element(a, 0, a.size()) << '\n';
}
