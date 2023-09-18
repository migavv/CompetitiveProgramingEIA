//
// Created by migav on 3/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, color[100003]; bool visited[100003];
vector<vi> graph;

int dfs(int i, bool isBlack) {
    visited[i] = true;
    int children = 0;
    int sum = 0;
    for(int j = 0; j < graph[i].size(); j++) {
        if(!visited[graph[i][j]]) {
            children++;
            sum += dfs(graph[i][j], !isBlack);
        }
    }
    if(isBlack) {
        color[i] = 1;
        return sum;
    }
    else {
        color[i] = 0;
        return sum + children;
    }
}

int main() {
    int u, v, black, white; long long res = 0;
    cin >> n;
    graph.assign(n+1, {});
    while(cin >> u >> v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    color[1] = 1;
    black = dfs(1, true) + 1;
    white = n - black;
    memset(visited, 0, sizeof visited);
    for(int i = 1; i <= n; i++) {
        visited[i] = true;
        if(color[i]) {
            res += white;
            black--;
        }
        else {
            res += black;
            white--;
        }
        for(int j = 0; j < graph[i].size(); j++)
            if(!visited[graph[i][j]])
                res--;
    }
    cout << res;
}