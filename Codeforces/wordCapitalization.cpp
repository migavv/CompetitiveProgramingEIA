#include <bits/stdc++.h>

using namespace std;

int main(){

    string word;
    string capitalize;

    cin >> word;

    if (isupper(word[0])){
        cout << word;
    }
    else{
        char ch = toupper(word[0]);
        capitalize += ch;
        for (int i = 1; i < word.size(); i++){
            capitalize+=word[i];
        }
    }

    cout << capitalize;
}