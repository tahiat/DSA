#include<iostream>
using namespace std;


void max_heapify(int arr[], int i, int n){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left< n && arr[left] > arr[i]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, n);
    }
}

void build_maxheap(int arr[], int n){
    for (int i = (n-1)/2 ; i>=0; i--){
        max_heapify(arr, i, n);
    }
}

void heapsort(int arr[], int n){
    for (int i = n-1; i >=1; i--){
        swap(arr[0], arr[i]);
        n--;
        max_heapify(arr, 0, n);
    }
}

int  main () {
    int arr[7] = {4,7,8,3,2,6,5};
    build_maxheap(arr, 7);

    for (int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
    heapsort(arr,7);
    cout << endl;
    for (int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
}