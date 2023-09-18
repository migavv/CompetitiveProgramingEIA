//
// Created by migav on 17/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int st[20][200005];

int main() {
    int n, q, nms[200005], a, b;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> nms[i];
    copy(nms, nms + n, st[0]);
    for(int i = 1; i < 20; i++) {
        for(int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))]);
    }
    while(q--) {
        cin >> a >> b;
        int i = log2_floor(b - a + 1);
        cout << min(st[i][a-1], st[i][b - (1 << i)]) << endl;
    }
}