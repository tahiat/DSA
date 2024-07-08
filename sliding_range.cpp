#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main () {
    deque<pair<int,int>> DQ; // {value, index}
    vector<int> res = {10, 50, 15, 12, 4};

    vector<int> result;
    int m = 3;
    for (int i = 0; i< res.size(); i++){

        while(!DQ.empty() && DQ.front().first >= res[i]){
            DQ.pop_front();
        }

        DQ.push_front(make_pair(res[i], i));

        while(!DQ.empty() && DQ.back().second <= (i-m)){
            DQ.pop_back();
        }

        if (i >= m-1){
            result.push_back(DQ.back().first);
        }
    }

    for(int i = 0; i< result.size();i++){
        cout << result[i] << ", ";
    }

}