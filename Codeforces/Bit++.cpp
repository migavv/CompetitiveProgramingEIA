#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    scanf("%d", &n);

    int x = 0;

    while(n--){

        char expresion[4];

        scanf("%s", &expresion);
        if (!strcmp(expresion,"X++") || !strcmp(expresion,"++X")){
            x +=1;
        }
        else if(!strcmp(expresion,"X--") || !strcmp(expresion,"--X")){
            x -=1;
        }

    }

    printf("%d", x);

    return 0;
}