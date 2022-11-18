//
// Created by migav on 26/09/2022.
//

#include<cstdio>

using namespace std;

struct soldier {
    soldier *right;
    soldier *left;
    int num;

    explicit soldier(int num) {
        this -> num = num;
        left = nullptr;
        right = nullptr;
    }
};
//int main() {
//    int s, b, l, r;
//    while(scanf("%d %d", &s, &b), (s || b)){
//        auto *left = new soldier(1);
//        auto *right = left;
//        soldier* list[s + 1];
//        list[1] = left;
//        for (int i = 2; i <= s; ++i) {
//            auto sold = new soldier(i);
//            list[i] = sold;
//            right -> right = sold;
//            sold -> left = right;
//            right = sold;
//        }
//
//        while(b--) {
//            scanf("%d %d", &l, &r);
//            auto *from = list[l];
//            auto *to = list[r];
//            if(from -> left == nullptr) {
//                printf("* ");
//                left = to -> right;
//            } else {
//                printf("%d ", from -> left -> num);
//                from -> left -> right = to -> right;
//            }
//            if(to -> right == nullptr) {
//                printf("*");
//            }
//            else {
//                printf("%d", to -> right -> num);
//                to -> right -> left = from -> left;
//            }
//            printf("\n");
//        }
//        printf("-\n");
//    }
//}