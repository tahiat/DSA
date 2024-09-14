// Date: 2024-09-14
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
private:
    void powerSet (int idx, int n, vector<int> cur, vector<int>& num,  vector<vector<int>> &res){
        if (idx == n){
            res.push_back(cur);
            return;
        }

        powerSet(idx+1, n, cur, num, res);

        cur.push_back(num[idx]);
        powerSet(idx+1, n, cur, num, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int row = pow(2, n);
        vector<vector<int>> res;

        vector<int> cur;
        powerSet(0, n, cur, nums, res);

        return res;
    }
};


int main() {
    Solution sln;
    vector<int> v = {1,2,3};
    sln.subsets(v);
    return 0;
}