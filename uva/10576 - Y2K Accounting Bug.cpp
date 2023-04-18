//
// Created by migav on 8/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int s, d, months[13], best, sum;

void backtrack(int month) {
    //If the 5 consecutive months reports shows surplus, return:
    if(month > 5 && accumulate(months + month - 5, months + month, 0) > 0)
        return;
    //If a possible configuration was found, update results:
    if(month > 12) {
        best = max(best, sum);
        return;
    }
    //Check surplus possibility for current month:
    sum += s; months[month] = s;
    backtrack(month + 1);
    sum -= s + d; months[month] = -d;//Backtrack
    //Check deficit possibility for current month:
    backtrack(month + 1);
    sum += d;//Backtrack
}

int main() {
    while(cin >> s >> d) { //Read input
        best = INT_MIN;
        sum = 0;
        backtrack(1);
        //Output results:
        if(best > 0) cout << best;
        else cout << "Deficit";
        cout << endl;
    }
}