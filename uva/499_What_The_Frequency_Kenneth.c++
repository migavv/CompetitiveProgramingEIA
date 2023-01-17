#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;

    cin.ignore();

    while(getline(cin, s)){
        unordered_map<char, int> l;
        unordered_map<char, int> lR;
        vector<char> upper;
        vector<char> lower;
        int mayor = 0;

        for (size_t i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i])) l[s[i]]++;
        }

        for(auto it = l.begin(); it != l.end(); it++){
            if(it->second > mayor) mayor = it->second;
        }
        
        for(auto i = l.begin(); i != l.end(); i++){
            if(i->second == mayor) {
                lR.insert({i->first, i->second});
            }
        }

        for(auto t = lR.begin(); t != lR.end(); t++){
            if(isupper(t-> first)) upper.push_back(t->first);
            else lower.push_back(t->first);
        }

        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        for (size_t i = 0; i < upper.size(); i++)
        {
            cout << upper[i];
        }

        for (size_t i = 0; i < lower.size(); i++)
        {
            cout << lower[i];
        }
        
        cout << " " << mayor << endl;
    }

    return 0;
}