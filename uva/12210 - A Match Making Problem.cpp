//
// Created by migav on 22/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int b, s, young, age, c = 1; //young: Will store the youngest bachelor.
    while(cin >> b >> s, b || s) {
        /*We only need to find the youngest bachelor as the ones left will be the youngest
        and the problem only asks for the age of the youngest bachelor left*/

        //Searching for the youngest bachelor while reading input:
        young = INT_MAX;
        int i = b; while(i--) {
            cin >> age;
            young = min(young, age);
        }

        //Reading ages of spinsters (not relevant for current solution)
        i = s; while(i--) cin >> age;

        //Output:
        cout << "Case " << c++ << ": ";
        if(b <= s) cout << 0; //If the number of spinsters is greater or equal than the number of bachelors, no bachelor will be left.
        else cout << b - s << " " << young; //Else the number of bachelors left will be b - s.
        cout << endl;
    }
}