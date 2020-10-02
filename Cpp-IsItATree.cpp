#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
#define endl "\n"
#define ll long long

const int N = 1e5 + 5;
const unsigned int M = 1000000007;
ll a[N],b[N]; 

const int MX = 100010;      // maximum no. of nodes in graph
vector<bool> visited(MX+1,0);
vector<int>G[MX+1];  

void addedge(int u,int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
 
void dfs(int x)
  {
    visited[x]=true;
    for(auto& i : G[x])
    {
      if(visited[i]==false)
        dfs(i);
    }
  }

int32_t main ()
{
  int n,m,t; cin>>n>>m;
   t=m;
   while(t--)
   {
     int u,v;  cin>>u>>v;
     addedge(u,v); 
   } 
    int count=0;
    for(int i=1;i<=n;i++)
      {
        if(!visited[i])
        {
          dfs(i);
          count++;
        }
      }
    
      if(m==n-1 and count==1)
        cout<<"YES";
      else
        cout<<"NO";
  return 0;
}