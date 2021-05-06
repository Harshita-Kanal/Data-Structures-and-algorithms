#include<bits/stdc++.h> 
using namespace std; 
  
class Graph 
{ 
    int V;     
    list<int> *adj;    
    void DFSUtil(int v, bool visited[]);   
public: 
    Graph(int V);   
    void addEdge(int v, int w);   
    void DFS();     
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
     
    visited[v] = true; 
    cout << v << " "; 
  
    
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
 
void Graph::DFS() 
{ 
    
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFSUtil(i, visited); 
} 
  
int main() 
{ 
    int v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    
    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    
    Graph g(v); 
    int a,b;
    for(int i=0;i<edges;i++){
       cin>>a>>b;
       g.addEdge(a,b);
    } 
  
    cout << "Following is Depth First Traversaln"; 
    g.DFS(); 
  
    return 0; 
} 
