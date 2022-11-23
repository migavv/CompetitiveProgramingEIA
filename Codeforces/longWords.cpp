#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);

    while(n--){
        string palabra;
        string abreviacion;

        cin >> palabra;

        if (palabra.size() > 10){
            int last = palabra.size() - 1;

            abreviacion = palabra[0] + to_string(palabra.size()-2) + palabra[last];

            cout << abreviacion << endl;

        }else{
            cout << palabra << endl;
        }
    }

    return 0;
}