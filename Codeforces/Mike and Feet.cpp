//
// Created by migav on 8/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 100;
int bear[maxn], l[maxn], r[maxn], ans[maxn];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> bear[i];
    fill(l, l+maxn, -1);
    fill(r, r+maxn, n);
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && bear[s.top()] >= bear[i])
            s.pop();
        if(!s.empty())
            l[i] = s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for(int i = n-1; i >= 0; i--) {
        while(!s.empty() && bear[s.top()] >= bear[i])
            s.pop();
        if(!s.empty())
            r[i] = s.top();
        s.push(i);
    }
    for(int i = 0; i < n; i++) {
        int len = r[i] - l[i] - 1;
        ans[len] = max(ans[len], bear[i]);
    }
    for(int i = n; i >= 0; i--)
        ans[i] = max(ans[i], ans[i+1]);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}