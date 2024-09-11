// Date: 2024-09-05
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;

bool recursion(int i, int k, vector<int>& arr,vector<vector<int>>& dp){
    if (i < 0) {
        if (k == 0){
            return true;
        }
        else {
            return false;
        }   
    }
    if (dp[i][k] != -1){
        return dp[i][k] == 1;
    }

    if (k == 0){
        return true;
    }

    bool take = recursion(i-1, k - arr[i], arr, dp);
    bool leave = recursion(i-1, k, arr, dp);

    if (take || leave){
        dp[i][k] = 1;
    }
    else {
        dp[i][k] = 2;
    }

    return (take || leave);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    return recursion(n-1, k, arr, dp);// || recursion(n-1, k-arr[n-1], arr);
}

int main() {
    int n = 10, k = 19;
    vector<int> arr = {60, 15, 13, 10, 7, 29, 47, 48, 90, 70 };
    bool a = subsetSumToK(n, k, arr);
    return 0;
}