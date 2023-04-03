//
// Created by migav on 3/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, x, y; 
    vector<pair<int, int>> pairs;
    while(cin >> k) {
        pairs.clear();
        for(y = k + 1 ;; y++) {
            if(!((k*y)%(y-k))) {
                x = y*k/(y-k);
                pairs.emplace_back(x, y);
            }
            if(x == y) break;
        }
        cout << pairs.size() << endl;
        for(auto p : pairs)
            cout << "1/" << k << " = 1/" << p.first << " + 1/" << p.second << endl;
    }
}
