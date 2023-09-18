//
// Created by migav on 15/07/2023.
//

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, x, t, k, value[201], favour[201], dp[201][1101][25];
//
//int fav(int plate, int cost, int num) {
//    if(plate == 2*k || (cost + n*t)*11/10.0 > x || !num)
//        return 0;
//    int &ans = dp[plate][cost][num];
//    if(ans != -1) return ans;
//    if((cost + value[plate] + n*t)*11/10.0 > x) return ans = fav(plate + 1, cost, num);
//    return ans = max(fav(plate + 1, cost, num), favour[plate] + fav(plate + 1, cost + value[plate], num - 1));
//}
//
//int main() {
//    cout << fixed << setprecision(2);
//    int c = 1;
//    while(cin >> n >> x >> t >> k, n) {
//        memset(favour, 0, sizeof favour);
//        memset(dp, -1, sizeof dp);
//        n++;
//        x *= n;
//        for(int i = 1; i < 2*k; i += 2) {
//            cin >> value[i];
//            value[i-1] = value[i];
//            int f;
//            for(int j = 0; j < n; j++) {
//                cin >> f;
//                favour[i] += f;
//                favour[i-1] += f;
//            }
//        }
//        cout << fav(0, 0, 2*n)/(double)n << endl;
//    }
//}