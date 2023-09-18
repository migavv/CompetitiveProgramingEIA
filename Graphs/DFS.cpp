//
// Created by migav on 23/07/2023.
//

#include<bits/stdc++.h>

#define VISITED 1
#define UNVISITED 0

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> graph;
vi dfs_num;

void dfs(int i) {
    dfs_num[i] = VISITED;
    for(auto curr : graph[i]) {
        if(dfs_num[curr.first] == UNVISITED)
            dfs(curr.first);
    }
}
