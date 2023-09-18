//
// Created by migav on 3/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, num, maxi, res;
    set<int> nums;
    cin >> t;
    while(t--) {
        cin >> n;
        while(n--) {
            cin >> num;
            if(!(num%2)) nums.insert(num);
        }
        res = 0;
        while(!nums.empty()) {
            maxi = *nums.rbegin();
            nums.erase(maxi);
            maxi /= 2;
            if(!(maxi % 2))
                nums.insert(maxi);
            res++;
        }
        cout << res << endl;
    }

}