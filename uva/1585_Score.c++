#include <bits/stdc++.h>

using namespace std;

int tc;
string s;

int main(){

    scanf("%d", &tc);
    while(tc--){
        cin >> s;

        int count = 0, res = 0, aux = 1;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'O'){
                count = count + aux;
                aux++;
            }else{
                res += count;
                count = 0;
                aux = 1;
            }
        }
        res += count;

        printf("%d\n", res);
    }

    return 0;
}