//
// Created by migav on 19/06/2023.
//

#include <bits/stdc++.h>

using namespace std;

//int main() {
//    long long res, G[21][21][21], aux[21][21][21];
//    int t, a,b,c;
//    cin >> t;
//    while(t--) {
//        memset(aux, 0, sizeof aux);
//        cin >> a >> b >> c;
//        for(int i = 0; i < a; i++) {
//            for(int j = 0; j < b; j++) {
//                for(int k = 0; k < c; k++) {
//                    cin >> G[i][j][k];
//                    aux[i][j][k] = G[i][j][k];
//                    if(i > 0) aux[i][j][k] += aux[i-1][j][k];
//                }
//            }
//        }
//        res = INT_MIN;
//        for(int p = 0; p < a; p++){
//            for(int q = p; q < a; q++){
//
//                for(int i = 0; i < b; i++) {
//                    long long sum[21] = {0};
//                    for(int j = i; j < b; j++) {
//
//                        long long tmp = 0;
//                        for(int k = 0; k < c; k++) {
//                            sum[k] += aux[q][j][k];
//                            if(p) sum[k] -= aux[p-1][j][k];
//                            tmp += sum[k];
//                            res = max(res, tmp);
//                            if(tmp < 0) tmp = 0;
//                        }
//                    }
//                }
//            }
//        }
//        cout << res << endl;
//        if(t) cout << endl;
//    }
//}