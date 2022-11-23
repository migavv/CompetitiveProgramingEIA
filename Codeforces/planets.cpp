#include <bits/stdc++.h>

using namespace std;

int main(){

    int cases;
    cin >> cases;

    while (cases--)
    {
        int planets,cost,total=0;
        map <int, int> mp;

        cin >> planets >> cost;

       int a[planets];

       for (int i = 0; i < planets; i++){
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] <= cost){
            total++;
        }
       }
       cout << total << endl;

    }
}