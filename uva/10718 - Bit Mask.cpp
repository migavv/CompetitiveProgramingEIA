//
// Created by migav on 22/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n,l,u,m;
    while(cin >> n >> l >> u) {
        m = 0;
        for(int i = 35; i >= 0; i--) {
            long long k = (1LL << i)|m;
            if(k > u) continue; //k out of range
            if(k <= l || !(n&(1 << i))) //If k <= l, must turn on bit i of m, otherwise it will never reach range
                m = k;                  //Also, if bit 'i' of n is off, must be turned on in m.
        }
        cout << m << endl;
    }
}