// Date: 2024-08-09
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int,int> dp;
        dp[s.size()] = 1;

        int result = dfs(s, 0, dp);
        return result;
    }
    int dfs(string s, int index, unordered_map<int,int>& dp){
        if (dp.find(index) != dp.end()){
            return dp[index];
        }

        if (s[index] == '0'){
            return 0;
        }

        int res = dfs(s, index + 1, dp);

        if (index + 1 < s.size() && stoi(s.substr(index, 2)) <= 26){
            res += dfs(s, index+2, dp);
        }
        dp[index] = res;
        return res;
    }
};

int main() {
    Solution sln;

    //cout << sln.numDecodings("326") << endl;
    cout << sln.numDecodings("01") << endl;
    cout << sln.numDecodings("12") << endl;
    return 0;
}