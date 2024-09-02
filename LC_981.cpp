// Date: 2024-08-31
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = map.find(key);
        if (it != map.end()){
            vector<pair<string,int>> list = it->second;
            int n = list.size() ;
            if (timestamp < list[0].second){
                return "";
            }
            if (timestamp > list[n - 1].second || n == 1){
                return list[n-1].first;
            }

            int left = 0, right = n;
            while (left < right){
                int mid = left + (right-left)/2;
                if (list[mid].second > timestamp){
                    right =  mid;
                }
                else {
                    left = mid + 1;
                }
            }
            return list[left-1].first;
        }
        else {
            return "";
        }
    }
};

int main() {
    TimeMap mp;
    mp.set("alice", "happy", 1);
    cout << " " << mp.get("alice", 1) << endl;
    cout << mp.get("alice", 2) << endl;
    mp.set("alice", "sad", 3);
    cout << mp.get("alice", 3) << endl;
    return 0;
}