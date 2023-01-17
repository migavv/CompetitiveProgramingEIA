#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] != i) return i;
    }

    return nums.size();
    
}

int main(){
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << missingNumber(nums);

    return 0;
}