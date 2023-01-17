#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(){

    while(scanf("%d" "%d", &n, &k) != EOF){
        int res = n, aux = n;
        
        while(aux >= k){
            int leftover = aux%k;
            aux = aux / k;
            res += aux; 
            aux += leftover; 
        }

        printf("%d\n", res);
    }

    return 0;
}