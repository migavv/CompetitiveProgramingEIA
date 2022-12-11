#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char>& s) {
    int count = 0;
    char aux;

    while(count < s.size()/2){
        aux = s[count];
        s[count] = s[s.size() - (1+count)];
        s[s.size() - (1+count)] = aux;
        count++;
    }
        
}

int main(){
    vector<char> nums = {'H','a','n','n','a', 'h'};

    reverseString(nums);

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }

}