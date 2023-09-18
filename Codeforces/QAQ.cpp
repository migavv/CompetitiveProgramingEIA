//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'Q') for(int j = i + 1; j < s.length(); j++) {
            if(s[j] == 'A') for(int k = j + 1; k < s.length(); k++) {
                if(s[k] == 'Q') res++;
            }
        }
    }
    cout << res;
}