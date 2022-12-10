#include <bits/stdc++.h>

using namespace std;

int t,n;
int main(){
    //Number of test cases.
    scanf("%d", &t);

    while(t--){
        int max, second;
        //length of the array.
        scanf("%d", &n);

        vector<int> s(n);

        //Rellenar el vector con los datos proporcionados y determinar mayor y segundo.
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }

        vector<int> b(n);
        sort(b.begin(), b.end());

        //Hacer las restas respectivas
        for (int j = 0; j < n; j++){
            if (s[j] != b[n-1]) s[j] = s[j] - b[n-1];
            else s[j] = s[j] - b[n-2];
        }

        //Imprimir nuevo vector
        for (int k = 0; k < n; k++){
            cout << s[k] << " ";
        }

        cout << endl;

    }

    return 0;
}