#include<iostream>
using namespace std;



int binary_search(int arr[], int arr_size, int key){
   int l = 0, h = arr_size -1;

    while (l  <= h){
        int m = l + (h-l)/2;
        if (arr[m] == key) 
            return m;
        if (key < arr[m])
        {
            h = m-1;
        }    
        else{
            l = m + 1;
        }
    }
   
    return -1;
}


int main () {
    int arr[7] = {4,5,7,3,2,4,6};

    sort(arr, arr+7);

    int index = binary_search(arr, 7, 6);
    cout << index ;
}