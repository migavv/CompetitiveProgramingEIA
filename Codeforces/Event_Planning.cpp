#include <bits/stdc++.h>

using namespace std;


int main(){

    int participants, budget, hotels,total, weeks;
    int pricePerson, minimo;

    while (scanf("%d" "%d" "%d" "%d", &participants, &budget, &hotels, &weeks) != EOF)
    {
        minimo = 2000000000;
        while(hotels--){

            int bedWeek[weeks];

            scanf("%d", &pricePerson);
            for (int i = 0; i < weeks; i++){
                cin >> bedWeek[i];
                if (bedWeek[i] >= participants){
                    total =  participants*pricePerson;
                    if (total <= budget){
                        minimo = min(minimo, total);
                    }
                }
            }
                
        }

        if (minimo != 2000000000) printf("%d\n", minimo); 
        else printf("stay home\n");
    }
    return 0;
}