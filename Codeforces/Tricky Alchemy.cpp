//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long yi, bi, yf, gf, bf;
    cin >> yi >> bi >> yf >> gf >> bf;
    long long yn, bn;
    yn = bn = 0;
    for(int i = 0; i < yf; i++)
        yn += 2;
    for(int i = 0; i < gf; i++) {
        yn++;
        bn++;
    }
    for(int i = 0; i < bf; i++)
        bn += 3;
    cout << max(bn - bi, 0ll) + max(yn - yi, 0ll);
}