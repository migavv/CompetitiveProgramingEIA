//
// Created by migav on 13/10/2022.
//

#include <queue>
#include <stack>
#include <cstdio>

using namespace std;

//int main() {
//    int set, n, s, q, c, aux, ttl, time;
//    scanf("%d", &set);
//    while(set--) {
//        ttl = 0;
//        time = 0;
//        stack<int> carrier;
//        scanf("%d %d %d", &n, &s, &q);
//        queue<int> pB[101];
//        for (int i = 1; i <= n; ++i) {
//            scanf("%d",&c);
//            ttl += c;
//            for (int j = 0; j < c; ++j) {
//                scanf("%d", &aux);
//                pB[i].push(aux);
//            }
//        }
//        size_t it = 1;
//        while(ttl) {
//            while(!carrier.empty()) {
//                if(carrier.top() == it) {
//                    carrier.pop();
//                    ttl--;
//                    time++;
//                    if(!ttl) break;
//                }
//                else if(pB[it].size() < q) {
//                    pB[it].push(carrier.top());
//                    carrier.pop();
//                    time++;
//                }
//                else break;
//            }
//            if(!ttl) break;
//            while(carrier.size() < s) {
//                if(pB[it].empty())
//                    break;
//                carrier.push(pB[it].front());
//                pB[it].pop();
//                time++;
//            }
//            it = (it % n) + 1;
//            time += 2;
//        }
//        printf("%d\n", time);
//    }
//    return 0;
//}
