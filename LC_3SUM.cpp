#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int l = i + 1, r = nums.size() - 1;
            while (l < r){
                int three_sum = nums[i] + nums[l] + nums[r];
                if (three_sum < 0){
                    l += 1;
                }
                else if (three_sum > 0){
                    r -= 1;
                }
                else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    while (l < r && nums[l] == nums[l-1]){
                        l += 1;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v {-1,0,1,2,-1,-4};
    auto res = s.threeSum(v);
    return 0;
}