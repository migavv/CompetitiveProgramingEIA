#include <bits/stdc++.h>

using namespace std;

int cases, res;
string s1, s2;

int main (){

    scanf("%d", &cases);

    while (cases--){
        cin >> s1 >> s2;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if(s1[0] == 'L' && s2[0] == 'L'){
            res = s1.compare(s2);
            if(res < 0) printf("<\n");
            else if(res > 0) printf(">\n");
            else printf("=\n");
        }
        else if (s1[0] == 'S' && s2[0] == 'S'){
            res = s1.compare(s2);
            if(res < 0) printf(">\n");
            else if(res > 0) printf("<\n");
            else printf("=\n");
        }
        else if (s1[0] == 'L' && s2[0] == 'S') printf(">\n");
        else if (s1[0] == 'S' && s2[0] == 'L') printf("<\n");
        else if (s1[0] == 'L' && s2[0] == 'M') printf(">\n");
        else if(s1[0] == 'M' && s2[0] == 'L') printf("<\n");
        else if (s1[0] == 'S' && s2[0] == 'M') printf("<\n");
        else if (s1[0] == 'M' && s2[0] == 'S') printf(">\n");
        else printf("=\n");
    }

    return 0;
}