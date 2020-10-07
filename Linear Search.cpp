#include <iostream>
using namespace std;

//Return value if we don't find value in array
int linSearch(int array[], int size, int searchVal)
{
	for (int i = 0; i < size; i++)
	{
		if (searchVal == array[i])
		{
			return i;
		}
	}
	//Indicating we did not find it
	return -1;
}

int main()
{
	int data[] = { 37,96,16,87,19,20 };

	//Ask user to input value that they want to search
	int value;
	cout << "Enter an integer: " << endl;
	cin >> value;

	//6 is for the size of the array data
	int result = linSearch(data, 6, value);

	if (result >= 0)
	{
		cout << data[result] << "Was found in integer with index: " << result << endl;
	}
	else
	{
		cout << value << "Not found." << endl;
	}
	
}


