//
// Created by migav on 18/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

int v = 10, n = 2, c[] = {1,5}, dp[20][10000];

Top - Down

int ways(int type, int val) {
    if(!val) return 1;
    if(val < 0 || type == n) return 0;
    int &ans = dp[type][val];
    if(ans != -1) return ans;
    else return ans = ways(type + 1, val) + ways(type, val - c[type]);
}

int main() {
    memset(dp, -1, sizeof dp);
    cout << ways(0, v);
}

Bottom - Up

int main() {
    for(int type = 0; type < n; type++)
        dp[type][0] = 1; //Base cases
    //Tabulation
    for(int type = 0; type < n; type++)
        for(int val = c[type]; val <= v; val++){
            if(type) dp[type][val] += dp[type-1][val];
            dp[type][val] += dp[type][val - c[type]];
        }
    cout << dp[n-1][v];
}