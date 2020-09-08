#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t > 0){
        long int n;
        cin >> n;
        vector <int> a(n + 1);
        int i;
        for(i = 0; i < n; i++){
            cin >> a[i];
        }
        std::vector<int>::iterator x =  max_element(a.begin(), a.end());
        cout << *x;
    }

}
