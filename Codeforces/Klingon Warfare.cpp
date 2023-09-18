//
// Created by migav on 13/08/2023.
//

#include <bits/stdc++.h>

using namespace std;


struct node {
    char fs;
    vector<node*> child;
    int s, e;
};

node *nodes1[10005], *nodes2[10005];

void add_warrior(char fs, int num, int leader, int clan) {
    node *warrior = new node;
    warrior -> fs = fs;
    if(clan == 1) {
        nodes1[leader] -> child.push_back(warrior);
        nodes1[num] = warrior;
    }
    else {
        nodes2[leader] -> child.push_back(warrior);
        nodes2[num] = warrior;
    }
}

int idx;

string flatten(node *n) {
    string clan;
    clan += '[';
    clan += n -> fs;
    n -> s = idx;
    idx += 2;
    for(node *c : n->child)
        clan += flatten(c);
    clan += n -> fs;
    clan += ']';
    n -> e = ++idx;
    n -> e = idx++;
    return clan;
}

int main() {
    int t, m, n, s;
    char f;
    long long p[50005], h1[50005], h2[50005], pr = 1e9 + 9;
    p[0] = 1;
    for(int i = 1; i <= 40003; i++)
        p[i] = (p[i-1] * 31) % pr;
    cin >> t;
    while(t--) {
        node *leader1 = new node, *leader2 = new node;
        set<long long> hashes;
        cin >> m >> n;
        cin >> f >> s;
        leader1 -> fs = f;
        nodes1[0] = leader1;
        for(int i = 1; i < m; i++) {
            cin >> f >> s;
            add_warrior(f, i, s, 1);
        }
        cin >> f >> s;
        leader2 -> fs = f;
        nodes2[0] = leader2;
        for(int i = 1; i < n; i++) {
            cin >> f >> s;
            add_warrior(f, i, s, 2);
        }

        //Rabin - Karp
        idx = 0;
        string c1 = flatten(leader1);
        idx = 0;
        string c2 = flatten(leader2);
        h1[0] = c1[0] - 'A' + 1;
        h2[0] = c2[0] - 'A' + 1;
        for(int i = 1; i < c1.length(); i++)
            h1[i] = (h1[i-1] + (c1[i] - 'A' + 1) * p[i]) % pr;
        for(int i = 1; i < c2.length(); i++)
            h2[i] = (h2[i-1] + (c2[i] - 'A' + 1) * p[i]) % pr;
        for(int i = 0; i < m; i++) {
            int l = nodes1[i]->s;
            int r = nodes1[i]->e;
            long long h = h1[r];
            if(l) h = (h - h1[l-1] + pr) % pr;
            hashes.insert((h * p[max(c1.length(), c2.length()) - l]) % pr);
        }
        int best = 0;
        for(int i = 0; i < n; i++) {
            int l = nodes2[i]->s;
            int r = nodes2[i]->e;
            if(r - l + 1 > best) {
                long long h = h2[r];
                if(l) h = (h - h2[l-1] + pr) % pr;
                h = (h * p[max(c1.length(), c2.length()) - l]) % pr;
                if(hashes.find(h) != hashes.end())
                    best = r - l + 1;
            }
        }
        cout << best/4 << endl;
    }
}