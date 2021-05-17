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

function linearSearch(arr, searchValue){
    for( let i = 0; i < arr.length; i++){
        if(arr[i] == searchValue){
            return i;
        }
    }
    return -1;
}

var arr = [2, 5, 8, 2, 0, 3, 56, 6, 34, 546, 23, 76]
var searchItem = 5
var searchIndex = linearSearch(arr, searchItem)
if(searchIndex == -1){
    console.log("Search Item ", searchItem, " not found")
}
else{
    console.log("Search Item ", searchItem, " found at Array Index ", searchIndex)
}
