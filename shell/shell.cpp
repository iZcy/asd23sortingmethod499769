#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

milliseconds deltaInit;
milliseconds deltaVal;

// Shell Sort algorithm from https://www.geeksforgeeks.org/shellsort/
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
  
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void countTime(int cond = 0 /*0 = set start, 1 = stop count, 2 = print count*/) {
    if (cond == 0)
        deltaInit = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    else if (cond == 1)
        deltaVal = duration_cast< milliseconds >(system_clock::now().time_since_epoch()) - deltaInit;
    else if (cond == 2)
        cout << "Interval : " << to_string(deltaVal.count()) << "ms" << endl;
}

void shellSortRes(int* arr={0}, unsigned int n=1, bool print=false) {
    if (print) {
        cout << "Array before sorting: \n";
        printArray(arr, n);
    }
    
    countTime(0);
    shellSort(arr, n);
    countTime(1);
  
    if (print) {
        cout << "\nArray after sorting: \n";
        printArray(arr, n);
        cout << "\n";
    }
}

int main() {


    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    shellSortRes(arr2, n2, false);

    countTime(2);
    return 0;
}