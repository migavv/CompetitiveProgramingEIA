//
// Created by migav on 17/10/2022.
//

#include <cstdio>
#include <queue>
#include <cstring>

const int LEFT = 0;
const int RIGHT = 1;

using namespace std;

int main() {
    int c, l, m, size, location, ferry, trips;
    scanf("%d", &c);
    while(c--) {
        queue<int> bank[2];
        scanf("%d %d", &l, &m);
        l *= 100;
        char side[10];
        while(m--) {
            scanf("%d %s", &size, side);
            if(!strcmp(side, "left"))
                bank[LEFT].push(size);
            else
                bank[RIGHT].push(size);
        }
        trips = 0;
        ferry = 0;
        location = LEFT;
        while(!bank[LEFT].empty() || !bank[RIGHT].empty()) {
            while(!bank[location].empty() && ferry + bank[location].front() <= l) {
                ferry += bank[location].front();
                bank[location].pop();
            }
            location ^= 1;
            trips++;
            ferry = 0;
        }
        printf("%d\n", trips);
    }
    return 0;
}