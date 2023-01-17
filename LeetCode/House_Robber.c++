#include <bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums) {

    if (nums.size() == 1) return nums[0];

    if(nums.size() < 3) return max(nums[0], nums[1]);

    int nums1 = nums[0],nums2 = max(nums[0],nums[1]), res = 0;
    
    for(int i = 2 ; i < nums.size(); i++){
        res = max(nums[i] + nums1, nums2);
        nums1 = nums2;
        nums2 = res;
    }

    return res;
}

int main(){
    vector<int> nums = {2,1,1,2};
    cout << rob(nums);
    
    return 0;
}