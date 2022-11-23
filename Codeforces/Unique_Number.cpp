#include <bits/stdc++.h>

using namespace std;

int t,n;

int main(){

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        if(n > 45) printf("%d\n", -1);
        else{
            if (n <= 9) printf("%d\n", n);
            else{
                string str;
                int i = 9;
                while (n > 0){
                    n -= i;
                    str.append(to_string(i));
                    if(n < 9 && i > n){
                        str.append(to_string(n));
                        break;
                    }
                    i--;
                }
                reverse(str.begin(),str.end());
                cout << str << endl;
            }
        }
    }
    return 0;
}