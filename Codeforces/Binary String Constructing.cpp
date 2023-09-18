//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string alt;
    if(c) {
        if(a >= b) alt = "01";
        else alt = "10";
        a--;
        b--;
        c--;
    }
    while(c > 0) {
        if(alt[alt.length()-1] == '0') {
            alt += '1';
            b--;
        }
        else {
            alt += '0';
            a--;
        }
        c--;
    }
    string ones, zeros;
    while(a > 0) {
        zeros += '0';
        a--;
    }
    while(b > 0) {
        ones += '1';
        b--;
    }
    if(!alt.length()) cout << ones + zeros;
    else {
        if(alt[0] == '1') alt.insert(1, (ones + zeros));
        else alt.insert(1, (zeros+ones));
        cout << alt;
    }
}