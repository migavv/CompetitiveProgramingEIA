#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    sort(strs.begin(), strs.end());

    string firstWord = strs[0], lastWord = strs[strs.size()-1], res = "";

    for (size_t i = 0; i < firstWord.size(); i++)
    {
        if(firstWord[i] == lastWord[i]) res += firstWord[i];
        else break;
    }

    return res;
    
}

int main(){

    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs);

    return 0;
}