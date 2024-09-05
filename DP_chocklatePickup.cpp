// Date: 2024-09-05
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;


int recursion1(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp){
    if (j1 < 0 || j2 < 0 || j1>=c || j2>=c){
        return -1e8;
    }
    if (i == r - 1){
        if (j1 == j2){
            return grid[i][j1];
        }
        else {
            return grid[i][j1] + grid[i][j2];
        }
    }

    if (dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    int result = -1e8;
    for (int m = -1; m <=1; m++){
        for (int n = -1; n <=1; n++){
            int temp = recursion1(i+1, j1+m, j2+n, r, c, grid, dp);
            if (j1 == j2){
                temp += grid[i][j1];
            }
            else {
                temp += (grid[i][j1] + grid[i][j2]);
            }
            result = max(result, temp);
        }
    }
    return dp[i][j1][j2] = result;
}   

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // vector<vector<vector<int>>> dp (r, vector<vector<int>>(c, vector<int>(c, -1)));
    // return recursion1(0, 0, c-1, r, c, grid, dp);

    vector<vector<vector<int>>> dp (r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int i = 0; i < c; i++){
        for (int j = 0; j < c; j++){
            if (i == j) dp[r-1][i][j] = grid[r-1][i];
            else  dp[r-1][i][j] = grid[r-1][i] + grid[r-1][j];
        }
    }

    for (int i = r-2; i >= 0; i--){
        for (int j = 0; j < c; j++){
            for (int k = 0; k < c; k++){

                int maxi = -1e8;
                for (int m = -1; m <=1; m++){
                    for (int n = -1; n <=1; n++){
                        int temp = -1e8;
                        if (j+m >=0 && j + m <c && k+n >=0 && k+n <c) {
                            temp = dp[i+1][j+m][k+n];
                        }
                    
                        if (j == k){
                            temp += grid[i][j];
                        }
                        else {
                            temp += (grid[i][j] + grid[i][k]);
                        }
                        maxi = max (maxi, temp);
                    }
                }    

                 dp[i][j][k] = max(dp[i][j][k], maxi);

            }
        }
    }

    return dp[0][0][c-1];

}


int main() {
    return 0;
}