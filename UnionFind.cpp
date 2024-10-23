#include<iostream>
#include<vector>
using namespace std;



class UnionFind {
    vector<int> representative;
    vector<int> componentSize;
    int connectedComponent;
    public:
        UnionFind(int n){
            connectedComponent = n;
            for(int i = 0; i<=n; i++){
                representative.push_back(i);
                componentSize.push_back(0);
            }
        }

        int findRepresentative(int x){
            if (representative[x] == x){
                return x;
            }
            representative[x] = findRepresentative(representative[x]);
            return representative[x];
        }

        int makeUnion(int x, int y){
            int px = findRepresentative(x);
            int py = findRepresentative(y);

            if (px == py){
                return 0;
            }

            if (componentSize[px] > componentSize[py]) {
                representative[py] = px;
                componentSize[px] += componentSize[py];
            }
            else {
                representative[px] = py;
                componentSize[py] = componentSize[px];
            }
            connectedComponent--;
            return 1;
        }
        bool isConnected(){
            return connectedComponent == 1;
        }

};

