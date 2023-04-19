//
// Created by migav on 19/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

int n, rungs[100001]; //rungs: Height of each rung

bool can(int k) { //Simulation for k strength
    int curr = 0;
    for(int i = 0; i < n; i++) {
        if(curr + k < rungs[i])
            return false;
        if(rungs[i] - curr == k)
            k--;
        curr = rungs[i];
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> rungs[i];
        int l = rungs[0], h = rungs[n - 1];

        //Binary search for minimum strength needed:
        while(l <= h) {
            int m = (l + h)/2;
            if(can(m)) {
                h = m - 1;
            } else l = m + 1;
        }
        cout << "Case " << c << ": " << l << endl;
    }
}