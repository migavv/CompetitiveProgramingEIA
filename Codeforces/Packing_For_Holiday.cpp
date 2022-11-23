#include <bits/stdc++.h>

using namespace std;

int cases, L,W,H, c=1;

int main(){

    scanf("%d", &cases);

    while (cases--)
    {
        scanf("%d %d %d", &L, &W, &H);

        if (L <= 20 && W <= 20 && H <= 20){
            printf("Case %d: good\n", c++);
        }else printf("Case %d: bad\n", c++);
    }
    
}