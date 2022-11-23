#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(){
    scanf("%d", &t);

    while(t--){
        string s1, s2;
        int ok = 1;
        
        scanf("%d", &n);

        cin >> s1;
        cin >> s2;

        for(int i = 0; i < n; i++){
            if( (s1[i] == 'R' && s2[i] == 'B') || (s1[i] == 'R' && s2[i] == 'G') || (s2[i] == 'R' && s1[i] == 'B') || (s2[i] == 'R' && s1[i] == 'G') ) ok = 0;
        }

        if(ok) printf("YES\n");
        else printf("NO\n");
        
    }
    return 0;
}