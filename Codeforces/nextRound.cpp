#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int k;

    scanf("%d %d", &n, &k);

    int numeros[n];
    int count = 0;

    for(int i=0; i<n; i++)
        scanf("%d", &numeros[i]);

    for (int j = 0; j<n; j++){
        if (numeros[j] > 0 && numeros[j] >= numeros[k-1]){
            count++;
        }
    }

    printf("%d", count);

    return 0;
}