#include <iostream>
using namespace std;
void spiral(int n,int m,int a[][1000]){
    
    int start_row=0;
    int start_col=0;
    int end_col=n-1;
    int end_row=m-1;
    while(start_row<=end_row and start_col<=end_col){
        
      //FIRST ROW  
    for (int i=start_col;i<=end_col;i++){
        cout<<a[start_row][i]<<" ";
    }
    start_row++;
    //LAST COLUMN
    for(int i =start_row;i<=end_row;i++){
        cout<<a[i][end_col]<<" ";
    }
    end_col--;
    //LAST ROW
    if(end_row>start_row){
    for(int i=end_col;i>=start_col;i--){
        cout<<a[end_row][i]<<" ";
    }
    end_row--;
    }
    //FIRST COLUMN
    if(end_col>start_col){
    for(int i =end_row;i>=start_row;i--){
        cout<<a[i][start_col]<<" ";
    }
    start_col++;
    }
    }
    
    
    
    
}

int main()
{
    int m,n;
    int a[1000][1000]={0};
    cin>> m>> n;
     int x=1;
    for (int row=0;row<=m-1;row++){
      
        for(int col=0;col<=n-1;col++){
            a[row][col]=x;
             x=x+1;
            cout<<a[row][col]<<" ";
            
        }
        cout<<endl;
    }
    spiral(n,m,a);
    
    return 0;
}