//
// Created by migav on 7/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int v, e, cost[100003];
vector<vi> graph;
bitset<100005> visited;

int dfs(int n) {
    visited[n] = true;
    int res = cost[n];
    for(int i = 0; i < graph[n].size(); i++) {
        if(!visited[graph[n][i]])
            res = min(res, dfs(graph[n][i]));
    }
    return res;
}

int main() {
    int f, t;
    cin >> v >> e;
    graph.assign(v + 1, {});
    for(int i = 1; i <= v; i++)
        cin >> cost[i];
    for(int i = 0; i < e; i++) {
        cin >> f >> t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
    long long res = 0;
    for(int i = 1; i <= v; i++) {
        if(!visited[i])
            res += dfs(i);
    }
    cout << res;
}