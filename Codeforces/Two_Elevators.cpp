#include <bits/stdc++.h>

using namespace std;

int main (){

    int cases, aux, aux2;

    cin >> cases;

    while (cases--)
    {
        int a,b,c;

        cin >> a >> b >> c;

        if (a == 1){
            cout << 1 << endl;
        }else{
            if (b > c){
                aux2 = b-1;
                aux = a-1;
                if (aux2 > aux){
                    cout << 1 << endl;
                }
                else if(aux2 < aux){
                    cout << 2 << endl;
                }
                else{
                    cout << 3 << endl;
                }
            }else{
                aux = c-b + c-1;
                aux2 = a-1;
                if (aux > aux2){
                    cout << 1 << endl;
                }
                else if (aux < aux2){
                    cout << 2 << endl;
                }else{
                    cout << 3 << endl;
                }
            }

        }
    }

    return 0;
}