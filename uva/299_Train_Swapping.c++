#include <bits/stdc++.h>

using namespace std;

int tc;

int main(){

    scanf("%d", &tc);

    while(tc--){
        int l,temp, count = 0;

        scanf("%d", &l);
        int nums[l];

        for (size_t i = 0; i < l; i++)
        {
            scanf("%d", &nums[i]);
        }

        for (size_t i = 0; i < l; i++)
        {
            for (size_t j = l-1; j > i; j--)
            {
                if(nums[j] < nums[j-1]){
                    temp = nums[j];
					nums[j] = nums[j-1];
					nums[j-1] = temp;
					count++;
                }
            }
        
        }

        printf("Optimal train swapping takes %d swaps.\n", count);
    }

    return 0;
}