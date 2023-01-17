#include <bits/stdc++.h>

using namespace std;

int n,m;

int main(){

    while(scanf("%d" "%d", &n, &m), n || m){

        unordered_map<int, int> map;
        int num, count = 0;

        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if(map.find(num) == map.end()) map[num]++;
        }

        for (size_t i = 0; i < m; i++)
        {
            scanf("%d", &num);
            if(map.find(num) != map.end()) count++;
        }

        printf("%d\n", count);
    }

    return 0;
}