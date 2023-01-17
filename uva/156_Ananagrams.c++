#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    unordered_map<string, int> map;
    vector<string> words;

    while(cin >> s, s!= "#"){

        words.push_back(s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        sort(s.begin(), s.end());
        map[s]++;
    }

    //sort(words.begin(), words.end());
    vector<string> res;

    for (size_t i = 0; i < words.size(); i++)
    {
        string aux = words[i];
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        sort(words[i].begin(), words[i].end());
        if(map[words[i]] == 1){
            res.push_back(aux);
        }
    }

    sort(res.begin(), res.end());

    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    return 0;
}