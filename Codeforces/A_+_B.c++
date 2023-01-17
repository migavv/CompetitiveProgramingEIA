#include <bits/stdc++.h>
 
using namespace std;

int t;

int main(){
    scanf("%d", &t);

    while(t--){
        string exp, a, b;
        int numa, numb;

        cin >> exp;

        a = exp[0];
        b = exp[2];

        numa = stoi(a);
        numb = stoi(b);

        printf("%d\n", numa + numb);
    }

    return 0;
}