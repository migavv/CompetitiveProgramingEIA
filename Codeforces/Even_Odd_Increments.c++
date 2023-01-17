#include <bits/stdc++.h>

using namespace std;

int t;

int main(){

    scanf("%d", &t);

    while(t--){
        int n, q;
        long long int temp, countE = 0, countO = 0, sum = 0;

        scanf("%d" "%d", &n, &q);

        for (size_t i = 0; i < n; i++)
        {
            scanf("%lld", &temp);
            if(temp % 2 == 0) {
                countE++;
                sum += temp;
            }
            else {
                countO++;
                sum += temp;
            }
        }

        while(q--){
            int op, x;

            scanf("%d" "%d", &op, &x);

            if(op == 0 && (x % 2 != 0)){
                sum += (countE * x);
                countO += countE;
                countE = 0;
            }

            if(op == 0 && (x % 2 == 0)){
                sum += (countE * x);
            }

            if(op == 1 && (x % 2 == 0)){
                sum += (countO * x);
            }

            if(op == 1 && (x % 2 != 0)){
                sum += (countO * x);
                countE += countO;
                countO = 0;
            }

            printf("%lld\n", sum);
            
        }
        
    }

    return 0;
}