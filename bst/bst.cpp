// C++ program to implement Tree Sort
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

struct Node
{
	int key;
	struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Stores inorder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
	if (root != NULL)
	{
		storeSorted(root->left, arr, i);
		arr[i++] = root->key;
		storeSorted(root->right, arr, i);
	}
}

/* A utility function to insert a new
Node with given key in BST */
Node* insert(Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key <= node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) Node pointer */
	return node;
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n)
{
	struct Node *root = NULL;

	// Construct the BST
	root = insert(root, arr[0]);
	for (int i=1; i<n; i++)
		root = insert(root, arr[i]);

	// Store inorder traversal of the BST
	// in arr[]
	int i = 0;
	storeSorted(root, arr, i);
}

// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
    cout << endl;
}

// Driver Program to test above functions
int main()
{
	//create input array
	int n = sizeof(arr)/sizeof(arr[0]);

    //cout << "Given array is \n";
	//printArray(arr, n);

    countTime(0);
	treeSort(arr, n);
    countTime(1);

    //cout << "\nSorted array is \n";
	//printArray(arr, n);

    countTime(2);
	return 0;
}