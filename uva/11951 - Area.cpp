//
// Created by migav on 9/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

//int main() {
//    int t, n, m, k, a[102][102];
//    cin >> t;
//    for(int c = 1; c <= t; c++) {
//        cin >> n >> m >> k;
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < m; j++) {
//                cin >> a[i][j];
//                if(i > 0) a[i][j] += a[i-1][j];
//            }
//        int maxArea = 0, minCost = INT_MAX, tmpCost, tmpArea;
//        for(int l = 0; l < n; l++)
//            for(int r = l; r < n; r++) {
//                int i = 0; tmpCost = 0;
//                for(int j = 0; j < m; j++) {
//                    tmpCost += a[r][j];
//                    if(l) tmpCost -= a[l-1][j];
//                    while(i <= j && tmpCost > k) {
//                        tmpCost -= a[r][i];
//                        if(l) tmpCost += a[l-1][i];
//                        i++;
//                    }
//                    tmpArea = (r-l+1)*(j-i+1);
//                    if(tmpCost <= k) {
//                        if(tmpArea > maxArea || (maxArea == tmpArea && tmpCost < minCost)) {
//                            maxArea = tmpArea;
//                            minCost = tmpCost;
//                        }
//                    }
//                }
//            }
//        cout << "Case #" << c << ": " << maxArea << " " << minCost << endl;
//    }
//}