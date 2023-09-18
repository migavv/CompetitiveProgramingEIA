//
// Created by migav on 22/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int moves[8][2] = {
            {1,2}, {2,1},
            {-1,2},{2,-1},
            {1,-2}, {-2,1},
            {-1,-2},{-2,-1}
    };
    double dp[105][30][30];
    double play(int n, int k, double p, int r, int c) {
        if(r < 0 || r >= n || c < 0 || c >= n)
            return 0;
        if(!k)
            return p;
        double &ans = dp[k][r][c];
        if(ans != -1) return ans;
        ans = 0;
        for(auto move : moves)
            ans += play(n, k-1, p/8, r+move[0], c+move[1]);
        return ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i = 1; i <= k; i++)
            for(int a = 0; a < n; a++)
                for(int b = 0; b < n; b++)
                    dp[i][a][b] = -1;
        return play(n, k,1,row,column);
    }
};

int main() {
    Solution sol;
    cout << sol.knightProbability(3, 3, 0,0);
}