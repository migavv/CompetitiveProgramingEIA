//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, player[505], best = -1;
    long long k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> player[i];
        best = max(best, player[i]);
    }
    if(k > n) {
        cout << best;
        return 0;
    }
    best = player[0];
    int streak = 0;
    for(int i = 1; i < n; i++) {
        if(player[i] < best)
            streak++;
        else {
            best = player[i];
            streak = 1;
        }
        if(streak == k) break;
    }
    cout << best;
}