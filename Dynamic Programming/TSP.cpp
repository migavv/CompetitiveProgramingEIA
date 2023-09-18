//
// Created by migav on 22/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

//Particular testcase:
int n = 4; //Number of cities
int dist[4][4] = { //Matrix of distances
        {0,20,42,35},
        {20,0,30,34},
        {42,30,0,12},
        {35,34,12,0}
};

int dp[4][16];

int tsp(int i, int v) {
    if(v == (1<<n) - 1) //If all cities already visited
        return dist[i][0]; //Return to start
    int &ans = dp[i][v]; //Memoization
    if(ans != -1) return ans;
    //Calculate best next city:
    ans = inf;
    for(int j = 0; j < n; j++) {
        if(!(v & 1<<j)) //If j has not been visited
            ans = min(ans, dist[i][j] + tsp(j, v | 1<<j));
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cout << tsp(0, 1); //First city is already visited
}