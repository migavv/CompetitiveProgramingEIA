//
// Created by migav on 1/07/2023.
//

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int A[] {-7,10,2,3,8,8,1, 99};

int memo[1000];

int lis(int i) {
    if(!i) return 1;
    int &ans = memo[i];
    if(ans != -1) return ans;
    ans = 1;
    for(int j = 0; j < i; j++)
        if(A[j] < A[i])
            ans = max(ans, lis(j) + 1);
    return ans;
}

void printLIS(int a, unordered_map<int, int> &m) {
    if(m[a] == -99) cout << a << " ";
    else {
        printLIS(m[a], m);
        cout << a << " ";
    }
}

int main() {
    unordered_map<int, int> m;
    int n = 8, k = 0;
    vi L(n, 0);
    for(int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(),L.begin()+k,A[i]) - L.begin();
        L[pos] = A[i];
        m[A[i]] = pos ? L[pos - 1] : -99;
        if(pos == k) k++;
    }
    int a = L[k - 1];
    printLIS(L[k - 1],m);
}