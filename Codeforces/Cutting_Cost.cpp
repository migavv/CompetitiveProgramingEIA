#include <bits/stdc++.h>

using namespace std;

int cases, a,b,c, Case = 1;

int main(){

    scanf("%d", &cases);

    while (cases--)
    {
        scanf("%d" "%d" "%d", &a, &b, &c);
        if ((a > b && a < c) || (a < b && a > c)) printf("Case %d: %d\n", Case++, a);

        if((b > a && b < c) || (b < a && b > c)) printf("Case %d: %d\n", Case++, b);

        if ((c>a && c<b) || (c<a && c>b)) printf ("Case %d: %d\n", Case++, c);
    }

}