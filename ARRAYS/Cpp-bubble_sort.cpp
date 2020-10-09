#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int> arr)
{
    int n=arr.size();
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int aux = arr[j];
				arr[j] = arr[i];
				arr[i] = aux;
			}
		}
	}
	return arr;
}

int main()
{

	vector<int> arr = { 6, 3, 7, 1, 12, 5, 43, 21 ,8 ,9 };

    arr=bubble_sort(arr);

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i]<< ' ';
}
