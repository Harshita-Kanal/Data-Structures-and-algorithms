#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
//quick sort is another one of my favorite algorithms
void quicksort(int data[ ], size_t n);

void partition(int data[ ], size_t n, size_t& pivot_index);
// Precondition: n > 1, and data is an array (or subarray)
// with at least n elements.
// Postcondition: The function has selected some "pivot value"
// that occurs in data[0]..data[n-1]. The elements of data
// have then been rearranged, and the pivot index set so that:
//   -- data[pivot_index] is equal to the pivot;
//   -- Each item before data[pivot_index] is <= the pivot;
//   -- Each item after data[pivot_index] is >= the pivot.


int main( ){
    const char BLANK = ' ';
    const size_t ARRAY_SIZE = 10;
    int data[ARRAY_SIZE];
    int user_input;
    size_t number_of_elements;
    size_t i;

    // Provide some instructions
    cout << "Please type up to " << ARRAY_SIZE << " positive integers.";
    cout << " Indicate the list's end with a zero." << endl;

    // Read the input numbers
    number_of_elements = 0;
    cin >> user_input;
    while ((user_input != 0) && (number_of_elements < ARRAY_SIZE))
    {
        data[number_of_elements] = user_input;
        number_of_elements++;
        cin >> user_input;
    }

    // Sort the numbers and print the result with two blanks after each number
    quicksort(data, number_of_elements);
    cout << "In sorted order, your numbers are: " << endl;
    for (i = 0; i < number_of_elements; i++)
        cout << data[i] << BLANK << BLANK;
    cout << endl;

    return 0;
}

void quicksort(int data[ ], size_t n)
// Library facilities used: cstdlib
{
    size_t pivot_index; // Array index for the pivot element
    size_t n1;          // Number of elements before the pivot element
    size_t n2;          // Number of elements after the pivot element

    if (n > 1)
    {
        // Partition the array, and set the pivot index.
        partition(data, n, pivot_index);

        // Compute the sizes of the subarrays.
        n1 = pivot_index;
        n2 = n - n1 - 1;

        // Recursive calls will now sort the subarrays.
        quicksort(data, n1);
        quicksort((data + pivot_index + 1), n2);
    }
}

void partition(int data[ ], size_t n, size_t& pivot_index)
{
    int too_big_index = 1;
    int too_small_index = n-1;
    int pivot = data[0];

    while(too_big_index<=too_small_index){
      while((too_big_index < n) && (data[too_big_index] < pivot)){
        ++too_big_index;
      }
      while((data[too_small_index]) > pivot){
        --too_small_index;
      }

      if(too_big_index < too_small_index){
        int temp = data[too_big_index];
        data[too_big_index] = data[too_small_index];
        data[too_small_index] = temp;
      }

    }

    if(too_big_index > too_small_index){
      pivot_index = too_small_index;
      data[0] = data[pivot_index];
      data[pivot_index] = pivot;
    }

}