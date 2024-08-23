// Date: 2024-07-27
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
private:
    bool dfs(int course, vector<vector<int>>& adList, unordered_set<int> visit){
        if (visit.find(course) != visit.end()){ //loop
            return false;
        }
        if (adList[course].size()==0){
            return true;
        }
        visit.insert(course);
        for (int pre: adList[course]){
            if (!dfs(pre, adList, visit)){
                return false;
            }
        }
        visit.erase(course);
        adList[course].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList (numCourses);
        unordered_set<int> visitSet;    

        for(int i = 0; i < prerequisites.size(); i++){
            adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i< numCourses; i++){
            if (!dfs(i, adjacencyList, visitSet)){
                return false;
            }
        }

        return true;
    }
};


int main() {
    
}