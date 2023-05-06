#include <iostream>
#include <string>

using namespace std;

struct bucket
{
    int ptr;
    float *value;
};

template <typename T>
void insertionSort(T arr[], int size)
{
    T key;
    int i, j;
    for (i = 0; i < size; ++i)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(float ar[], int size, string str)
{
    cout << str << "[";
    for (int i = 0; i < size; ++i)
    {
        cout << (i == 0 ? "" : ", ") << ar[i];
    }
    cout << "]" << endl;
}

// Bucket Sort Function
void bucketSort(float ar[], int n)
{
    struct bucket B[n];
    for (int i = 0; i < n; i++)
    {
        B[i].ptr = -1;
        B[i].value = new float[n];
    }
    for (int i = 0; i < n; i++)
    {
        int idx = n * ar[i];
        B[idx].value[++B[idx].ptr] = ar[i];
    }

    for (int i = 0; i < n; i++)
    {
        insertionSort<float>(B[i].value, B[i].ptr + 1);
        // cout << "  Bucket " << i;
        // print(B[i].value, B[i].ptr+1, " = ");
    }

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < B[i].ptr + 1; j++)
            ar[idx++] = B[i].value[j];
        delete[] B[i].value; // and free the memory
    }
}

int main()
{

    // Taking a random size ranging from 5 to 20
    int size = rand() % 15 + 5;
    float *arr = new float[size];

    // Initializing array with random values between 0 and 1 with 2 digits after decimal
    for (int j = 0; j < size; j++)
    {
        arr[j] = (float)(rand() % 100) / 100;
    }

    print(arr, size, "\nUnsorted Array = ");
    bucketSort(arr, size);
    print(arr, size, "\nSorted Array = ");
    cout << endl;

    return 0;
}
