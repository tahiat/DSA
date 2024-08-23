// Date: 2024-07-26
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<utility>
using namespace std;

class Solution {
public:
    
    void dfs(int r, int c, int ROWS, int COLS, set<pair<int,int>>& visit, int prevHeight, vector<vector<int>>& heights){
        if (r < 0 || c < 0 || r == ROWS || c == COLS || visit.find({r,c}) != visit.end()
        || heights[r][c] < prevHeight){
            return;
        }
        visit.insert({r,c});
        dfs(r-1, c, ROWS, COLS, visit, heights[r][c], heights);
        dfs(r+1, c, ROWS, COLS, visit, heights[r][c], heights);
        dfs(r, c-1, ROWS, COLS, visit, heights[r][c], heights);
        dfs(r, c+1, ROWS, COLS, visit, heights[r][c], heights);


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> heights) {
        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;
        vector<vector<int>> result;

        int ROWS = heights.size();
        int COLS = heights[0].size();

        //iterate over row
        for(int r = 0; r < ROWS; r++){
            dfs(r, 0, ROWS, COLS, pacific, heights[r][0], heights);
            dfs(r, COLS-1, ROWS, COLS, atlantic, heights[r][COLS-1], heights);
        }

        for(int c = 0; c < COLS; c++){
            dfs(0, c, ROWS, COLS, pacific, heights[0][c], heights);
            dfs(ROWS-1, c, ROWS, COLS, atlantic, heights[ROWS-1][c], heights);
        }
       
        for (const pair<int,int>& item: pacific){
            if (atlantic.find(item) != atlantic.end()){
                result.push_back({item.first, item.second});
            }
        }

        return result;
    }
};

int main() {

    Solution sln;
    vector<vector<int>> input = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

    auto result = sln.pacificAtlantic(input);

    return 0;
}