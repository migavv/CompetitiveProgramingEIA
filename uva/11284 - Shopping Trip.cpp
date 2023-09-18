//
// Created by migav on 19/07/2023.
//

#include <bits/stdc++.h>

#define INF 1e8;

using namespace std;

//int n, m, p, road[53][53], storeId[53], storeCost[53], dp[53][8192];
//
//int tsp(int i, int visited) {
//    if(visited == (1 << p) - 1)
//        return -road[storeId[i]][0];
//    int &ans = dp[i][visited];
//    if(ans != -1) return ans;
//    ans = -road[storeId[i]][0];
//    for(int j = 0; j < p; j++) {
//        if(!(visited & 1<<j)) {
//            ans = max(ans, storeCost[j] - road[storeId[i]][storeId[j]]
//            + tsp(j, visited | 1<<j));
//        }
//    }
//    return ans;
//}
//
//int main() {
//    cout << fixed << setprecision(2);
//    int t, s, e;
//    double cost, price;
//    cin >> t;
//    while(t--) {
//        memset(dp, -1, sizeof dp);
//        cin >> n >> m;
//        n++;
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < n; j++)
//                road[i][j] = INF;
//            road[i][i] = 0;
//        }
//        for(int i = 0; i < m; i++) {
//            cin >> s >> e >> cost;
//            road[s][e] = min(road[e][s], (int)round(cost*100.0));
//            road[e][s] = road[s][e];
//        }
//        //Floyd Warshall:
//        for(int k = 0; k < n; k++)
//            for(int i = 0; i < n; i++)
//                for(int j = 0; j < n; j++)
//                    road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
//        cin >> p; p++;
//        for(int i = 1; i < p; i++) {
//            cin >> storeId[i] >> price;
//            storeCost[i] = (int)round(price*100.0);
//        }
//        int saving = tsp(0, 0);
//        if(saving <= 0) cout << "Don't leave the house\n";
//        else
//            cout << "Daniel can save $" << saving / 100.0 << endl;
//    }
//}