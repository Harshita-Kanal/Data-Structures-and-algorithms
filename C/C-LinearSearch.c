//
//  main.c
//  LinearSearch
//
//  Created by Sydnie Nguyen on 3/15/21.

/* Linear search is an algorithm that finds a value in a array or list by searching through
 every value and returns the index of the value.  This code is written in c
 */
// input: length l of the array,an array x of integer and query needed to be found q
// output: index of the query or Not found if no query found

#include <stdio.h>

// this function will look for the query using linear search
/*
 x[] is the array
 n is the length of the array
 q is the value that is being looked for
 */

int looking(int x[], int n, int q){
    
    for (int i= 0; i<n; i++){
        if (x[i]==q)
            return i;
    }
        return -1;
}

int main(int argc, const char * argv[]) {
    
    // asking user to input the length of the array
    int l;
    printf("Enter length of array: ");
    scanf("%d", &l);
    
    // asking user to input the list of values
    int x[l];
    for (int i=0; i<l; i++){
        printf("Enter value #%d: ",i);
        scanf("%d", &x[i]);
    }
    
    // asking user for value to find
    int q=1;
    printf("Enter value to be found: ");
    scanf("%d", &q);
    
    // function call to look for the value
    // result will be the index of the value
    int result= looking( x, l, q );

    // prints and outputs the index of the query
    if (result==-1) {
        printf("Not found\n");
    }
    else {
        printf("%d is at index %d\n", q,result);
    }
    
    return 0;
}
