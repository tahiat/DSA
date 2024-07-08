#include<iostream>
#include<vector>
using namespace std;



void merge(vector<int>&arr, int s, int m , int mm, int l){
    int n1 = m-s+1;
    int n2 = l-mm+1;
    vector<int> a1(n1);
    vector<int> a2(n2);
    vector<int> res(l-s+1);

    for (int i = 0; i< n1; i++){
        a1[i] = arr[s+i];
    }
    for(int i=0; i< n2;i++)
    {
        a2[i] = arr[mm+i];
    }
    int i = 0, j = 0, k = s;

    while (i<n1 && j <n2){
        if (a1[i] <= a2[j]){
            arr[k++] = a1[i++];
        }
        else{
            arr[k++] = a2[j++];
        }
    }
    while (i<n1){
        arr[k++] = a1[i++];
    }
    while (j<n2){
        arr[k++] = a2[j++];
    }
}

void ms(vector<int> &arr, int s, int l){
    if (s < l){
        int m = s + (l-s)/2;
        ms(arr, s, m);
        ms(arr, m+1, l);

        merge(arr, s, m , m+1, l);
    }
}

void mergesort(vector<int>&arr){
    ms(arr, 0, arr.size()-1);
}

void selectionSort(vector<int>& arr){
    int n = arr.size();
    int swap_index = -1;
    for(int i=0; i< n-1; i++){
        swap_index = -1;
        for (int j=i; j < n;j++){
            if (arr[j]<arr[i]){
                swap_index = j;
            }
        }
        if (swap_index != -1){
            int temp = arr[i];
            arr[i] = arr[swap_index];
            arr[swap_index] = temp;
        } 
    }
}

void insertionSort(vector<int>& arr){
    for (int i = 1; i< arr.size(); i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main (){
    vector<int> ss{-6,0,9,100};
    selectionSort(ss);

    printf("selection sort result of {-6,0,9,100} \n");
    for(int i = 0; i< ss.size(); i++){
        cout<< ss[i] << endl;
    }


    vector<int> insert{0,9,-1,0,8,7,9,1,-8};
    insertionSort(insert);
    printf("Insertion sort output\n");
    for(int i = 0; i< insert.size(); i++){
        cout<< insert[i] << endl;
    }


    vector<int> mer{0,9,-1,0,8,7,9,1,-8};
    mergesort(mer);
    printf("Merge sort output\n");
    for(int i = 0; i< mer.size(); i++){
        cout<< mer[i] << endl;
    }
}