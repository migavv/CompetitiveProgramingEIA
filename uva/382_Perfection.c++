#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> numeros;
    vector<int> divisores;
    int numero;

    while(scanf("%d", &numero), numero != 0){
        numeros.push_back(numero);
    }

    printf("PERFECTION OUTPUT\n");

    for (size_t i = 0; i < numeros.size(); i++)
    {
        for (size_t j = 1; j < numeros[i]; j++)
        {
            if(numeros[i] % j == 0) divisores.push_back(j);
        }

        int suma = 0;
        for (size_t k = 0; k < divisores.size(); k++)
        {
            suma += divisores[k];
        }

        if(suma == numeros[i]) printf("%5d  " "%s", numeros[i],"PERFECT\n");
        if(suma < numeros[i]) printf("%5d  " "%s", numeros[i],"DEFICIENT\n");
        if(suma > numeros[i]) printf("%5d  " "%s", numeros[i],"ABUNDANT\n");
        
        divisores.clear();
        
    }

    printf("END OF OUTPUT\n");
    

    return 0;
}