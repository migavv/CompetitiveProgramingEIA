//
// Created by migav on 10/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int n, taken, ring[17]; //n: Ring size; taken: Bitmask keeping track of chosen numbers; ring: Array representing the ring
bitset<32> isPrime; //Bitmap is constructed in such a way that for every prime number p < 32, isPrime[p] = true;

void backtrack(int num) {
    if(num > n ) { //If ring is filled
        if(isPrime[ring[n] + 1]) { //If last chosen number + the first one (always 1) equals a prime number, output results
            cout << 1;
            for(int i = 2; i <= n; i++)
                cout << " " << ring[i];
            cout << endl;
        }
        return;
    }
    for(int i = 2; i <= n; i++) {
        //If 'i' has not been chosen and the sum of 'i' and the previously selected number equals a prime number:
        if(!(taken & (1 << i)) && isPrime[i + ring[num - 1]]) {
            taken |= 1 << i; //Mark i as taken
            ring[num] = i; //Add i to the ring
            backtrack(num + 1); //Recursion to choose next number
            taken &= ~(1 << i); //Backtrack
        }
    }
}

int main() {
    int t = 0;
    ring[1] = 1; //Setting first value of the ring as 1.

    //Using sieve of Eratosthenes algorithm to build 'isPrime' bitset:
    isPrime.set();
    for(int i = 2; i <= sqrt(32); i++) {
        if(isPrime[i]) for(int j = i; j * i < 32; j++)
                isPrime[i * j] = false;
    }

    while(cin >> n) { //Reading input
        //Output result
        if(t++) cout << endl;
        cout << "Case " << t << ":" << endl;
        taken = 0;
        backtrack(2);
    }
}