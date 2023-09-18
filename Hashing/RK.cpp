
#include <bits/stdc++.h>

using namespace std;

int main() {
    int p = 31;
    long long m = 1e9+9, p_pow[1000], h[1000];

    string s = "alola";
    string t = "lol";
    p_pow[0] = 1;
    for(int i = 1; i <= s.length(); i++)
        p_pow[i] = (p_pow[i-1] * p)%m;
    h[0] = s[0] - 'a' + 1;
    for(int i = 1; i < s.length(); i++)
        h[i] = (h[i-1] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = (((h[3] - h[0] + m) % m) * p_pow[s.length() - 1]) % m;
    long long h_t = 0;
    for(int i = 0; i < t.length(); i++)
        h_t = (h_t + (t[i] - 'a' + 1) * p_pow[i]) % m;

    h_t = (h_t * p_pow[s.length()]) % m;
    if(h_s == h_t)
        cout << "match";
    else cout << "no match";

}