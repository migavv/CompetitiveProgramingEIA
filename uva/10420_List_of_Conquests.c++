#include <bits/stdc++.h>

using namespace std;

int n;

int main(){

    scanf("%d", &n);

    map<string, int> map;

    cin.ignore();
    while (n--)
    {
        string s, country;
        cin >> country;
        getline(cin,s);
        
        map[country]++;
    }

    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}