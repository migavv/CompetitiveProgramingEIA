#include <bits/stdc++.h>

using namespace std;

string reverseVowels(string s) {

    unordered_set <char> vocales;

    vocales.insert('A');
    vocales.insert('a');
    vocales.insert('E');
    vocales.insert('e');
    vocales.insert('I');
    vocales.insert('i');
    vocales.insert('O');
    vocales.insert('o');
    vocales.insert('u');
    vocales.insert('U');

    int j = s.length()-1, i = 0;
    char aux;

    while(i < j){
        
        if (vocales.find(s[j]) == vocales.end()){
            j--;
        }

        if (/* Voy a buscar algo*/ vocales.find(s[i]) == vocales.end() /* No encontrado */){
            i++;
        }

        if((vocales.find(s[i]) != vocales.end()) && (vocales.find(s[j]) != vocales.end())){
            swap(s[i], s[j]);
            /*aux = s[i];
            s[i] = s[j];
            s[j] = aux;*/
            j--;
            i++;
        }
        
    }

    return s;

}

int main(){
    string s = "Egad! Loretta has Adams as mad as a hatter. Old age!";

    cout << reverseVowels(s);

    return 0;

}