#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#define size 200000

using namespace std;
int main() {
    int arr[size];

    string fileName = "generated_dataset_forRadix.txt";

    ofstream outfile;
    
    cout << "Opening file..." << endl;
    outfile.open(fileName);
    cout << "File opened." << endl;

    srand((unsigned) time(0));
    cout << "Generating..." << endl;
    for (long long int i = 0; i < size; i++)
        arr[i] = (unsigned int) rand();
    cout << "Generattion finished."  << endl;

    cout << "Inserting to " << fileName << "..." << endl;
    for (long long int i = 0; i < size; i++)
        outfile << arr[i] << ((i + 1 == size) ? "" : ", ");
    cout << "Insertion finished."  << endl;

    cout << "Closing file..." << endl;
    outfile.close();
    cout << "File closed." << endl;

    return 0;
}