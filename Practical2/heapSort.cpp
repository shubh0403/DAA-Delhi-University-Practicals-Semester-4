#include <iostream>
#include <fstream>
using namespace std;

// Max Heapify function
int max_heapify(int arr[], int i, int size)
{
    int count = 0; // comparison counter
    int maxIndex = i;
    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child

    // Comparisons with left child
    if (l < size && arr[l] > arr[maxIndex])
        maxIndex = l;
    // Comparisons with left child
    if (r < size && arr[r] > arr[maxIndex])
        maxIndex = r;

    // Main logic
    if (i != maxIndex)
    {
        count++;
        swap(arr[i], arr[maxIndex]);
        count += max_heapify(arr, maxIndex, size);
    }
    return count;
}

/*
    Build Heap function - iterating over all the
    non leaf nodes and applying max_heapify
*/
int buildMaxHeap(int arr[], int size)
{
    int count = 0;
    for (int i = size / 2 - 1; i >= 0; --i)
        count += max_heapify(arr, i, size) + 1;
    return count;
}

/*
    Heap Sort function - iterates (size-1) times,
    swap max element (root) and last element and then
    applying max_heapify on root element (and decrease size by 1)
*/
int heapSort(int arr[], int size)
{
    int count = buildMaxHeap(arr, size);
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        count += max_heapify(arr, 0, i) + 1;
    }
    return count;
}

int main()
{
    // Number of iterations
    int n = 100;

    // Opening and initializing file
    ofstream outputFile("data.csv");

    for (int i = 0; i < n; i++)
    {
        int size;
        // Taking a random size between 30 and 1000
        do
        {
            size = rand() % 1000;
        } while (size < 30 || size > 1000);
        int *arr = new int[size];

        // Initializing array with random values
        for (int j = 0; j < size; j++)
        {
            arr[j] = rand() % 1000;
        }

        // Initializing comps and applying heap sort
        int comps = heapSort(arr, size);

        // Saving data to file
        outputFile << "\n"
                   << size << "," << comps;
    }

    outputFile.close(); // Close the file
    cout << endl;
    return 0;
}