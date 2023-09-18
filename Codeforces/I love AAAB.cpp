//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a;
    string s;
    bool possible;
    cin >> t;
    while(t--) {
        a = 0;
        possible = true;
        cin >> s;
        if(s.length() < 2 || s[s.length()-1] == 'A') {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'A')
                a++;
            else {
                if(a == 0) {
                    possible = false;
                    break;
                }
                a--;
            }
        }
        if(possible) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}