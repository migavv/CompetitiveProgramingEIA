#include <bits/stdc++.h>

using namespace std;

int tc, c = 1;

int main(){

    scanf("%d", &tc);

    while(tc--){

        int i = 0, re, mayor = 0;
        string web;
        unordered_map<string, int> map;
        unordered_map<string, int> mayores;

        while(i<10){
            cin >> web >> re;
            map[web] = re;
            i++;
        }

        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second > mayor){
                mayor = it->second;
                //mayores[it->first] = it->second;
            }
        }

        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second == mayor){
                mayores[it->first] = it->second;
            }
        }

        printf("Case #%d:\n", c++);

        for(auto it = mayores.begin(); it != mayores.end(); it++) {
            cout << it->first << endl;
        }

    }

    return 0;
}