#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    int t = 1;

    while(getline(cin,s) && s != "DONE"){
        string aux = "";

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (size_t i = 0; i < s.size(); i++)
        {
            if(isalpha(s[i])) aux += s[i];
        }
        
        string original = aux;

        reverse(aux.begin(), aux.end());

        if(original == aux) printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
        
    }

    return 0;
}