// Date: 2024-08-23
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;
/*
Quick select is an algorithm to find the k-th smallest(modify to find largest) element in an array
In average case the algorithm should work in O(n) complexity
In worst case it words in O(n^2)
*/
int quickSelect(vector<int>& lst, int k){
    int pivot = lst[rand() % lst.size()];

    vector<int> left;  // contains elements that are smaller than pivot
    vector<int> mid;   // equal to pivot
    vector<int> right; // greater than pivot

    for (int elem: lst){
        if (elem < pivot){
            left.push_back(elem);
        }
        else if (elem > pivot){
            right.push_back(elem);
        }
        else {
            mid.push_back(elem);
        }
    }

    if (k <= left.size()){
        return quickSelect(left, k);
    }

    if (k > left.size() + mid.size()){
        return quickSelect(right, k - left.size() - mid.size());
    }

    return pivot;
}

int GTRP(vector<int>& arr, int left, int right){
    int rIdx = left + rand()%(right-left+1);
    std::swap(arr[right], arr[rIdx]);

    int splitter = arr[right];

    int i = left, j = right;
    while (i <= j){
        while (i <= j && arr[i] <= splitter) i++;
        while (j >= i && arr[j] >= splitter) j--;
        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[i], arr[right]);
    return i;
}

int RQSelect(vector<int>& arr, int k, int l, int r){
    if (l==r) return arr[l];
    int m = GTRP(arr, l, r);
    int t = m-l+1;
    if (k == t){
        return arr[k];
    }
    else if (k < t){
        return RQSelect(arr, k, l, m-1);
    }
    else {
        return RQSelect(arr, k-t, m+1, r);
    }
}

int main() {
    vector<int> list = {3,2,3,1,2,4,5,5,6,1};
    cout << quickSelect(list, 5) << endl;
    cout << "rqselect  " << RQSelect(list, 5, 0, list.size() - 1);
    return 0;
}