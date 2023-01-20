//
// Created by migav on 9/10/2022.
//

#include<cstdio>

int main() {
    int n, a ,b, aux;
    bool even;
    while(scanf("%d", &n), n) {
        a = 0;
        b = 0;
        even = false;
        aux = 1;
        while(n) {
            if(n & 1) {
                if(even) {
                    b |= aux;
                    even = false;
                } else {
                    a |= aux;
                    even = true;
                }
            }
            aux <<= 1;
            n >>= 1;
        }
        printf("%d %d\n", a, b);
    }
}