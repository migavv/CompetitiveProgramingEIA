#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;

    while(getline(cin, s)){
    
        stringstream ss(s);

        string Word;
        int count = 0;

        while( ss >> Word){
            count++;
        }

        cout << count << endl;
    }


    return 0;
}