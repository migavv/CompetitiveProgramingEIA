#include <bits/stdc++.h>

using namespace std;

int cases;

int main(){

    scanf("%d", &cases);

    while (cases--){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        if((a > b && a < c) || (a < b && a > c)) printf("%d\n", a);
        if((b > a && b < c) || (b < a && b > c)) printf("%d\n", b);
        if((c > b && c < a) || (c < b && c > a)) printf("%d\n", c);
    }

    return 0;
}