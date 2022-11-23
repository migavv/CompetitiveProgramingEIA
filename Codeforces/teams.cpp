#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);

    int count = 0;

    while(n){
        int a,b,c;

        scanf("%d %d %d", &a, &b, &c);

        if ((a ==1 && b ==1 ) || (b == 1 && c==1) || (a == 1 && c==1))
            count+=1;

        n--;
    }
    printf("%d", count);

    return 0;
}