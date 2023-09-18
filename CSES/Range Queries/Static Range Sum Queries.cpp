//
// Created by migav on 16/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, a, b;
    long long nums[200005], res;
    cin >> n >> q;
    cin >> nums[1];
    for(int i = 2; i <= n; i++) {
        cin >> nums[i];
        nums[i] += nums[i-1];
    }
    while(q--) {
        cin >> a >> b;
        res = nums[b];
        if(a > 1) res -= nums[a-1];
        cout << res << endl;
    }
}