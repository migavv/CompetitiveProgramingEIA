//
// Created by migav on 6/10/2022.
//

#include <cstdio>
#include <bitset>

using namespace std;

//int main() {
//    int n, m, s, e, r;
//    bool conflict;
//    while(scanf("%d %d", &n, &m), n || m) {
//        conflict = false;
//        bitset<1000000> schedule(0);
//        while(n--) {
//            scanf("%d %d", &s, &e);
//            if(conflict) continue;
//            for(size_t i = s; i < e; i++) {
//                if(schedule[i]) {
//                    conflict = true;
//                    break;
//                }
//                schedule[i] = true;
//            }
//        }
//        while(m--) {
//            scanf("%d %d %d", &s, &e, &r);
//            if(conflict) continue;
//            for(size_t i = s; i < 1000000; i += r) {
//                for(size_t j = 0; j < min(schedule.size() - i, size_t(e - s)); j++) {
//                    if(schedule[i + j]) {
//                        conflict = true;
//                        break;
//                    }
//                    schedule[i + j] = true;
//                }
//                if(conflict) break;
//            }
//        }
//        if(conflict) printf("CONFLICT\n");
//        else printf("NO CONFLICT\n");
//    }
//}