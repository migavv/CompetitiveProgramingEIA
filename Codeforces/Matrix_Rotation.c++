#include <bits/stdc++.h>

using namespace std;

int t;

int main(){

    scanf("%d", &t);

    while(t--){
        vector<int> numbers;
        int num1, num2, num3, num4;

        scanf("%d" "%d" "%d" "%d", &num1, &num2, &num3, &num4);

        numbers.push_back(num1);
        numbers.push_back(num2);
        numbers.push_back(num3);
        numbers.push_back(num4);

        int i = 0, temp, temp2, flag = 0;

        while (i < 4)
        {
            if((numbers[0] < numbers[1] && numbers[0] < numbers[2]) && numbers[1] < numbers [3]){
                if(numbers[2] < numbers[3]){
                    flag = 1;
                    break;
                }
            }
            
            temp = numbers[0];
            numbers[0] = numbers[2];
            temp2 = numbers[1];
            numbers[1] = temp;
            temp = numbers[3];
            numbers[3] = temp2;
            numbers[2] = temp;

            i++;
        }
        
        if(flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}