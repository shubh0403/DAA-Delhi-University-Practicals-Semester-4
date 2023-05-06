#include <iostream>
#include <fstream>
using namespace std;

// Comparison Counter
int comps;

// Function to make partitions of array according to a pivot
int partition(int array[], int low, int high)
{
    // Select the pivot element
    int pivot = array[high];
    int i = (low - 1);

    // Put the elements smaller than pivot on the left
    // and greater than pivot on the right of pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
            comps++; // Comparison + 1
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

// Function to generate random pivot, and then
// call partition on that pivot
int randomPartition(int arr[], int low, int high)
{
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

// Quick Sort function
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // Make partition based on random pivot
        int pi = randomPartition(array, low, high);

        // Sort the elements on the left of pivot
        quickSort(array, low, pi - 1);

        // Sort the elements on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// Main function
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

        // Initializing comps and applying Quick sort algorithm
        comps = 0;
        quickSort(arr, 0, size);

        // Saving data to file
        outputFile << "\n" << size << "," << comps;
    }

    outputFile.close(); // Close the file
    cout << endl;
    return 0;
}