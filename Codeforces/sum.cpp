#include <bits/stdc++.h>

using namespace std;

int main(){

    string expresion;
    string nuevaSuma;
    cin >> expresion;

    for (int i = 0; i<expresion.size(); i++){
        if (expresion[i] != '+'){
            nuevaSuma += expresion[i];
        }
    }

    sort(nuevaSuma.begin(), nuevaSuma.end());

    for (int j = 0; j< nuevaSuma.size(); j++){
        if (j == nuevaSuma.size()-1)
            cout << nuevaSuma[j];
        else
            cout << nuevaSuma[j] << "+";
    }
    
}