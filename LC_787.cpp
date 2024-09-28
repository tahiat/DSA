// Date: 2024-09-26
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adList;

        for (int i = 0; i < flights.size(); i++){
            adList[flights[i][0]].push_back({flights[i][2], flights[i][1]});
        }
        
        bool hasConnection = false;
        for (auto edge: adList[src]){
            if (edge.second == dst){
                hasConnection = true;
            }
        }
        if (k == 0 && !hasConnection) return -1;

        // so i will create a recursive back track function (dfs) that will take atmost 
        // if dst is rechabe using k intermediate node -- return distance
        // if dst not rechable using k intermediate node -- return max int;
        vector<int> dp(n+1, -1);
        int result = dfs(src, dst, k, dp, adList);

        return result >= 1e8 ? -1 : result;
    }

    int dfs(int curNode, int dst, int k, vector<int>& dp, unordered_map<int, vector<pair<int,int>>>& adList){
        if (curNode == dst){
            return 0;
        }
        if (k < 0){
            return 1e8;
        }
        if (dp[curNode] != -1){
            return dp[curNode];
        }
        int cost = 1e8;;

        for (auto edge: adList[curNode]){
            int dis =  edge.first + dfs(edge.second, dst, k-1, dp, adList);
            cost = min(cost, dis);
        }
        

        return dp[curNode] = cost;
    }
};

int main() {
    Solution sln;
    int n = 5, src = 0, dst = 2, k = 2;

    vector<vector<int>> list = {{0,1,5}, {1,2,5}, {0,3,2}, {3,1,2}, {1,4,1}, {4,2,1}};
    int result = sln.findCheapestPrice(n, list, src, dst, k);
    cout << "result " << result << endl;
    return 0;
}