//
// Created by migav on 3/10/2022.
//

#include <cstdio>
#include <algorithm>

using namespace std;

//int main() {
//    int n, v, maxP;
//    while(scanf("%d", &n) != EOF) {
//        int corners[33000] = {0};
//        for(size_t i = 0; i < (1 << n); i++) {
//            scanf("%d", &v);
//            for(size_t j = 0; j < n; j++)
//                corners[i ^ (1 << j)] += v;
//        }
//        maxP = 0;
//        for(size_t i = 0; i < (1 << n); i++) {
//            for(size_t j = 0; j < n; j++)
//                maxP = max(maxP, corners[i] + corners[i ^ (1 << j)]);
//        }
//        printf("%d\n", maxP);
//    }
//}