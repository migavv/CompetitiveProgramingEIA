//
// Created by migav on 13/10/2022.
//

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct car {
    int entry;
    int exit;
};

//int main() {
//    int c, n, t, m, arr, clock;
//    bool isLeft;
//    scanf("%d", &c);
//    while(c--) {
//        clock = 0;
//        queue<car*> left, right, ferry;
//        car cars[10000];
//        scanf("%d %d %d", &n, &t, &m);
//        char side[10];
//        for (int i = 0; i < m; ++i) {
//            scanf("%d %s", &arr, side);
//            cars[i].entry = arr;
//            if(!strcmp(side, "left"))
//                left.push(&cars[i]);
//            else
//                right.push(&cars[i]);
//        }
//        isLeft = true;
//        while(!left.empty() || !right.empty() || !ferry.empty()) {
//            while(!ferry.empty()) {
//                ferry.front() -> exit = clock;
//                ferry.pop();
//            }
//            if(isLeft) {
//                while(!left.empty() && left.front() -> entry <= clock && ferry.size() < n) {
//                    ferry.push(left.front());
//                    left.pop();
//                }
//            } else {
//                while(!right.empty() && right.front() -> entry <= clock && ferry.size() < n) {
//                    ferry.push(right.front());
//                    right.pop();
//                }
//            }
//            if(ferry.empty()) {
//                if(left.empty() && right.empty())
//                    break;
//                if(isLeft) {
//                    if(!left.empty() && (right.empty() || left.front() -> entry <= right.front() -> entry))
//                        clock = left.front() -> entry;
//                    else {
//                        clock = max(clock + t, right.front() -> entry + t);
//                        isLeft = false;
//                    }
//                } else {
//                    if(!right.empty() && (left.empty() || right.front() -> entry <= left.front() -> entry))
//                        clock = right.front() -> entry;
//                    else {
//                        clock = max(clock + t, left.front() -> entry + t);
//                        isLeft = true;
//                    }
//                }
//            } else {
//                clock += t;
//                isLeft ^= 1;
//            }
//        }
//        for (int i = 0; i < m; ++i)
//            printf("%d\n", cars[i].exit);
//        if(c) printf("\n");
//    }
//}