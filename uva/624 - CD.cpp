//
// Created by migav on 8/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int n, t, track[20], aux[20], best, curr;
//n: Tape capacity; t: number of tapes; track[i] = Duration of track i;
//aux: Current selection of tracks to add to the tape; curr: Current sum of the lengths of the selected tracks;
//best: Sum of the lengths of the best selection of tracks;
vector<int> res; //Best selection of tracks to add to the tape;

void backtrack(int i, int k) { //
    if(curr > n || i >= t)
        return; //If tape capacity exceeded or number of tapes surpassed, return.
    for(int j = i; j < t; j++) { //For every track in tracks array from i to t:
        curr += track[j]; //Update current sum.
        aux[k - 1] = track[j]; //Update current selection of tracks.
        if(curr <= n && curr > best) { //If current sum is closest to n than best, update best sum and best selection.
            res.assign(aux, aux + k);
            best = curr;
        }
        backtrack(j + 1, k + 1); //Recursion to add another track.
        curr -= track[j]; //Undo changes, backtrack.
    }
}

int main() {
    while(cin >> n) {
        best = curr = 0; //Set initial values
        cin >> t;
        //Read input
        for(int i = 0; i < t; i++)
            cin >> track[i];
        backtrack(0, 1);
        //Output results
        for(int d : res) cout << d << " ";
        cout << "sum:" << best << endl;
    }
    return 0;
}