// Date: 2024-09-01
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;


#include<bits/stdc++.h>
using namespace std;
// with memoization
int maxSum(int cur, int prevActivity, vector<vector<int>>& points, vector<vector<int>>& dp){
    if (cur < 0){
        //if 
        return 0;
    }
    if (dp[cur][prevActivity] != -1){
        return dp[cur][prevActivity];
    }
    int max_val = 0;
    //int sum;
    
    for (int i = 0; i < 3; i++){
        if (i != prevActivity){
            int point = points[cur][i] + maxSum(cur-1, i, points, dp);
            max_val = max(point, max_val);
        }
    }
    dp[cur][prevActivity] = max_val;
    return max_val;
}

// tabulation;
int maxSum_tabulation(int n, vector<vector<int>>& points){
    vector<vector<int>> dp (n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1]  = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++){
        for (int last = 0; last < 4; last++){
            for (int i = 0; i < 3; i++){
                if (i != last){
                    dp[day][last] = max(dp[day][last], points[day][i] + dp[day-1][i]);
                }
            }
        }
    }
    return dp[n-1][3];
}

int maxSum_spaceoptimize(int n, vector<vector<int>>& points){
    vector<int> dp (4, -1);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1]  = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++){
        vector<int> dummy (4, -1);
        for (int last = 0; last < 4; last++){
            for (int i = 0; i < 3; i++){
                if (i != last){
                    dummy[last] = max(dummy[last], points[day][i] + dp[i]);
                }
            }
        }
        dp = dummy;
    }
    return dp[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (4, -1));
     int result = INT_MIN;
    //return maxSum(n-1, 3, points, dp);

    //tabulation
    //return maxSum_tabulation(n, points);

    //space opt
    return maxSum_spaceoptimize(n, points);

}


int main() {
    int n = 3;
    vector<vector<int>> dp = {{10, 40, 70}, 
                                {20, 50, 80},
                                {30, 60, 90}};
    int result = INT_MIN;
    int val = maxSum(n-1, 3, dp);    
    return 0;
}