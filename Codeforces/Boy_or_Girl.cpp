#include <bits/stdc++.h>

using namespace std;

int main(){

    string username;

    cin >> username;

    sort(username.begin(), username.end());

    char actual = username[0];
    int count = 1;

    for (int k = 1; k < username.size(); k++){
        if (actual != username[k]){
            actual = username[k];
            count += 1;
        }
    }

    if (count % 2 == 0){
        cout << "CHAT WITH HER!";
    }else{
        cout << "IGNORE HIM!";
    }
    
}
