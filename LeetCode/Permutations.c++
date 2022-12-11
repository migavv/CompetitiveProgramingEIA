#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> res;

    do{
        res.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end()));

    return res;
}

int main(){
    vector <int> nums1 = {0,1};

    permute(nums1);

    return 0;
}