#include<iostream>
#include<vector>
using namespace std;

vector<int>G[1000];
vector<bool>visited(1000,false);

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

int main()
{
	int n,e,count=0;
	cin>>n>>e;
	
    for(int i=1;i<=e;i++)
    {  
    	int u,v;
    	cin>>u>>v;
    	addedge(u,v);
    }

    for(int i=1;i<=n;i++)
    {
    	if(visited[i]==false)
    	{
    		dfs(i);
            count++;
        }
    }

    cout<<count;      
}