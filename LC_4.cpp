// Date: 2024-08-31
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if (m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total = m + n;
        int half = (m+n+1)/2;

        int left = 0, right = m;

        while (left <= right){
            int mid1 = left + (right-left)/2; //take mid elements from nums1
            int mid2 = half - mid1; // half is total in left portion, 

            int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;
            if (mid1-1 >= 0) left1 = nums1[mid1-1];
            if (mid2 - 1 >= 0) left2 = nums2[mid2-1];
            if (mid1 < m)  right1 = nums1[mid1];
            if (mid2 < n) right2 = nums2[mid2];

            if (left1 <= right2 && left2 <= right1){
                if (total%2 == 0){
                    return double(max(left1,left2) + min(right1, right2)) / 2.0;
                }
                else {
                    return max(left1, left2);
                }
            }
            else if (left1 > right2){
                right  = mid1 - 1;
            }
            else{
                left = mid1 + 1;
            }

            
        }
        return 0;
    }
};

int main() {
    Solution sln;
    vector<int> n1 = {1, 2};
    vector<int> n2 = {3};
    double r =sln.findMedianSortedArrays(n1, n2);

    n1 = {1,3};
    n2 = {2,4};
    r = sln.findMedianSortedArrays(n1,n2);

    return 0;
}