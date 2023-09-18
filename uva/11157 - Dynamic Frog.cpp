//
// Created by migav on 22/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, c=1;
    char s[102]; //s[i] = 'B' if stone i is B, s[i] = 'S' if small.
    long long d, m[102], maxi; //m[i] = distance from stone to left bank.
    //Both left and right banks are included in m & s.
    scanf("%d", &t);
    while(t--) {
        scanf("%d %lld\n", &n, &d); //Reading N & D

        m[0] = 0; m[n + 1] = d; //Left and right banks into m.

        //Reading data for each stone.
        for(int i = 1; i < n; i++)
            scanf("%c-%lld ", &s[i], &m[i]);
        scanf("%c-%lld", &s[n], &m[n]);

        /* Calculating minimized maximum leap:
         * The best way of crossing through consecutive
         * small rocks is by leaving one in between. */
        maxi = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == 'B')
                maxi =max(maxi, m[i]-m[i-1]);
            else
                maxi = max(maxi, m[i+1]-m[i-1]);
                //If rock is small, Fred will eventually jump over it,
                //so distance between previous and next is considered.
        }
        maxi = max(maxi, m[n+1]-m[n]);
        printf("Case %d: %lld\n", c++, maxi);
    }
}