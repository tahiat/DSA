#include<iostream>
using namespace std;


int get_smallest_subarry(int arr[], int n, int x){
    int min_len = n+1;

    int start =0, end = 0, current_sum =0;


    while (end < n){

        while (current_sum <= x && end < n){
            current_sum += arr[end++];
        }

        while (current_sum > x && start < n){
            min_len = min(min_len, end-start+1);  /// understand why using +1 is a  mistake here...

            current_sum -= arr[start++];
        }
    }

    return min_len;
}

int main (){
int arr1[] = { 1, 4, 45, 6, 10, 19 };
    int x = 51;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int res1 = get_smallest_subarry(arr1, n1, x);
    (res1 == n1 + 1) ? cout << "Not possible\n"
                     : cout << res1 << endl;
}