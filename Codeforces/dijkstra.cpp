//
// Created by migav on 7/07/2023.
//

#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int nax = 10e5;
const long long inf = 2e17;

vector<vector<ii>> g;
int p[nax];
long long d[nax];

void dijkstra(int s, int n){
    for(int i = 0; i < n; i++) {d[i] = inf, p[i] = -1;}
    priority_queue <ii, vector <ii>,greater<> > q;
    d[s] = 0;
    q.emplace(0, s);
    int dist, u, v, w;
    while(q.size()){
        tie(dist, u) = q.top();
        q.pop();
        if (dist > (long long)d[u]) continue;
        for (ii e: g[u]) {
            tie(v,w) = e;
            if (d[u] + w < d[v]){
                d[v] = (long long)d[u] + w;
                p[v] = u;
                q.emplace(d[v], v);
            }
        }
    }
}

int main() {
    int v, e, f, t, w;
    scanf("%d %d", &v, &e);
    g.resize(v+3);
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &f, &t, &w);
        g[f].emplace_back(t, w);
        g[t].emplace_back(f, w);
    }
    vi ans;
    dijkstra(1, v + 1);
    if(d[v] == inf) printf("%d", -1);
    else {
        vi path;
        int cur = v;
        while(cur != -1){
            path.push_back(cur);
            cur = p[cur];
        }
        reverse(path.begin(), path.end());
        printf("%d", 1);
        for(int i = 1; i < path.size(); i++)
            printf("% d", path[i]);
    }
    printf("\n");
}