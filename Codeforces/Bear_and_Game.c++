#include <bits/stdc++.h>
 
using namespace std;

int n;

int main(){

    scanf("%d", &n);

    int temp, aux = 0, minutes = 0, flag = 1;

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &temp);

        if(temp - aux > 15) {
            minutes += 15;
            flag=0;
            break;
        }else{
            minutes = minutes + (temp - aux);
            aux = temp;
        }
    }

    if(flag){
        if(90-temp > 15){
            minutes += 15;
        }else{
            minutes = minutes + (90 - temp);
        }
        
    }
    
    printf("%d\n", minutes);

    return 0;
}