#include <bits/stdc++.h>

using namespace std;

int n;

int main(){

    int c = 1;

    while(scanf("%d", &n), n){

        int t, countT = 0, countO = 0;
        
        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", &t);
            if(t == 0) countO++;
            else countT++;
        }

        printf("Case %d: %d\n", c++, countT - countO);
        
    }

    return 0;
}