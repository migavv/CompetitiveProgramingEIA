#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){

    while (cin >> n >> s)
    {
        //Creación variables útiles para resolver el problema.
        map<string, int> map;
        string str = "", pass;
        int count = 0, mayor = 0;

        // Bucle en el cual se hace la partición de las palabras.
        // Voy a hacer que el ciclo while vaya hasta el size -3 de la palabra por caracerística del problema general.
        while(count <= s.size()-n){
            //Cada que reinicia el while entra al for y construye el sustring de 3 letras.
            for (size_t i = count; i < (n+count); i++)
            {
                str += s[i];
            }

            //Reiniciamos variables para siguente ciclo
            map[str]++;
            str = "";
            count++;
        }

        for (auto i = map.begin(); i != map.end(); i++){

            //cout << i ->first << " " << i->second << endl;
            if(i->second >= mayor) {
                mayor = i->second;
                pass = i->first;
            }
        }

        //Impresión resultado (Esto sí debe estar en el código final)
        cout << pass << endl;

        //Limpiamos el map para un próximo TC.
        map.clear();
        
    }

    return 0;
}