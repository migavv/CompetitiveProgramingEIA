#include <bits/stdc++.h>

using namespace std;

int cases, a, b;

int main(){

    scanf("%d", &cases);

    while (cases--)
    {
        scanf("%d" "%d", &a, &b);

        if (a < b) printf("%c\n", '<');

        else if (a > b) printf("%c\n", '>');

        else printf("%c\n", '=');
    }
    
}