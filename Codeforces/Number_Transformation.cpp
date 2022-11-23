#include <bits/stdc++.h>

using namespace std;

int t, x, y; 

int main(){

    scanf("%d", &t);

    while(t--){
        scanf("%d" "%d", &x, &y);

        if (x > y)
            cout << 0 << " " << 0 << endl;
        else{
            if(y % x == 0){
                int divisor = y/x;
                cout << 1 << " " << divisor << endl;
            }else cout << 0 << " " << 0 << endl;
        } 
    }

    return 0;
}