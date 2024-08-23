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

class UnionFind {
private:
    vector<int> rep;
    vector<int> com_size;
    int CC;
public:
    UnionFind(int n) {
        for (int i = 0; i<n;i++){
            rep.push_back(i);
            com_size.push_back(1);
        }
        CC = n;
    }

    int makeUnion(int x, int y){
        int px = find(x);
        int py = find(y);

        if (px == py){
            return 0;
        }

        if (com_size[px] < com_size[py]){
            rep[px] = py;
            com_size[py] += com_size[px];
        }
        else {
            rep[py] = px;
            com_size[px] += com_size[py];
        }
        CC--;
        return 1;
    }
    int find(int x){
        if (rep[x] == x){
            return x;
        }
        rep[x] = find(rep[x]);
        return rep[x];
    }
    bool isConnected(){
        return CC==1;
    }
    int getCC(){
        return CC;
    }

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for (auto item : edges){
            uf.makeUnion(item[0], item[1]);
        }

        return uf.getCC();
    }
};

int main() {
    return 0;
}