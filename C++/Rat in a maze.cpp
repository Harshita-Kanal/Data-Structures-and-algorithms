#include<iostream> 
using namespace std;
#define N 4

bool solve(int a[N][N], int x, int z) 
{ 
    if (x >= 0 && x < N && z >= 0 && z < N && a[x][z] == 1) 
    {
        return true; 
    }
    return false; 
} 
bool maze(int a[N][N], int x, int z, int s[N][N]) 
{ 
    if (x == N - 1 && z == N - 1 && a[x][z] == 1) 
    { 
        s[x][z] = 1; 
        return true; 
    } 
    if (solve(a, x, z) == true) 
    { 
        s[x][z] = 1; 
        if (maze(a, x + 1, z, s)== true) 
        {
            return true; 
        }
        if (maze(a, x, z + 1, s)== true) 
        {
            return true; 
        }
        s[x][z] = 0; 
        return false; 
    } 
    return false; 
} 
void print(int s[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        {
            cout<<" "<<s[i][j]<<" "; 
        }
        cout<<"\n"; 
    } 
} 
bool solution(int a[N][N]) 
{ 
    int s[N][N] = { { 0, 0, 0, 0 }, 
                    { 0, 0, 0, 0 }, 
                    { 0, 0, 0, 0 }, 
                    { 0, 0, 0, 0 } }; 
  
    if (maze(a, 0, 0, s)== false) 
    { 
        cout<<"Solution doesn't exist"; 
        return false; 
    } 
    print(s); 
    return true; 
} 
int main() 
{ 
    int a[N][N] = { { 1, 0, 0, 1 }, 
                    { 1, 1, 0, 1 }, 
                    { 0, 1, 0, 1 }, 
                    { 0, 1, 1, 1 } }; 
    solution(a); 
    return 0; 
} 
