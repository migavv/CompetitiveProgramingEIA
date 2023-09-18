//
// Created by migav on 7/08/2023.
//

#include<bits/stdc++.h>

using namespace std;

int a, b, c, dp[5000];

int solve(int n) {
    if(n < 0) return -1e7;
    if(!n) return 0;
    int &ans = dp[n];
    if(ans != 0) return ans;
    return ans = max(solve(n-a), max(solve(n-b), solve(n-c))) + 1;
}

int main() {
    int n;
    cin >> n >> a >> b >> c;
    cout << solve(n);
}