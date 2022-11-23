#include <bits/stdc++.h>

using namespace std;

int main(){
    int numcities;

    scanf("%d", &numcities);

    int ciudades[numcities];
    int minimo = INT_MAX;
    int ind = 1;

    for (int i = 0; i < numcities; i++){
        int num;
        cin >> num;
        ciudades[i] = num;
        if (num < minimo){
            minimo = num;
            ind = i+1;
        }

    }

    sort(ciudades, ciudades + numcities);

    if (ciudades[0] == ciudades[1]){
        printf("Still Rozdil");
    }else
        cout << ind;

}