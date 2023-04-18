//
// Created by migav on 11/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, spaces[16], pieces[15][2];
//n: Number of spaces; m: Number of pieces available;
// spaces: Array storing placed pieces; pieces: Stores available pieces;

int taken; //Bitmask to keep track of already placed pieces
bool possible; //If a solution was found, possible = true;

bool playable(int p, int i) {
    //If piece i (pieces[i]) is playable at space p, return true
    return spaces[p - 1] == pieces[i][0] || spaces[p - 1] == pieces[i][1];
}

void backtrack(int p) {
    if (possible) return; //If a solution was already found, return.
    if(p > n) { //If all spaces were filled
        //Set possible to true if last placed piece matches with the final one:
        possible = spaces[n] == spaces[n + 1];
        return;
    }
    //Looking playable pieces for position p:
    for(int i = 0; i < m; i++) { //For every piece
        if(!(taken & (1 << i)) && playable(p, i)) { //If piece 'i' is playable:
            taken |= 1 << i; //Set piece i as taken.

            //Place piece in space:
            if(pieces[i][0] == spaces[p - 1])
                spaces[p] = pieces[i][1];
            else spaces[p] = pieces[i][0];

            backtrack(p + 1); //Place next piece
            taken &= ~(1 << i); //Set piece back to unplaced, backtrack.
        }
    }
}

int main() {
    int input;
    while(cin >> n, n) {
        //Setting initial values:
        taken = 0;
        possible = false;

        //Reading input:
        cin >> m;
        cin >> input >> spaces[0];
        cin >> spaces[n+1] >> input;
        for(int i = 0; i < m; i++)
            cin >> pieces[i][0] >> pieces[i][1];

        //Solving:
        backtrack(1);

        //Printing result
        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }
}