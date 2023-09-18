//
// Created by migav on 7/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    double dist;
    cin >> x >> y;
    dist = sqrt(x*x + y*y);
    if(abs(round(dist) - dist) <= 1e-20) cout << "black";
    else if(x*y > 0) {
        if((int)ceil(dist) % 2) cout << "black";
        else cout << "white";
    } else {
        if((int)ceil(dist) % 2) cout << "white";
        else cout << "black";
    }
}