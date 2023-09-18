//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; bitset<100003> tests;
    string t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t[0] == 'L')
            tests[i] = false;
        else tests[i] = true;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(!tests[i+1])
            tests[i] = !tests[i];
    }
    if(tests[0]) cout << "TRUTH";
    else cout << "LIE";
}