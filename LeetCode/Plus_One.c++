#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int last = digits.size();

    while(last--){
        if (digits[last] < 9) {
            digits[last] += 1;
            return digits;
        }
        else digits[last] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
    
}

int main(){
    vector <int> nums1 = {9,9,9};

    plusOne(nums1);

    for (size_t i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i];
    }

    return 0;
}