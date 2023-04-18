//
// Created by migav on 13/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

//Representation of numbers from 0 to 9 with the LEDs
string nums[10] {"YYYYYYN", "NYYNNNN", "YYNYYNY","YYYYNNY", "NYYNNYY",
                 "YNYYNYY","YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY" },

seq[10]; //Stores given sequence of LEDs states.
bitset<10> burned; //To keep track of burned LEDs.
bool match; //True if a matching countdown was found.
int t; //Size of the given sequence

void backtrack(int i, int val) { //i: Index of the current state of the LEDs; val: Value to match with seqs[i].
    if(i == t) { //If a match was found for every number in the sequence, set match to true;
        match = true;
        return;
    }
    string &curr = seq[i]; //Get current state of the LEDs as curr.
    string &num = nums[val]; //Get value to match with curr as num.
    for(int j = 0; j < 7; j++) {
        if(burned[j] && curr[j] == 'Y') return; //If current state has LED j on, and it should be burned, doesn't match.
        if(curr[j] == 'Y' && num[j] == 'N') return; //If current state has LED j and num has it off, doesn't match.
        if(num[j] == 'Y' && curr[j] == 'N') burned[j] = true; //If num has LED j on, and current state doesn't, j must is burned.
    }
    backtrack(i + 1, val - 1); //Check if next state and next val in countdown match.
}

int main() {
    while(cin >> t, t) {
        //Read input
        for(int i = 0; i < t; i++)
            cin >> seq[i];

        //Set initial state
        match = false;

        //Try to solve for every possible countdown of t numbers
        for(int val = 9; val >= t - 1 && !match; val--) {
            burned.reset();
            backtrack(0, val);
        }

        //Output results
        cout << (match ? "MATCH" : "MISMATCH") << endl;
    }
}

