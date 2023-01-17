#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    unordered_map<char, char> m;
    string res = "";

    m.insert({'B', '1'});
    m.insert({'F', '1'});
    m.insert({'P', '1'});
    m.insert({'V', '1'});
    m.insert({'C', '2'});
    m.insert({'G', '2'});
    m.insert({'J', '2'});
    m.insert({'K', '2'});
    m.insert({'Q', '2'});
    m.insert({'S', '2'});
    m.insert({'X', '2'});
    m.insert({'Z', '2'});
    m.insert({'D', '3'});
    m.insert({'T', '3'});
    m.insert({'L', '4'});
    m.insert({'M', '5'});
    m.insert({'N', '5'});
    m.insert({'R', '6'});

    while(cin >> s){
        for (size_t i = 0; i < s.length(); i++)
        {
            if(i <= s.length() - 2){
                if(m.find(s[i]) != m.end()){
                    if(m.find(s[i+1]) != m.end()){
                        if(m[s[i]] != m[s[i+1]]) res += m[s[i]];
                    }else{
                        res += m[s[i]];
                    }
                }
            }else{
                if(m.find(s[i]) != m.end()){
                    if(m.find(s[i-1]) != m.end()){
                        if(m[s[i]] == m[s[i-1]]) res += m[s[i]];
                        else res += m[s[i]];
                    }else res += m[s[i]];
                }
            }
            
        }

        cout << res << endl;

        res = "";
        
    }
}