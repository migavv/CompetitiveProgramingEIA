//
// Created by migav on 3/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, aux, res = 0;
    cin >> n >> m;
    if(m%n) cout << -1;
    else {
        aux = m/n;
        while(aux > 1 && !(aux%3)) {
            aux /= 3;
            res++;
        }
        while(aux > 1 && !(aux%2)) {
            aux /= 2;
            res++;
        }
        if(aux == 1) cout << res;
        else cout << -1;
    }
}