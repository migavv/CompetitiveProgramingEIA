//
// Created by migav on 29/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, val, a, b, A[200005];
    cin >> n >> q >> A[1];
    for(int i = 2; i <= n; i++) {
        cin >> val;
        A[i] = A[i-1] ^ val;
    }
    while(q--) {
        cin >> a >> b;
        int res = A[b];
        if(a > 1) res ^= A[a - 1];
        cout << res << endl;
    }
}