#include <bits/stdc++.h>

using namespace std;

int main(){
    int queries, length;

    cin >> queries;
    
    while(queries--){

        int team = 1;

        cin >> length;

        int nums[length];

        for (int i = 0; i < length; i++){
            cin >> nums[i];
        }

        sort(nums, nums + length);

        for (int j=0; j<length;j++){
            for (int k = 1; k < length;k++){
                
                if (abs(nums[j]-nums[k]) == 1){
                    team = 2;
                }
            }
            
        }
        cout << team << endl;

    }
    return 0;
}