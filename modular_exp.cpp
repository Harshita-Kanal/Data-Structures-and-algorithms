#include<iostream>
using namespace std;
typedef long long ll;

ll powm(ll a, ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        b=b/2;
        a=(a*a)%m;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<powm(7,256,13);
    //ans is 9
}