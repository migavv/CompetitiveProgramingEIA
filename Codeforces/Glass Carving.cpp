//
// Created by migav on 1/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, h, n, pos, len;
    char dir;
    cin >> w >> h >> n;
    set<int> hc, vc;
    hc.insert(0); vc.insert(0);
    hc.insert(h); vc.insert(w);
    multiset<int> hs, vs;
    hs.insert(h); vs.insert(w);
    set<int>::iterator l, r, itc;
    multiset<int>::iterator its;
    for(int i = 0; i < n; i++) {
        cin >> dir >> pos;
        if(dir == 'H') {
            r = itc = hc.lower_bound(pos);
            itc--; l = itc; //Test
            len = *r - *l;
            itc = hs.find(len);
            hs.erase(itc);
            hs.insert(pos - *l);
            hs.insert(*r - pos);
            hc.insert(pos);
        } else {
            r = itc = vc.lower_bound(pos);
            itc--; l = itc; //Test
            len = *r - *l;
            itc = vs.find(len);
            vs.erase(itc);
            vs.insert(pos - *l);
            vs.insert(*r - pos);
            vc.insert(pos);
        }
        cout << (long long)*hs.rbegin() * (long long)*vs.rbegin() << endl;
    }
}