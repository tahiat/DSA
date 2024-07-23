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
    int search(vector<int>& nums, int target) {  // Find target in rotated sorted array.
        int n = nums.size() - 1;
        int left = 0, right = n;

        // first find the minimum value and its index
        while (left < right){
            int mid = left + (right-left)/2;

            if (nums[mid] < nums[n]){
                right = mid;
            }
            else {
                left = mid+1;
            }

        }
    }
    int search2(vector<int>& nums, int target) {  // Find target in rotated sorted array.
        int n = nums.size() - 1;
        int left = 0, right = n;

        // first find the minimum value and its index
        while (left < right){
            int mid = left + (right-left)/2;

            if (nums[mid] < nums[n]){
                right = mid;
            }
            else {
                left = mid+1;
            }

        }
        if (target >= nums[left] && target <= nums[n]){
            right = n;
        }
        else {
            left = 0;
            right = left - 1;
        }

        while (left < right){
            int mid = left + (right-left)/2;

            if (nums[mid] >= target){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }

        if (nums[left] == target){
            return left;
        }
        else {
            return -1;
        }
    }
};

int main () {
    Solution sl;
    vector<int> v {4};
    int res = sl.search(v, 4);

    return 0;
}