#include <bits/stdc++.h>

using namespace std;

int cases,n;

int main(){

    scanf("%d", &cases);

    while (cases--)
    {
        scanf("%d", &n);

        int a[n];
        int maximo = 0, ok = 0;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int j = n-1; j >= 0; j--){
            for (int k = n-1; k >= 0 ; k--){
                cout << a[j] << " " << j << " "<< " " << a[k] << " " << k << endl;
                if (__gcd(a[j],a[k]) == 1){
                    cout << "coprime" << a[j] << " " << a[k] << endl;
                    maximo = j+k+2;
                    k = 0;
                    j=0;
                    ok = 1;
                }
                     
            }
        }

        if(ok) printf("%d\n", maximo);
        else printf("%d\n", -1);
    }
    return 0;
}