/*
Finding the diameter of a tree using DFS twice.
First, we run DFS from the root node and find the longest node from the root.
Then, we run DFS from the longest node and find the diameter of the tree.
Contributed to Data-Structures-and-algorithms by Harshita Kanal on Github
Contributor: Santhosh-Vardhan
*/
#include<bits/stdc++.h>
using namespace std;
class tree
{
    int v;          //holds the number of vertices
    list<int> *adj; //adjacency list to represnt the graph
    bool *visited;  //to check if a node has already been visited
    int cres,mres;  //cres - holds the distance till the current node
                    //mres - holds the maximum distance so far
    int mloc;       //mloc - holds the longest node from the root 
    int longestPathUtil(int st, int isSt);//Utility function that runs dfs and finds the maximum distance
    void resetVals();//function to reset all the values 
    public:
        tree(int ver)//constructor that sets all the data members to valid base values
        {
            v = ver;
            adj = new list<int>[v];
            visited = new bool[v];
            for(int i = 0;i<v;i++)
            visited[i] = false;
            cres = 0;
            mres = 0;
        }
        void addEdge(int v1, int v2);//to add an edge to the graph
        int longestPath();//function that returns the longest path
};
void tree::resetVals()
{
    cres = 0;
    mres = 0;
    for(int i = 0;i<v;i++)
        visited[i] = false;
}
void tree::addEdge(int v1, int v2)
{
adj[v1].push_back(v2);
adj[v2].push_back(v1);
}
int tree::longestPathUtil(int st, int isSt)
{
    //isSt = -1 denotes that the node is the starting point in the DFS
    visited[st] = true;
    for(auto it = adj[st].begin(); it!= adj[st].end();it++)//to run DFS 
    {
        if(isSt==-1)
            cres = 0;
        if(!visited[*it])
        {
            cres++;//increasing the current distance everytime a new deeper node is visited
            if(cres>mres)
            {
                //changing the values of mloc and mres accordingly
            mloc = *it;
            mres = cres;
            }
            longestPathUtil(*it,1);//recursive DFS
            cres--;//decrementing current distance everytime we move a level up
            }
    }
    if(isSt==-1)//return the maximum distance in case of beginning node
    return mres;
    else
    return 0; 
}
int tree::longestPath()
{
    longestPathUtil(0,-1);//Finding the longest node from root
    resetVals();
    int longest =  longestPathUtil(mloc,-1);//finding the longest path from the longest node
    resetVals();
    return longest;//return the longest path
}
int main()
{
    int n,i;
    cin>>n;//number of vertices in the tree
    tree t1(n);
    for(i = 0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        t1.addEdge(u-1,v-1);
    }
    cout<<t1.longestPath();
}
