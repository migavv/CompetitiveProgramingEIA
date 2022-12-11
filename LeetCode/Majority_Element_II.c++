#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {

    vector<int> respuesta;
    unordered_map<int, size_t> ocurrencia;

    for(int i = 0; i < nums.size(); i++){
        if(!ocurrencia[nums[i]]){
            ocurrencia[nums[i]]++;
        }else ocurrencia[nums[i]]++;
    }

    for(auto it = ocurrencia.begin(); it != ocurrencia.end(); it++) {
        if(it->second > nums.size()/3) respuesta.push_back(it->first);
    }

    /*for(int i = 0; i < respuesta.size(); i++){
        cout << respuesta[i] << " ";
    }*/

    return respuesta;
}

int main(){
    vector<int> nums = {1,2};

    majorityElement(nums);

    return 0;
}