// Date: 2024-09-11
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
    int findDuplicate(vector<int>& nums) {
        // int m = *max_element(nums.begin(), nums.end());

        // int pr= 1;
        // for (int num: nums){
        //     pr *= num;
        // }

        // for (int i = 1; i <=m ; i++){
        //     pr /= i;
        // }

        // if (pr > m){

        // }
        // return pr;

        int slow = 0, fast = 0;
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }

        int slow2 = 0;
        while (true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) return slow;
        }

    }
};


int main() {
    return 0;
}