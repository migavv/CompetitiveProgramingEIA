#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(){

    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);

        if (n == 1){
            int number;
            scanf("%d", &number);
            printf("YES\n");
        }

        else{
            int a[n];
            int ok = 1;

            for(int i = 0; i < n; i++){
                cin >> a[i];
            }

            sort(a, a+n);

            for (size_t j = 0; j < n-1; j++)
            {
                if(a[j] == a[j+1]){
                    ok = 0;
                    break;
                }
            }

            if(ok) printf("YES\n");
            else printf("NO\n");
            
        }
    }
    return 0;
}

