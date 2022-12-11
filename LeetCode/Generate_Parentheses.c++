#include <bits/stdc++.h>

using namespace std;

void generarParentesis(vector<string>& ans, int n, int cerrado, int abierto, string s){

    if(cerrado == n && abierto == n) {
        ans.push_back(s);
        return;
    }

    if(abierto < n) generarParentesis(ans, n, cerrado, abierto + 1, s + "(");
    if(cerrado < abierto) generarParentesis(ans, n, cerrado + 1, abierto, s + ")");
}

vector<string> generateParenthesis(int n) {
    
    vector<string> ans;
    string s = "";
    int cerrado = 0, abierto = 0;

    generarParentesis(ans, n, cerrado, abierto, s);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

}

int main(){
    int n = 3;

    generateParenthesis(n);

}