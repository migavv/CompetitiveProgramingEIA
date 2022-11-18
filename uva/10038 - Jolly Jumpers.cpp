//
// Created by migav on 24/09/2022.
//

#include<cstdio>
#include<cmath>

//int main() {
//    int n, prev, curr, val;
//    bool jolly;
//    while(scanf("%d", &n) != EOF) {
//        bool b[3000] = {false};
//        jolly = true;
//        scanf("%d", &prev);
//        int i = n - 1;
//        while(i--) {
//            scanf("%d", &curr);
//            val = abs(curr - prev);
//            if(val > 0 && val < n)
//                b[val] = true;
//            prev = curr;
//        }
//        for (int j = 1; j < n; ++j) {
//            if(!b[j]) {
//                jolly = false;
//                break;
//            }
//        }
//        if(!jolly) printf("Not jolly\n");
//        else printf("Jolly\n");
//    }
//}