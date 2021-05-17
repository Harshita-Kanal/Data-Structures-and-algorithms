// Linear Search
// ***************
// 
// This search technic works by searching linearly one by one.
// Generally linear search is performed on array.
// 
// Time Complexity: O(n)
// Space Complexity: O(n)
// 
// Algorithm: LinearSearch(Array, SearchValue)
//     Step1 - START
//     Step2 - for each item in the array
//     Step3 -     if item == SearchValue
//     Step4 -         return it's index
//     Step5 - return -1
//     Step1 - END
// 

using System;

public class Solution{
    public static int linearSearch(int[] arr, int arrLength, int searchValue){
        for(int i = 0; i < arrLength; i++){
            if(arr[i] == searchValue){
                return(i);
            }
        }
        return(-1);
    }

    public static void Main(String[] args) {
        int[] arr = {2, 5, 8, 2, 0, 3, 56, 6, 34, 546, 23, 76};
        int arrLength = 12;
        int searchItem = 5;
        int searchIndex = linearSearch(arr, arrLength, searchItem);
        if(searchIndex == -1){
            Console.Write("Search Item " + searchItem + " not found");
        }
        else{
            Console.Write("Search Item " + searchItem + " found at Array Index " + searchIndex);
        }      
    }
}
