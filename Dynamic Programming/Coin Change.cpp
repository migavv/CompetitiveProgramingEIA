//
// Created by migav on 18/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

const int inf = 10e5;

int n = 4, c[] = {1,3,4,5}, dp[10000];

//Top - Down

int change(int val) {
    if(!val) return 0; //0 coins are needed to represent V = 0
    if(val < 0) return inf; //Exact value cannot be reached
    int &ans = dp[val]; //Memoization
    if(ans != -1) return ans;
    ans = inf;
    for(int i = 0; i < n; i++) //For every coin value:
        ans = min(ans, change(val - c[i]) + 1);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    int v = 10;
    cout << change(v);
}

//Bottom Up:

//int main() {
//    int v = 7;
//    fill(dp, dp+v+1, inf);
//    dp[0] = 0; //0 coins needed to represent V = 0
//    for(int val = 1; val <= v; val++) {
//        for(int coin = 0; coin < n; coin++) {
//            if(val - c[coin] >= 0)
//                dp[val] = min(dp[val], dp[val - c[coin]] + 1);
//        }
//    }
//    cout << dp[v];
//}