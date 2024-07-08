#include<iostream>
using namespace std;



int getMaxSum(int arr[], int arr_size, int k){


    int max_sum = INT_MIN;

    for (int i = 0; i < arr_size - k + 1; i++){
        int current_sum = 0;
        for (int j = 0; j < k; j++){
            current_sum += arr[i + j];
        }

        max_sum = max(current_sum, max_sum);
    }

    return max_sum;
}

int getMaxSumSliding(int arr[], int arr_size, int k){
    if (arr_size<=k) {
        return -1; //invalid
    }

    int maxsum = 0;
    for (int i =0;i<k;i++){
        maxsum += arr[i];
    }
    int windowsum = maxsum;
    for (int i = k; i<arr_size;i++){
        windowsum += arr[i] - arr[i-k];
        maxsum = max(maxsum, windowsum);
    }
    return maxsum;
}

int main () {
    int arr[] = {4,5,6,-1,2,0,9};

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << getMaxSum(arr,arr_size, 2) << endl;

    //cout << getMaxSum({1,2,3,4,5,6,7}, 3);
}