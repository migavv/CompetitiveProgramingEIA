//
// Created by migav on 6/07/2023.
//
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int n, g[100][100] = {0}, aux[100][100] = {0};
//    cin >> n;
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < n; j++){
//            cin >> g[i][j];
//            aux[i][j] = g[i][j];
//            if(i) aux[i][j] += aux[i][j-1];
//        }
//    int res = INT_MIN, curr;
//    for(int l = 0; l < n; l++) {
//        for(int r = l; r < n; r++) {
//            curr = 0;
//            for(int i = 0; i < n; i++) {
//                curr += aux[i][r];
//                if(l) curr -= aux[i][l-1];
//                res = max(res, curr);
//                if(curr < 0) curr = 0;
//            }
//        }
//    }
//    cout << res << endl;
//}