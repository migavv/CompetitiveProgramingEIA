#include <bits/stdc++.h>

using namespace std;

int main(){

    int cases,number,aux,respuesta;
    cin >> cases;

    while (cases--){
        cin >> number;
        aux =(((((((number*567)/9)+7492)*235)/47)-498)/10)%10;
        respuesta = abs(aux);
        cout << respuesta << endl;
    }
    
}