//
// Created by migav on 1/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

long long myPow(long long x, long long y) { //Function for computing powers on long integers
    if(y == 0) return 1;
    if(y&1) return x*myPow(x*x, y/2);
    else return myPow(x*x, y/2);
}

int main() {
    int t, i, coeffs[22]; //t: Number of testcases; i: Degree of the polynomial; coeffs: Coefficients of each term of the polynomial
    long long d, k, n, an; // an: Value of the polynomial evaluated at n
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &i);
        for(int j = 0; j <= i; j++) //Storing coefficients
            scanf("%d", &coeffs[j]);
        scanf("%lld", &d);
        scanf("%lld", &k);
        n = 1;
        while(d*n*(n+1)/2 < k) n++; //Looking for an n value such that An == Bk using arithmetic series formula.
        an = 0;
        for(int j = 0; j <= i; j++)
            an += myPow(n, j) * coeffs[j]; //Calculating An
        printf("%lld\n", an);
    }
}