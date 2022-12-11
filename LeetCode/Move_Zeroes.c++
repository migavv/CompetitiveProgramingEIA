#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
    if (nums.size() > 1){
        int count = 0, aux = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                aux = nums[count];
                nums[count] = nums[i];
                nums[i] = aux;
                count++;
            }
        }
    }
    
}

int main(){
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }

}