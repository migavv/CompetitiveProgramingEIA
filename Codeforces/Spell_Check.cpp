#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main(){

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        cin >> s;

        string original = "Timur";

        sort(original.begin(),original.end());

        if (n < 5 || n>5) printf("NO\n");
        else{
            sort(s.begin(), s.end());
            if(s.compare(original) == 0) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}