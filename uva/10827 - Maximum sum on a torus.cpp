//
// Created by migav on 6/07/2023.
//

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int t, n, g[400][400];
//    cin >> t;
//    while(t--) {
//        cin >> n;
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < n; j++){
//                cin >> g[i][j];
//                g[i][j+n] = g[i+n][j] = g[i+n][j+n] = g[i][j];
//            }
//        for(int i = 0; i < 2*n; i++)
//            for(int j = 0; j < 2*n; j++) {
//                if(i > 0) g[i][j] += g[i-1][j];
//                if(j > 0) g[i][j] += g[i][j-1];
//                if(i > 0 && j > 0) g[i][j] -= g[i-1][j-1];
//            }
//        int nax = INT_MIN, curr;
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < n; j++)
//                for(int k = i; k < i + n; k++)
//                    for(int l = j; l < j + n; l++) {
//                        curr = g[k][l];
//                        if(i) curr -= g[i-1][l];
//                        if(j) curr -= g[k][j-1];
//                        if(i && j) curr += g[i-1][j-1];
//                        nax = max(nax, curr);
//                    }
//        cout << nax << endl;
//    }
//}