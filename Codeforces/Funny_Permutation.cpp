#include <bits/stdc++.h>

using namespace std;

int cases, n;

int main(){

    scanf("%d", &cases);

    while (cases--){

        scanf("%d", &n);

        if(n == 3) printf("%d\n", -1);

        else if (n%2){
            int aux = (n+1)/2;

            for(int i = n; i > aux;i--){
                cout << i << " ";
            }

            for(int j = 1; j <= aux; j++){
                cout << j << " ";
            }
            cout << endl;
        }
        else{
            for(int k = n; k > 0 ; k--){
                cout << k << " ";
            }
            cout << endl;
        }

    }

    return 0;

}