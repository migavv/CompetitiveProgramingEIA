#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res = {};
    unordered_map<char, int> pCount;
    unordered_map<char, int> sCount;

    if (p.size() > s.size()) return res;

    for (int i = 0; i < p.length(); i++){
        if(!pCount[p[i]]){
            pCount[p[i]]++;
        }else pCount[p[i]]++;

        if(!sCount[s[i]]){
            sCount[s[i]]++;
        }else sCount[s[i]]++;
    }

    if (pCount == sCount) res.push_back(0);

    /*for(auto it=sCount.begin();it!=sCount.end();it++) {
        cout << it->first << " " << it->second; 
    }*/

    int j = 0, n = p.length();

    for (int i = n; i < s.length(); i++){
        if(!sCount[s[i]]){
            sCount[s[i]]++;
        }else sCount[s[i]]++;

        sCount[s[j]]--;

        if (sCount[s[j]] == 0) sCount.erase(s[j]);

        j++;

        if (pCount == sCount) res.push_back(j);

    }

    /*for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }*/
    return res;

}

int main(){
    string s = "abab", p = "ab";

    findAnagrams(s, p);

    return 0;
}