//
// Created by migav on 13/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

//long long dp[202][21][202];
//int n, m, d, nums[202];
//
//long long sum(int i, int s, int k) {
//    if(i == n || k == 0) {
//        if(s || k > 0) return 0;
//        else return 1;
//    }
//    long long &ans = dp[i][s][k];
//    if (ans != -1) return ans;
//    long long aux = (s + nums[i]) % d;
//    if(aux < 0) aux += d;
//    return ans = sum(i+1, (int)aux, k-1) + sum(i+1, s, k);
//}

//int main() {
//    int Q, s = 1;
//    while(cin >> n >> Q, n||Q) {
//        for(int i = 0; i < n; i++)
//            cin >> nums[i];
//        cout << "SET " << s++ << ":" << endl;
//        for(int q = 1; q <= Q; q++) {
//            cin >> d >> m;
//            memset(dp, -1, sizeof dp);
//            cout << "QUERY " << q << ": " << sum(0, 0, m) << endl;
//        }
//    }
//}
