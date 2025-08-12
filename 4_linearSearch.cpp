#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element)
            return i;
    }
    return -1;
}

int main(){
    int arr[] = {1,4,5,33,79,353,400,532,970};
    int size = sizeof(arr) / sizeof(int);  // Calculate size of array
    int element;
    cout << "Enter element: ";
    cin >> element;
    int searchIndex = linearSearch(arr, size, element);

    if(searchIndex == -1){
        cout << "Element not found.\n";
    }else{
        cout << "Element found at index " << searchIndex << endl;
    }
    return 0;
}