//
// Created by migav on 21/07/2023.
//

#include <bits/stdc++.h>

//using namespace std;
//
//const int inf = 1e7;
//
//int n, dist[10][10], dp[10][2050], nxt[10][2050];
//
//int tsp(int i, int v) {
//    if(v == (1 << n) - 1)
//        return 0;
//    int &ans = dp[i][v];
//    if(ans != -1) return ans;
//    ans = inf;
//    for(int j = 0; j < n; j++) {
//        if(!(v & 1 << j)) {
//            int curr = dist[i][j] + tsp(j, v | 1 << j);
//            if(curr < ans) {
//                ans = curr;
//                nxt[i][v] = j;
//            }
//        }
//    }
//    return ans;
//}
//
//int main() {
//    cout << fixed << setprecision(2);
//    int x, y, net = 1, distX, distY;
//    pair<int, int> loc[10];
//    while(cin >> n, n) {
//        n++;
//        for(int i = 1; i < n; i++) {
//            cin >> x >> y;
//            loc[i].first = x;
//            loc[i].second = y;
//        }
//        for(int i = 1; i < n; i++) {
//            for(int j = i; j < n; j++) {
//                distX = abs(loc[i].first - loc[j].first);
//                distY = abs(loc[i].second - loc[j].second);
//                dist[i][j] = dist[j][i] = (int)round(sqrt(distX*distX + distY*distY)*10000.0);
//            }
//        }
//        memset(dp, -1, sizeof dp);
//        int res = tsp(0,1);
//        cout << "**********************************************************\n";
//        cout << "Network #" << net++<<endl;
//        int curr = nxt[0][1];
//        int state = 1 | 1<<curr;
//        int next;
//        while(state != (1 << n) -1) {
//            next = nxt[curr][state];
//            cout << "Cable requirement to connect (" << loc[curr].first << "," << loc[curr].second
//                << ") to (" << loc[next].first << "," << loc[next].second << ") is "
//                << dist[curr][next]/10000.0 + 16 << " feet." << endl;
//            curr = next;
//            state |= 1 << next;
//        }
//        cout << "Number of feet of cable required is " << res/10000.0 + 16*(n-2) << ".\n";
//    }
//}