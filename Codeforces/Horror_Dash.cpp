#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases,c=1;

    scanf("%d", &cases);

    while(cases--){
        int students,maximaS = 0;
        cin >> students;
        int speed;
        for (int i = 0; i < students;i++){
            cin >> speed;
            maximaS = max(speed,maximaS);
        }

        printf("Case %d: %d\n", c++, maximaS);
    }
}