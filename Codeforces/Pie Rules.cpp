//
// Created by migav on 1/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int n, pie[100003], dp[100003][2];

int solve(int i, int p) {
    if(i == n-1) {
        if(p) return pie[i];
        else return 0;
    }
    int &ans = dp[i][p];
    if(ans != -1) return ans;
    if(p) return ans = max(pie[i] + solve(i+1,0), solve(i+1,1));
    else return ans = min(pie[i] + solve(i+1, 0), solve(i+1, 1));
}

int main() {
    int ttl = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pie[i];
        ttl += pie[i];
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(0, 1);
    cout << ttl - ans << " " << ans;
}