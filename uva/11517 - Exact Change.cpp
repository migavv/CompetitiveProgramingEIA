//
// Created by migav on 10/07/2023.
//

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int t, v, n, dp[20001], coins[101];
//    cin >> t;
//    while (t--) {
//        cin >> v;
//        fill(dp, dp+20001, INT_MAX);
//        dp[0] = 0;
//        cin >> n;
//        for(int i = 0; i < n; i++)
//            cin >> coins[i];
//        for(int i = 0; i < n; i++) {
//            for(int j = 20000; j >= 0; j--) {
//                if(dp[j] != INT_MAX && j + coins[i] <= 20000)
//                    dp[j+coins[i]] = min(dp[j+coins[i]], dp[j] + 1);
//            }
//        }
//        int res = v;
//        while(dp[res] == INT_MAX) res++;
//        cout << res << " " << dp[res] << endl;
//    }
//}
