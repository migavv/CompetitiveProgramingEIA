#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
        unordered_map<int, int> unico;
        
        for (int i = 0; i < nums.size(); i++){
            if(unico.find(nums[i]) == unico.end()) unico[nums[i]]++;
            else unico.erase(nums[i]);
        }

        auto it = unico.begin();
        return it->first;

        /*for (auto itr = unico.begin(); itr != unico.end(); ++itr) {
        cout << itr->first
             << '\t' << itr->second << '\n';
        }*/

}

int main(){
    vector <int> nums1 = {2,2,5,5,1,11,11};
    
    //int target = 10;

    cout << singleNumber(nums1);

    //twoSum(nums1, target);

    return 0;
}