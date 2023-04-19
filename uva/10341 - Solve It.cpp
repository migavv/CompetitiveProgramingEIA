//
// Created by migav on 18/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

int p,q,r,s,t,u; //Equation coefficients
double f(double x) { //f(x), left side of the equation
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u;
}

int main() {
    double a,b,l,h,x,ans;
    cout << setprecision(4) << fixed;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        a = f(0); b = f(1);
        if(a*b > 0) { //Checking if f(x) has roots between x = 0 & x = 1
            cout << "No solution" << endl;
            continue;
        }
        //Establishing positive bound (h) and negative bound (l)
        if(a < b) {l = 0; h = 1;}
        else {l = 1; h = 0;}

        //Bisection
        while(fabs(h-l) > 1e-9) {
            x = (l+h)/2;
            ans = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u;
            if(ans == 0) break;
            if(ans < 0) l = x; else h = x;
        }

        //Print
        cout << x << endl;
    }
}