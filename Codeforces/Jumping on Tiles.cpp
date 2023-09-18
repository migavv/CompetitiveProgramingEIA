//
// Created by migav on 2/08/2023.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    string word;
    int t; cin >> t;
    while(t--) {
        cin >> word;
        multimap<char, int> path;
        char l = min(word[0], word[word.length()-1]);
        char r = max(word[0], word[word.length()-1]);
        for(int i = 1; i < word.size()-1; i++) {
            if(l <= word[i] && word[i] <= r)
                path.insert({word[i], i});
        }
        cout << abs(l-r) << " " << path.size() + 2 << endl;
        cout << 1;
        if(l == word[0]) {
            for(auto curr : path)
                cout << " " << curr.second+1;
        } else {
            for(auto it = path.rbegin(); it != path.rend(); it++)
                cout << " " << it -> second+1;
        }
        cout << " " << word.length();
        cout << endl;
    }
}