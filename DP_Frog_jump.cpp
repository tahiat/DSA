#include<iostream>
#include<vector>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, -1);
        int res = INT_MAX;
        dfshelper(height, 0, 0, dp,res);
        return res;
    }
    int dfshelper(vector<int>& height, int sum, int current, vector<int> dp, int& result){
        if (current == height.size()-1){
            return sum;
        }
        
        int r1, r2;
        r1 = dfshelper(height, sum+abs(height[current]-height[current+1]), current+1, dp, result);
        if (current+2 < height.size())
            r2 = dfshelper(height, sum+abs(height[current]-height[current+2]), current+2, dp, result);
        
        result = min(result, min(r1,r2));
        return min (r1,r2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    vector<int> v = {10,20,30,10};
    
    Solution obj;
    cout << "result " << obj.minimumEnergy(v, 4);
    
    return 0;
}