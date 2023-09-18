//
// Created by migav on 12/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

//const int h = 9, inf = 2e5;
//
//int d, sky[11][1002], dp[11][1002];

//int fuel(int y, int x) {
//    if(x == d) {
//        if(y) return inf;
//        else return 0;
//    }
//    if(y < 0 || y > h) return inf;
//    int &ans = dp[y][x];
//    if(ans != -1) return ans;
//    return ans = min(60 + fuel(y+1, x+1), min(30 + fuel(y, x+1), 20 + fuel(y-1, x+1))) - sky[y][x];
//}
//
//int main() {
//    int t;
//    cin >> t;
//    while(t--) {
//        memset(dp, -1, sizeof dp);
//        cin >> d;
//        d /= 100;
//        for(int i = h; i >= 0; i--)
//            for(int j = 0; j < d; j++)
//                cin >> sky[i][j];
//        cout << fuel(0, 0) << "\n\n";
//    }
//}