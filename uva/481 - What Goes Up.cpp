//
// Created by migav on 11/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

//int main() {
//    vector<int> seq, lis, lPos, p, res;
//    int v;
//    while(cin >> v)
//        seq.push_back(v);
//    seq.push_back(INT_MAX);
//    p.assign(seq.size(), 0);
//    for(int i = 0; i < seq.size(); i++) {
//        int pos = (int)(lower_bound(lis.begin(), lis.end(), seq[i]) - lis.begin());
//        if(pos == lis.size()) {
//            lis.push_back(seq[i]);
//            lPos.push_back(i);
//        } else {
//            lis[pos] = seq[i];
//            lPos[pos] = i;
//        }
//        p[i] = pos ? lPos[pos - 1] : INT_MIN;
//    }
//    cout << lis.size() - 1 << endl;
//    cout << "-" << endl;
//    int k = p[seq.size() - 1];
//    while(k != INT_MIN) {
//        res.push_back(seq[k]);
//        k = p[k];
//    }
//    reverse(res.begin(), res.end());
//    for(int r : res) cout << r << endl;
//}