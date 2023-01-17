#include <bits/stdc++.h>

using namespace std;

int t;

int main(){

    scanf("%d", &t);

    int n, aux;

    while(t--){

        scanf("%d", &n);
        vector<int> prices;

        while(n--){
            scanf("%d", &aux);
            prices.push_back(aux);
        }

        sort(prices.begin(), prices.end());

        int c = 0, sum = 0;

        for (auto l = prices.rbegin(); l != prices.rend(); l++) {

            c++;
            if(c == 3){
                sum += *l;
                c = 0;
            }
        }

        printf("%d\n", sum);
        
    }

    return 0;
}