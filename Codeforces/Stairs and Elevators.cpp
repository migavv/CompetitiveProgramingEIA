//
// Created by migav on 4/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    const int INF = 2e8;
    long long m, n, s, e, v, q;
    int pos, x1, y1, x2, y2;
    set<int> stairs, elevators;
    cin >> n >> m >> s >> e >> v;
    for(int i = 0; i < s; i++) {
        cin >> pos;
        stairs.insert(pos);
    }
    for(int i = 0; i < e; i++) {
        cin >> pos;
        elevators.insert(pos);
    }
    cin >> q;
    //aux vars:
    set<int>::iterator stair, elev;
    long long costS, costE, leftS = -INF, rightS =INF, leftE = -INF, rightE = INF;
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) {
            cout << abs(y2-y1) << endl;
            continue;
        }
        if(!stairs.empty()) {
            stair = stairs.lower_bound(y1);
            if(stair != stairs.end()) rightS = *stair;
            if(stair != stairs.begin()) {
                stair--;
                leftS = *stair;
            }
        }
        if(!elevators.empty()) {
            elev = elevators.lower_bound(y1);
            if(elev != elevators.end()) rightE = *elev;
            if(elev != stairs.begin()) {
                elev--;
                leftE = *elev;
            }
        }
        costS = min(abs(y1 - leftS) + abs(leftS - y2) + abs(x2 - x1),
                    abs(y1 - rightS) + abs(rightS - y2) + abs(x2 - x1));
        costE = min(abs(y1 - leftE) + abs(leftE - y2) + (int)ceil(abs(x2 - x1)/(double)v),
                    abs(y1 - rightE) + abs(rightE - y2) + (int)ceil(abs(x2 - x1)/(double)v));
        cout << min(costE, costS) << endl;
    }
}