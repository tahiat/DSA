// Date: 2024-08-22
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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int fn = firstList.size();
        int sn = secondList.size();

        vector<vector<int>> result;

        int ptr1 = 0, ptr2 = 0;

        while (ptr1 < fn && ptr2 < sn){
            if (!(firstList[ptr1][0] > secondList[ptr2][1] || firstList[ptr1][1] < secondList[ptr2][0])){ // overlapped
                int st = max(firstList[ptr1][0], secondList[ptr2][0]);
                int en = min(firstList[ptr1][1], secondList[ptr2][1]);
                result.push_back({st,en});
                if (en == firstList[ptr1][1]){
                    ptr1++;
                }
                else {
                    ptr2++;
                }
            }
            else if (firstList[ptr1][0] > secondList[ptr2][1]){
                ptr2++;
            }
            else {
                ptr1++;
            }
        }
        return result;
    }   
};


int main() {
    Solution sln;
    vector<vector<int>> f = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> s = {{1,5},{8,12},{15,24},{25,26}};

    auto result = sln.intervalIntersection(f,s);

}