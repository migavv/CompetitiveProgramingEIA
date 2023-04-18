//
// Created by migav on 16/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

char grid1[6][6], grid2[6][6], password[6]; //password: Stores possible password
int k, res; //k: Problem asks to find the kth possible password; res: Counter of number of possible passwords found.
//

unordered_set<string> found; //Will keep track of possible answers found to avoid counting repeated ones.

//Aux method that sorts columns of a matrix
void sortCols(char grid[][6]) {
    char aux[6];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 6; j++)
            aux[j] = grid[j][i];
        sort(aux, aux + 6);
        for(int j = 0; j < 6; j++)
            grid[j][i] = aux[j];
    }
}

//Aux method that checks if some character s exists in column col of grid #2
bool match(char s, int col) {
    return any_of(grid2, grid2 + 6, [&s, &col](const char*  row){
        return s == row[col];
    });
}

void backtrack(int col) { //col: Current column
    if(res == k) return; //If kth possible password has already been found, return.
    if(col == 5) { //Check if a possible password was found.
        if(found.find(password) == found.end()) { //Check if the possible password wasn't found before.
            if(++res == k) cout << password << endl; //Check if it is the kth possible password
            found.insert(string(password)); //Insert the password into the found set
        }
        return;
    }
    //Iterate thorough col in grid 1 and 2 searching for a match
    for(auto & row : grid1) {
        if(match(row[col], col)) { //If a match is found:
            password[col] = row[col]; //Add char to the password
            backtrack(col + 1); //Search the next character of the password
        }
    }
}

int main() {
    int t; //Test cases
    cin >> t;
    while(t--) {
        //Setting initial values:
        res = 0;
        found.clear();

        //Building grids form input:
        cin >> k;
        for(auto & i : grid1)
            cin >> i;
        for(auto & i : grid2)
            cin >> i;
        //Columns are sorted in order to get possible passwords ordered lexicographically.
        sortCols(grid1);
        sortCols(grid2);

        //Solving:
        backtrack(0);

        //Printing results:
        if(res < k) cout << "NO" << endl;
    }
}