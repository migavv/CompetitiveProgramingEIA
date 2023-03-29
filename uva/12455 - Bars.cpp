//
// Created by migav on 29/03/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, p, sum, bars[20]; //t: # of test cases; n: required length; p: number of bars; bars: length of each bar;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        for(int i = 0; i < p; i++) cin >> bars[i];
        for(int i = 0; i < (1 << p); i++) { //For every subset of p
            sum = 0;
            for(int j = 0; j < p; j++) //Calculate length of current subset of bars
                if(i & (1 << j)) sum += bars[j];
            if(sum == n) break;
        }
        if(sum == n) cout << "YES\n"; //If a subset satisfy length condition 'n', output YES.
        else cout << "NO\n";
    }
}