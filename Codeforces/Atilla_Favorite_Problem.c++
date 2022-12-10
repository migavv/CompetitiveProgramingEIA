#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main(){
    //Número de test cases.
    scanf("%d", &t);

    while(t--){
        int max = 0;
        map<char, int> abc;
        abc['a'] = 1;
        abc['b'] = 2;
        abc['c'] = 3;
        abc['d'] = 4;
        abc['e'] = 5;
        abc['f'] = 6;
        abc['g'] = 7;
        abc['h'] = 8;
        abc['i'] = 9;
        abc['j'] = 10;
        abc['k'] = 11;
        abc['l'] = 12;
        abc['m'] = 13;
        abc['n'] = 14;
        abc['o'] = 15;
        abc['p'] = 16;
        abc['q'] = 17;
        abc['r'] = 18;
        abc['s'] = 19;
        abc['t'] = 20;
        abc['u'] = 21;
        abc['v'] = 22;
        abc['w'] = 23;
        abc['x'] = 24;
        abc['y'] = 25;
        abc['z'] = 26;

        //Longitud del string
        scanf("%d", &n);
        // Se recibe el string
        cin >> s;

        for (int i = 0; i < n; i++){
            if(abc[s[i]] > max) max = abc[s[i]];
        }

        printf("%d\n", max);
        max=0;

    }

    return 0;
}