//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a[5005], sums[5005];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sums[0] = a[0];
    for(int i = 1; i < n; i++)
        sums[i] = a[i] + sums[i-1];
    double res = -1, curr;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(j - i + 1 >= k) {
                curr = sums[j];
                if(i) curr -= sums[i-1];
                curr /= (j - i + 1);
                //if(i == 1 && j == 3) cout << curr << endl;
                res = max(curr, res);
            }
        }
    }
    cout << setprecision(15) << fixed << res;
}