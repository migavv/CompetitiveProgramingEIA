//
// Created by migav on 18/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    //n,m,q,l,u as described in the problem.
    int n, m, q, l, u, best, props[500][500]; //best: Max size that matches given conditions; props: Properties matrix

    //Build props matrix
    while(cin >> n >> m, n | m) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> props[i][j];

        //Get queries
        cin >> q;
        while(q--) {
            cin >> l >> u;
            best = 0;
            for(int i = 0; i < n; i++) {
                int s = (int)(lower_bound(props[i], props[i] + m, l) - props[i]); //s = upper left corner of best square for row i
                for(int j = best; i + j < n && s + j < m; j++) { //Checking diagonally the size of the square. j can start from current best size.
                    if(props[i+j][s+j] <= u) best++; //Updating best size if property of coordinates s+j, i+j still under range of heights
                    else break;
                }
            }
            cout << best << endl;
        }
        cout << "-\n";
    }
}