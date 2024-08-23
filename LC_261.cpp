// Date: 2024-07-28
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
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for (auto item: edges){
            adj[item[0]].push_back(item[1]);
            adj[item[1]].push_back(item[0]);
        }

        set<int> stckNode;

        bool isValid = dfs(0, adj, stckNode, -1);

        return (isValid && stckNode.size() == n)?  true :  false;
    }
    // visited for checking node in stack, covered to track all note that has been visited 
    bool dfs(int node, vector<vector<int>>& adj, set<int>& stk, int prev){
        if (stk.find(node) != stk.end()){
            return false;  //cycle detected;
        }

        stk.insert(node);
        
        for(auto neighbor: adj[node]){
            if (neighbor != prev){
                if (!dfs(neighbor, adj, stk, node)){
                    return false;
                }
            }
        }
        return true;
    }

};



int main() {
    vector<vector<int>> list;

    list.push_back({0,1});
    list.push_back({0,2});
    list.push_back({0,3});
    list.push_back({1,4});

    Solution sln;
    auto res = sln.validTree(5, list);
}