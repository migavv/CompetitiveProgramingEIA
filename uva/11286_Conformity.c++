#include <bits/stdc++.h>

using namespace std;

int n;

int main(){

    while (scanf("%d", &n), n != 0)
    {
        int mayor = 0;
        map<vector<int>, int> map;
        vector<int> nums(5);

        while (n--)
        {
            int aux;
            for (size_t i = 0; i < 5; i++)
            {
                scanf("%d", &aux);
                nums[i] = aux;
            }

            sort(nums.begin(), nums.end());
            
            map[nums]++;

        }

        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second > mayor){
                mayor = it->second;
            }
        }

        int count = 0;

        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second == mayor){
                count++;
            }
        }

        mayor = mayor * count;

        printf("%d\n", mayor);
        
    }

    return 0;
}

