//
// Created by migav on 4/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, res, mini; //m: Matrix size; res: Stores maximum minimum distance from a 1 to a 3;
    // mini: Stores minimum distance from current 1 to a 3

    string input; //Stores rows of input matrix
    vector<vector<int>> field; //Matrix

    //Reading input
    while(cin >> m) {
        res = 0;
        field.assign(m, {});
        for(int i = 0; i < m; i++) {
            cin >> input;
            for(int j = 0; j < m; j++)
                field[i].push_back(input[j] - '0');
        }

        //Check all distances from a 1 to a 3
        for(int i = 0; i < m; i++) { //Calculate
            for(int j = 0; j < m; j++) {
                if(field[i][j] == 1) { //For every 1 in matrix
                    mini = INT_MAX;
                    for(int k = 0; k < m; k++) {
                        for(int l = 0; l < m; l++)
                            if(field[k][l] == 3) //Calculate distance to every 3 and update minimum if necessary
                                mini = min(mini, abs(i - k) + abs(j - l));
                    }
                    res = max(res, mini); //Update maximum minimum distance if necessary
                }
            }
        }
        cout << res << endl; //Output maximum minimum distance
    }
}