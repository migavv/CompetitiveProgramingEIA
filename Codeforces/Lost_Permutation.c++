#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
    scanf("%d", &t);

    while(t--){
        int m, s, aux, x = 0,temp = 0;
        unordered_set<int> num;
        vector<int> nums;
        scanf("%d" "%d", &m, &s);
    
        for (size_t i = 0; i < m; i++)
        {
            scanf("%d", &aux);
            nums.push_back(aux);
            num.insert(aux);
        }

        for (size_t i = 1; i <= 100; i++)
        {
            if(num.find(i) == num.end()){
                num.insert(i); 
                temp += i;

                if(temp <= s) {
                    x = temp;
                    nums.push_back(i);
                }
                if(temp > s) {
                    break;
                }
            }
            
        }

        sort(nums.begin(), nums.end());
        int flag = 1;

        if(x != s){
            flag = 0;
        }

        for (size_t i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] - nums[i] != 1) flag = 0;
        }
        
        if(flag) printf("YES\n");
        else printf("NO\n");
        
    }

}