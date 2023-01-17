#include <bits/stdc++.h>

using namespace std;

int t;

int main(){

    scanf("%d", &t);

    while(t--){
        string answer = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
        string word;

        cin >> word;
        
        if (answer.find(word) != string::npos) printf("YES\n");
        else printf("NO\n");

    }

}
