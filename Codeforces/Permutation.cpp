//
// Created by migav on 7/08/2023.
//

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, num, nums[5003];
    cin >> n;
    //memset(nums, 1, sizeof nums);
    for(int i = 1; i <= n; i++) nums[i] = 1;
    int res = n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(nums[num] && num <= n) {
            res--;
            nums[num]--;
        }
    }
    cout << res;
}