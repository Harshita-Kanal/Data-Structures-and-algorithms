Sudoku Solver in CPP

#include<iostream>
#include<cmath>
using namespace std;

bool KyaRakhSkteHai(int mat[][9],int i,int j,int number,int n){
    // Check row and column
    for(int k=0;k<n;k++){
        if(mat[k][j] == number || mat[i][k]==number){
            return false;
        }
    }

    n = sqrt(n);
    int starti=(i/n)*n;//starting row
    int startj=(j/n)*n;//starting col

    //check 3x3 box
    for(int k=starti;k<starti+n;k++){//subgrids
        for(int l=startj;l<startj+n;l++){
            if(mat[k][l]==number){
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver(int mat[][9],int i,int j,int n){//i->row j->col
    if(i==n){
        // Print the sudoku
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(j==n){
        return SudokuSolver(mat,i+1,0,n);
    }

    if(mat[i][j]!=0){
        return SudokuSolver(mat,i,j+1,n);
    }


    for(int number = 1;number<=n;number++){
        if(KyaRakhSkteHai(mat,i,j,number,n)){
            mat[i][j] = number;
            bool KyaBaakiBaatBani = SudokuSolver(mat,i,j+1,n);
            if(KyaBaakiBaatBani){
                return true;
            }
            mat[i][j] = 0;
        }
    }

    return false;
}


int main(){
int mat[9][9] =
    {{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}};

    SudokuSolver(mat,0,0,9);


    return 0;
}
