//
// Created by migav on 3/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    char u, v;
    string s, t;
    int change[26][26];
    cin >> s >> t >> n;
    if(s.length() != t.length()) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++)
            change[i][j] = 200;
        change[i][i] = 0;
    }
    while(n--) {
        cin >> u >> v >> w;
        change[u-'a'][v-'a'] = min(change[u-'a'][v-'a'], w);
    }
    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                change[i][j] = min(change[i][j], change[i][k] + change[k][j]);
    int cost = 0, best;
    char ch = 0;
    bool possible = true;
    string ans;
    for(int i = 0; i < s.length(); i++) {
        best = 200;
        for(int j = 0; j < 26; j++) {
            int curr = change[s[i]-'a'][j] + change[t[i]-'a'][j];
            if(curr < best) {
                ch = (char)(j+'a');
                best = curr;
            }
        }
        ans += ch;
        if(best >= 200)  {
            cout << -1;
            possible = false;
            break;
        }
        cost += best;
    }
    if(possible) cout << cost << endl << ans;
}