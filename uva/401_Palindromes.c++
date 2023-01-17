#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    unordered_map<char, char> map1;

    map1.insert({'A', 'A'});
    map1.insert({'H', 'H'});
    map1.insert({'I', 'I'});
    map1.insert({'J', 'L'});
    map1.insert({'L', 'J'});
    map1.insert({'M', 'M'});
    map1.insert({'O', 'O'});
    map1.insert({'T', 'T'});
    map1.insert({'U', 'U'});
    map1.insert({'V', 'V'});
    map1.insert({'W', 'W'});
    map1.insert({'X', 'X'});
    map1.insert({'Y', 'Y'});
    map1.insert({'E', '3'});
    map1.insert({'S', '2'});
    map1.insert({'Z', '5'});
    map1.insert({'1', '1'});
    map1.insert({'8', '8'});
    map1.insert({'2', 'S'});
    map1.insert({'3', 'E'});
    map1.insert({'5', 'Z'});

    while(cin >> s){
        int flag = 1, flagM = 1;

        if((s.length() / 2) % 2 == 0){
            for (size_t i = 0; i <= s.length() / 2; i++)
            {
                if(s[i] != s[s.length() - 1 - i]) flag = 0;
            }    
        }else{
            for (size_t i = 0; i < s.length() / 2; i++)
            {
                if(s[i] != s[s.length() - 1 - i]) flag = 0;
            }
        }

        if(flag){
            string aux = "";
            for (size_t i = 0; i < s.length(); i++)
            {
                if(map1.find(s[i]) != map1.end()) aux += map1[s[i]];
                else flagM = 0;
            }

            if(flagM){
                for (size_t i = 0; i < s.length(); i++)
                {
                    if(s[i] != aux[aux.length() - 1 - i]) flagM = 0;
                }
                
            }
            
        }else{
            string aux = "";
            for (size_t i = 0; i < s.length(); i++)
            {
                if(map1.find(s[i]) != map1.end()) aux += map1[s[i]];
                else flagM = 0;
            }

            if(flagM){
                for (size_t i = 0; i < s.length(); i++)
                {
                    if(s[i] != aux[aux.length() - 1 - i]) {
                        flagM = 0;
                        break;
                    }
                }
                
            }
        }

        cout << s << " -- "; 
        if(flag && flagM) cout << "is a mirrored palindrome." << "\n" << endl;
        else if (!flag && flagM) cout << "is a mirrored string." << "\n" << endl;
        else if (flag && !flagM) cout << "is a regular palindrome." << "\n" << endl;
        else cout << "is not a palindrome." << "\n" << endl;
        
    }

    return 0;
}