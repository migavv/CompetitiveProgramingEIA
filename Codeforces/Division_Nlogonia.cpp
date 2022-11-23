#include <bits/stdc++.h>

using namespace std;

int queries, x,y,a,b;

int main(){

    int ok = 1;

    while (ok)
    {
        scanf("%d", &queries);

        if (queries == 0) ok = 0;

        else{
            scanf("%d" "%d", &x, &y);
            while(queries--){
                scanf("%d" "%d", &a, &b);

                if ((x == a && b == y) || x == a || b == y) printf("divisa\n");

                else if (a < x && b > y) printf("NO\n");

                else if(a < x && b < y) printf("SO\n");

                else if(a > x && b > y) printf("NE\n");

                else printf("SE\n");
            }
        } 
    
    }
}