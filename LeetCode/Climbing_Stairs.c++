#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    int uno = 1, dos = 1, aux = 0;

    for (int i = 0; i < n-1; i++){
        aux = dos;
        dos = uno;
        uno = uno + aux; 
    }
    return uno;
}

int main(){

    int n = 2;
    cout << climbStairs(n);
    
    return 0;
}