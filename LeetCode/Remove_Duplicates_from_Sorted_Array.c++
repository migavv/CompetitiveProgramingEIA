#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    unordered_map <int, int> umap;
    int res = nums.size(); 

    for (auto i = nums.begin(); i != nums.end(); ++i) {
        if (umap.find(*i) == umap.end()) {
            umap[*i] = *i;
        }else{
            nums.erase(i);
            i--;
            res--;
        }
    }

    return res;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    cout << removeDuplicates(nums);

    return 0;
}