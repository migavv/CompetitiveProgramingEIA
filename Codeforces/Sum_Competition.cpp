#include <bits/stdc++.h>

using namespace std;

int cases,a,b,c;

int main(){

    scanf("%d", &cases);

    while (cases--){

        scanf("%d" "%d" "%d", &a, &b, &c);

        if((a == b+c) || (b == a+c) || (c == a+b))
            printf("YES\n");

        else printf("NO\n");

    }

    return 0;
}