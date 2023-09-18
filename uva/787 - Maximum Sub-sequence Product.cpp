//
// Created by migav on 8/07/2023.
//

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int seq[105];
//    int d = -1, n;
//    while(cin >> d) {
//        n = 0;
//        while(d != -999999) {
//            seq[n++] = d;
//            cin >> d;
//        }
//        int currMin, currMax, nax;
//        currMin = currMax = nax = seq[0];
//        for(int i = 1; i < n; i++) {
//            int curr = seq[i];
//            if(!currMax)
//                currMin = currMax = seq[i];
//            else if(curr < 0) {
//                int tmp = currMax;
//                currMax = max(curr, currMin * curr);
//                currMin = min(curr, tmp * curr);
//            } else {
//                currMax = max(curr, currMax * curr);
//                currMin = min(curr, currMin * curr);
//            }
//            nax = max(nax, currMax);
//        }
//        cout << nax << endl;
//    }
//
//}