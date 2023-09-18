//
// Created by migav on 7/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    char curr = 'a';
    int res = 0;
    for(int i = 0; i < s.length(); i++) {
        int l = abs(s[i]-curr);
        int r = (min(s[i], curr)-'a' + 'z'-max(s[i], curr) + 1);
        res += min(l,r);
        curr = s[i];
    }
    cout << res;
}