#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int i, j, k;
    int B[100];
    i = start;
    j = mid + 1;
    k = start;
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            B[k] = arr[i];
            i++,k++;
        }else{
            B[k] = arr[j];
            j++,k++;
        }
    }
    while(i <= mid){
        B[k] = arr[i];
        i++,k++;
    }
    while(j <= end){
        B[k] = arr[j];
        j++,k++;
    }
    for(int i = start; i <= end; i++){
        arr[i] = B[i];
    }
}


void mergeSort(int arr[], int start, int end){
    if(start < end){
    int mid = (start + end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
    }
}


int main(){
    int arr[] = {64, 25, 12, 22, 11};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    printf("\n");

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;

}