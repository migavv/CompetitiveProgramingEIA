//
// Created by migav on 4/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

set<int> scores; //Will store all possible scores avoiding repetition

int main() {
    int score, perms, combs; //score: Initial Score; perms: Permutation counter; combs: Combination counter;

    for(int i = 0; i <= 20; i++) //Inserting all possible scores into "scores" set.
        scores.insert({i, i*2, i*3});
    scores.insert(50);

    vector<int> range(scores.begin(), scores.end()); //Copying scores to vector

    while(cin >> score, score > 0) { //Reading input
        perms = combs = 0;

        //Complete search. Iterate through all permutations
        for(int i = 0; i < range.size(); i++) {
            for(int j = 0; j < range.size(); j++) {
                for(int k = 0; k < range.size(); k++) {
                    if(!(score - range[i] - range[j] - range[k])) { //If score gets to 0 with current permutation
                        perms++; //Update permutation
                        if(i <= j && j <= k) combs++; //If indexes are ordered update combinations
                    }
                }
            }
        }

        //Output results
        if(!combs)
            cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS.\n";
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << combs << ".\n"
                 << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << perms << ".\n";
        }
        for(int i = 0; i < 70; i++) cout << "*";
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
}