//
// Created by migav on 12/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vii;

vii graph;
int n, k, best, black, white[101], aux[101], res[101];
//n: Number of nodes; k: Number of edges;
//best: Highest number of colored nodes; black: Current number of colored nodes;
//white: white[i] = 2 means that there are two black nodes adjacent to node i;
//aux: Current black nodes; res: Longest possible selection of black nodes.

void backtrack(int v, int i) { //v: Current node; i: Index for next black node in aux[];
    if(v > n) { //If al nodes painted
        if(black > best) { //Update best results if necessary
            best = black;
            copy(aux, aux + best, res);
        }
        return;
    }
    if(!white[v]) { //If v node is not white, i.e, if there are no black nodes adjacent to v, paint v to black:
        black++; //Update black nodes counter
        aux[i] = v; //Add v to current black nodes array

        //Update every node adjacent to v in white array:
        for(int j : graph[v])
            white[j]++;

        backtrack(v + 1, i + 1); //Go to next node.

        //Bring node back to white, backtrack:
        black--;
        for(int j : graph[v])
            white[j]--;
    }
    backtrack(v + 1, i); //Go to next node, without coloring current to black
}


int main() {
    int m, n1, n2; //m: Number of test cases; n1 & n2: Aux vars to store input nodes.
    cin >> m;
    while(m--) {
        //Set initial variables:
        best = black = 0;
        memset(white, 0, sizeof white);

        //Build graph:
        cin >> n >> k;
        graph.assign(n + 1, {});
        for(int i = 0; i < k; i++) {
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        //Solve:
        backtrack(1, 0);

        //Output solutions:
        cout << best << endl;
        cout << res[0];
        for(int i = 1; i < best; i++) cout << " " << res[i];
        cout << endl;
    }
}