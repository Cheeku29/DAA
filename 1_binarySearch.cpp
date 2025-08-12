#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int element){
    int start, mid, end;
    start = 0;
    end = size - 1;
    while(start <= end){
        mid = (start + end)/2;
        if(element == arr[mid]){
            return mid;
        }
        if(element < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,4,5,33,79,353,400,532,970};
    int size = sizeof(arr) / sizeof(int);  // Calculate size of array
    int element; // Element to search for
    cout << "Enter element: ";
    cin >> element;
    int searchIndex = binarySearch(arr, size, element);

    if(searchIndex == -1){
        cout << "Element not found.\n";
    }else{
        cout << "Element found at index " << searchIndex << endl;
    }
    return 0;
}