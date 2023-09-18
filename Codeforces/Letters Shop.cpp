//
// Created by migav on 2/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<char, vector<int>> dic;
    int idx[26], res;
    int n, m;
    string pf, name;
    cin >> n >> pf >> m;
    for(int i = 0; i < n; i++)
        dic[pf[i]].push_back(i);
    for(int i = 0; i < m; i++) {
        cin >> name;
        memset(idx, 0, sizeof idx);
        res = -1;
        for(char ch : name)
            res = max(res, dic[ch][idx[ch-'a']++]);
        cout << res + 1 << endl;
    }
}
