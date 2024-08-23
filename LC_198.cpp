// Date: 2024-08-01
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        /*
        int rob1 = 0, rob2 = 0;
        // [rob1, rob2, i, i+1, ... ...]
        for (int i = 0; i< n; i++){
            int temp = max(nums[i] + rob1, rob2); // rob the current house, added with the max value that can be robbed from two house before it.
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
        */
        // second solution: bottom up approach, dp with tabular data
        // we can remove the memory array and use 2 variable like above approach.
        
        vector<int> memory(n+1, 0);
        memory[n] = 0;
        memory[n-1] = nums[n-1];

        for (int i = n-2; i>=0; i--){
            memory[i] = max(nums[i] + memory[i+2], memory[i+1]);
        }
        return memory[0];
    }
};


int main() {
    Solution sln;

    vector<int> input({1,1,3,3});
    int res = sln.rob(input);
    cout << "Expected 4 , output is " << res << endl;
    input = {2,9,8,3,6};
    //[2,9,8,3,6]
    cout << "expected 16, output is " << sln.rob(input) << endl;

    return 0;
}