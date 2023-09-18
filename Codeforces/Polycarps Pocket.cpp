//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, val, freq[200] {0};
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++) {
        cin >> val;
        res = max(res, ++freq[val]);
    }
    cout << res;
}