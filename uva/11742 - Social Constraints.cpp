
#include <bits/stdc++.h>

using namespace std;

struct constraint {  //struct used for storing each constraint
    int a = 0, b = 0, c = 0;
};

int main() {
    int n, m, res; //n: number of friends; m: number of constraints
    while(cin >> n >> m, n || m) {
        int friends[8]; //Maximum number of friends = 8
        for(int i = 0; i < n; i++) friends[i] = i;
        constraint constraints[20]; //Maximum number of constraints = 20
        for(int i = 0; i < m; i++)
            cin >> constraints[i].a >> constraints[i].b >> constraints[i].c; //Reading and storing constraints
        res = 0; //Possible arrangements counter
        do {
            //Check if arrangement is valid
            bool correct = true;
            for(int i = 0; i < m; i++) {
                auto p1 = find(friends, friends + n, constraints[i].a);
                auto p2 = find(friends, friends + n, constraints[i].b);
                if(constraints[i].c > 0) correct = abs(distance(p1, p2)) <= constraints[i].c;
                else correct = abs(distance(p1, p2)) >= -constraints[i].c;
                if(!correct) break;
            }
            if(correct) res++;
        } while(next_permutation(friends, friends + n)); //For every possible arrangement
        cout << res << endl;
    }
}