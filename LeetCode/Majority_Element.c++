#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int>& nums) {
    int mayor = 0;
    unordered_map<int, size_t> ocurrencia;

    for(int i = 0; i < nums.size(); i++){
        if(!ocurrencia[nums[i]]){
            ocurrencia[nums[i]]++;
        }else ocurrencia[nums[i]]++;
    }

    for(auto it = ocurrencia.begin(); it != ocurrencia.end(); it++) {
        if(it->second > nums.size()/2) mayor = it->first;
    }

    return mayor;
}

int main(){
    vector<int> nums = {3,2,3};

    cout << majorityElement(nums);

    return 0;
}