//
// Created by migav on 3/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, t = 1, res = 0;
    priority_queue<pair<int, int>> cards;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        cards.emplace(b,a);
    }
    while(!cards.empty() && t > 0) {
        t--;
        auto card = cards.top();
        cards.pop();
        t += card.first;
        res += card.second;
    }
    cout << res;
}