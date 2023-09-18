//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, d, breaks[100003];
    cin >> n >> m >> d;
    set<int> days;
    for(int i = 0; i < n; i++)
        cin >> breaks[i];
    sort(breaks, breaks + n);
    for(int i = 0; i < n; i++) {
        auto j = days.lower_bound(min(breaks[i] - d, 0));
        if(j == days.end())
            days.insert(breaks[i]);
        else {
            days.erase(j);
            days.insert(breaks[i]);
        }
    }
    cout << days.size();
}