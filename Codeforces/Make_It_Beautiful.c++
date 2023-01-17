#include <bits/stdc++.h>

using namespace std;

int t;

int main(){

    scanf("%d", &t);

    while(t--){
        int n, temp;
        vector<int> nums;

        scanf("%d", &n);

        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            nums.push_back(temp);
        }

        if(count(nums.begin(), nums.end(), nums[0]) == nums.size()) printf("NO\n");
        else{
            sort(nums.rbegin(), nums.rend());

            int k = 1;
            while(nums[k] == nums[0]){
                k++;
                swap(nums[k], nums[0]);
            }

            printf("YES\n");
            for (size_t i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << " ";
                //printf("%d", nums[i], i == n - 1 ? "\n" : " ");
            }

            cout << endl;
            
        }
        
    }

    return 0;
}