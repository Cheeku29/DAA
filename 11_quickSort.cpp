#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    do {
        while (i <= end && arr[i] < pivot) {
            i++;
        }
        while (j >= start && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    } while (i < j);

    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
