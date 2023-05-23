// C code to implement quicksort
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

milliseconds deltaInit;
milliseconds deltaVal;

void countTime(int cond = 0 /*0 = set start, 1 = stop count, 2 = print count*/) {
    if (cond == 0)
        deltaInit = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    else if (cond == 1)
        deltaVal = duration_cast< milliseconds >(system_clock::now().time_since_epoch()) - deltaInit;
    else if (cond == 2)
        cout << "Interval : " << to_string(deltaVal.count()) << "ms" << endl;
}

// Function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
	// Choosing the pivot
	int pivot = arr[high];
	
	// Index of smaller element and indicates
	// the right position of pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			
			// Increment index of smaller element
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		
		// pi is partitioning index, arr[p]
		// is now at right place
		int pi = partition(arr, low, high);
		
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], const long long int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
	int N = sizeof(arr) / sizeof(arr[0]);

    //cout << "Given array is \n";
	//printArray(arr, N);

	// Function call
    countTime(0);
	quickSort(arr, 0, N - 1);
    countTime(1);

	//cout << "\nSorted array is \n";
	//printArray(arr, N);

    countTime(2);
	return 0;
}