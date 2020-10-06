// Quick sort algorithm in C++

#include <iostream>
using namespace std;

// Swapping position of elements
void swapPositions(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

// Printing elements of an array
void printArrayElements(int array[], int size) {
  int i;
  for (i = 0; i < size; i++){
  	cout << array[i] << " ";
  }
  cout << endl;
}

// Partitioning the array
int partitionArray(int array[], int low, int high,int n) {
  int pivot = array[high]; //Pivot Element
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swapPositions(&array[i], &array[j]);
    }
  }
  printArrayElements(array, n);
  cout << "______________________________________________\n";
  swapPositions(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high,int n) {
  if (low < high) {
    int pi = partitionArray(array, low, high,n);

    // Sorting elements on the left of pivot
    quickSort(array, low, pi - 1,n);

    // Sorting elements on the right of pivot
    quickSort(array, pi + 1, high,n);
  }
}


int main() {
  int data[] = {9,10,11,4,6,3,7,1,5,0,15};
  int n = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, n - 1,n);
  cout << "\nSorted array in ascending order using the Quick Sort Algorithm: \n";
  printArrayElements(data, n);
}
