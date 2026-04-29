#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    // TODO:
    // Create temporary arrays
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* arrLeft = new int[leftSize];
    int* arrRight = new int[rightSize];
    // Copy data

    for (int l = 0; l < leftSize; ++l) arrLeft[l] = arr[left + l];
    for (int r = 0; r < rightSize; ++r) arrRight[r] = arr[mid + 1 + r];
    // Merge sorted halves back into arr

    int leftIndex = 0, rightIndex = 0, og = left;
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (arrLeft[leftIndex] <= arrRight[rightIndex]) {
            arr[og] = arrLeft[leftIndex];
            ++leftIndex;
        } else {
            arr[og] = arrRight[rightIndex]; 
            ++rightIndex;
        }
        ++og;
    }

    while (leftIndex < leftSize) {
        arr[og] = arrLeft[leftIndex];
        ++leftIndex;
        ++og;        
    }

    while (rightIndex < rightSize) {
        arr[og] = arrRight[rightIndex];
        ++rightIndex;
        ++og;
    }

    delete[] arrLeft;
    delete[] arrRight;
    
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // TODO:
        // Find middle
        int mid = left + (right - left) / 2;
        // Recursively sort left half
        mergeSort(arr, left, mid);
        // Recursively sort right half
        mergeSort(arr, mid + 1, right);
        // Merge both halves
        merge(arr, left, mid, right);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};
    int n = 10;

    cout << "Before Sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    display(arr, n);

    return 0;
}
