#include <iostream>
using namespace std;

// Partition function to partition the array around a pivot element
int Partition(int A[], int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= A[r]) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

// Randomized partition function to select a random pivot element
int RandomizedPartition(int A[], int p, int r) {
    int i = p + rand() % (r - p + 1);
    swap(A[r], A[i]);
    return Partition(A, p, r);
}

// Randomized Select function to select ith order statistic from an unsorted array
int RandomizedSelect(int A[], int p, int r, int i) {
    if (p == r) {
        return A[p];
    }
    int q = RandomizedPartition(A, p, r);
    int k = q - p + 1;
    if (i == k) {
        return A[q];
    } else if (i < k) {
        return RandomizedSelect(A, p, q - 1, i);
    } else {
        return RandomizedSelect(A, q + 1, r, i - k);
    }
}

int main() {
    // cout<<endl;cout<<endl;cout<<endl;
    int A[] = { 3, 5, 2, 7, 6, 1, 4 };
    int n = sizeof(A) / sizeof(A[0]);
    int i = 3;
    int order_statistic = RandomizedSelect(A, 0, n - 1, i);
    cout << "The " << i << "th order statistic is: " << order_statistic << endl;
    // cout<<endl;cout<<endl;cout<<endl;
    return 0;
}
