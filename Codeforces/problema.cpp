#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int cases;
    unsigned long long a, b, raiz1, raiz2, superior, inferior, count;


    cin >> cases;

    while(cases--){
        cin >> a >> b;
        count = 0;
        raiz1 = sqrt(a);
        raiz2 = sqrt(b);
        size_t i = pow(raiz2, 2);
        while(i < b) {
            count++;
            i += raiz2;
        }
        raiz2--;
        count += raiz2 * 3;
        inferior = pow(raiz1, 2);
        size_t j = inferior;
        while(j < a) {
            count--;
            j += raiz1; 
        }
        cout << count << endl;
    }
}