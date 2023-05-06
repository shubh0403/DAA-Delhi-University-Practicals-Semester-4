#include <iostream>
#include <fstream>
using namespace std;

// Insertion Sort Function - return type is set to integer as number of comparisons needs to be returned
template <class T>
int insertionSort(T arr[], int size)
{
    T key;
    int i, j, comp = -1;
    for (i = 0; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            comp++;
            arr[j + 1] = arr[j];
            j--;
        }
        comp++;
        arr[j + 1] = key;
    }
    return comp; // Returns no. of comparisons
}

int main()
{

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

        // Initializing array with random values till 1000
        for (int j = 0; j < size; j++)
        {
            arr[j] = rand() % 1000;
        }

        // Applying insertion sort
        int comp = insertionSort<int>(arr, size);

        // Saving data to file
        outputFile << "\n"<< size << "," << comp;
    }
    outputFile.close();
    cout << endl;
    return 0;
}