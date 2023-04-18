//
// Created by migav on 5/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, population[5][5], n, r, c, p, minSum, sum, dist[5], res[5];
    //t: Test cases; population: population[i][j] = number of people (in thousands) living in zone of coordinates i,j;
    //n: Number of populated zones; r: Coordinate 'y' of populated zone; c: Coordinate 'x' of populated zone; p: Population of populated zone.
    //minSum: Weighted sum of distances from every populated zone to each office for best configuration;
    //min: Weighted sum of distances from every populated zone to each office for current configuration;
    //dist: Stores distances from current zone to each 5 offices; res: Stores the best locations for every office;

    //Stores coordinates of each area:
    pair<int, int> areas[25];
    int area = 0;
    for(int x = 0; x < 5; x++)
        for(int y = 0; y < 5; y++)
            areas[area++] = {x, y};

    cin >> t;
    while(t--) {
        memset(population, 0, sizeof population);

        //Reading population matrix from input
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> r >> c >> p;
            population[r][c] = p;
        }

        //Complete Search through all possible ways of locating the 5 offices
        minSum = INT_MAX;
        for(int i = 0; i <= 20; i++) { //i: Position of office #1
            for(int j = i + 1; j <= 21; j++) { //j: Position of office #2
                for(int k = j + 1; k <= 22; k++) { //k: Position of office #3
                    for(int l = k + 1; l <= 23; l++) { //l: Position of office #4
                        for(int m = l + 1; m <= 24; m++) { //m: Position of office #5
                            sum = 0;
                            //Iterate through matrix calculating distances from every [x][y] to each office
                            for(int x = 0; x < 5; x++) {
                                for(int y = 0; y < 5; y++) {
                                    if(population[x][y]) {
                                        //Manhattan distances
                                        dist[0] = abs(areas[i].first - x) + abs(areas[i].second - y);
                                        dist[1] = abs(areas[j].first - x) + abs(areas[j].second - y);
                                        dist[2] = abs(areas[k].first - x) + abs(areas[k].second - y);
                                        dist[3] = abs(areas[l].first - x) + abs(areas[l].second - y);
                                        dist[4] = abs(areas[m].first - x) + abs(areas[m].second - y);
                                        //Add weighted (minimum) distance to current sum:
                                        sum += *min_element(dist, dist + 5) * population[x][y];
                                    }
                                }
                            }
                            //Update answer:
                            if(sum < minSum) {
                                res[0] = i;
                                res[1] = j;
                                res[2] = k;
                                res[3] = l;
                                res[4] = m;
                                minSum = sum;
                            }
                        }
                    }
                }
            }
        }
        //Output results:
        for(int i = 0; i < 5; i++) {
            cout << res[i];
            if(i != 4) cout << " ";
        }
        cout << endl;
    }
}