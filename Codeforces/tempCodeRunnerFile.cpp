#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(){

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        int a[n];
        string s;

        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        cin >> s;

        unordered_map<int, char> umap;
        int ok = 1;

        for(int j = 0; j < n; j++){
            if (umap.find(a[j]) == umap.end()){
                umap[a[j]] = s[j];
            }else{
                if(umap[a[j]] != s[j]) ok = 0;
            }
        }

        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}