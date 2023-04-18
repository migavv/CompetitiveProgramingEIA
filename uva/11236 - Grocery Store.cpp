//
// Created by migav on 6/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

/*
 * Let a, b, c, d the prices in cents of each of the 4 products, where 'a' is the cheapest one, 'b', is the second cheapest...
 * Equation goes as: a/100 * b/100 * c/100 * d/100 = (a + b + c + d)/100
 * All products can have the same price.
 *
 * Problem solution derives from solving the equation for d and iterating to all possible combinations of values for a, b and c.
 */

int main() {
    cout << fixed << setprecision(2);
    int i = 1;
    long long p, s;
    for (int a = 1; a <= 500; a++) { // Right bound is obtained from 2000 / 4, as otherwise the sum would surpass 2000 cents
        for (int b = a; b <= (2000 - a) / 3; b++) { //Bound is calculated the same way as for 'a', except that this time there are just 3 product prices to pick
            for (int c = b; c <= (2000 - a - b) / 2; c++) { //Same logic as a and b for calculating right bound
                p = a * b * c;
                s = a + b + c;
                if(p != 1000000 && 1000000*s % (p - 1000000) == 0) { //Check if a,b,c match restrictions derived from the initial equation solved for d.
                    int d = (int)(1000000 * s / (p - 1000000)); //Calculating value of d, from the initial equation.
                    if(d >= c && a+b+c+d <= 2000) cout << a/100.0 << " " << b/100.0 << " " //Check if solution matches the problem constraint
                        << c/100.0 << " " << d/100.0 << endl;
                    //d >= c guarantees that we won't get repeated answers
                }
            }
        }
    }
}