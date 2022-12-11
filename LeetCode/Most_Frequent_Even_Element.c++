#include <bits/stdc++.h>

using namespace std;

int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, size_t> ocurrencia;
    int minimo = INT_MAX, mayor = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2 == 0){
            ocurrencia[nums[i]]++;
        }
    }
    if (ocurrencia.empty()) return -1;

    for(auto it = ocurrencia.begin(); it != ocurrencia.end(); it++) {
        if(it->second > mayor){
            mayor = it->second;
            minimo = it ->first;
        }
        else if(it->second == mayor){
            if(it->first < minimo) minimo = it->first;
        }

    }

    return minimo;
}

int main(){
    vector<int> nums = {29,47,21,41,13,37,25,7};

    cout << mostFrequentEven(nums);

    return 0;
}