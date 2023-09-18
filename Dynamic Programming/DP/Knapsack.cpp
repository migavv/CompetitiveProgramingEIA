//
// Created by migav on 3/07/2023.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000; //Max number of elements
const int MAX_W = 40; //Max possible knapsack size

//Particular test case:
int V[] {100, 70, 50, 10}; //Value of each item
int W[] {10, 4, 6, 12}; //Weight of each item
int N = 4, S = 12; //n: Number of items; S: Knapsack capacity

int C[MAX_N][MAX_W];
int main() {
    for (int i = 0; i <= N;  ++i) C[i][0] = 0;
    for (int w = 0; w <= S; ++w) C[0][w] = 0;
    for (int i = 1; i <= N; ++i)
        for (int w = 1; w <= S; ++w) {
            if (W[i] > w) C[i][w] = C[i-1][w];
            else          C[i][w] = max(C[i-1][w], V[i] + C[i-1][w-W[i]]);
        }
    int ans = C[N][S];
    printf("%d\n", ans);
    return 0;
}


int memo[MAX_N][MAX_W]; //Memoization table

int val(int id, int remW) { //id: Index of current item; remW: Remaining knapsack capacity
    if(!remW || id == n) return 0; //If knapsack is full or all items checked
    int &ans = memo[id][remW];
    if(ans != -1) return ans; //If current state was already solved before
    if(W[id] > remW) return ans = val(id + 1, remW); //If current item doesn't fit
    return ans = max(val(id + 1, remW), V[id] + val(id + 1, remW - W[id]));//Choosing between ignoring item or storing it
}

int main() {
    memset(memo, -1, sizeof memo); //Setting memo table empty (-1)
    cout << val(0, S);
}


