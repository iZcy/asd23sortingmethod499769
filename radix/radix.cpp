// C++ implementation of Radix Sort
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

// A utility function to get maximum value in arr[]
int getMax(int arr[], const long long int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], const long long int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], const long long int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], const long long int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
	const long long int n = sizeof(arr) / sizeof(arr[0]);
	
    //cout << "Given array is \n";
	//print(arr, n);
    
    // Function Call
    countTime(0);
	radixsort(arr, n);
    countTime(1);

    //cout << "\nSorted array is \n";
	//print(arr, n);
    countTime(2);
	return 0;
}