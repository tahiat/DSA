#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size() - 1;
        int left = 0, right = nums.size() -1;

        if (nums[left] < nums[right]){
            return nums[left];
        }

        while (left < right){
            int mid = left + (right-left)/2;

            if (nums[mid] < nums[n]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

int main () {
    Solution sl;
    vector<int> v {1,2,3,4,5,64};
    int res = sl.findMin(v);

    return 0;
}