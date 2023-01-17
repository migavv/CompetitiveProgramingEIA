#include <bits/stdc++.h>

using namespace std;

int t;

int main(){

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int p = 0;
        vector<int> move;

        while(n >=0){

            string s, number;
            int num;

            getline(cin,s);

            if(s[0] == 'R'){
                p += 1;
                move.push_back(1);
            }

            if(s[0] == 'L'){
                p -= 1;
                move.push_back(-1);
            }

            if(s[0] == 'S') {
                for (size_t i = 8; i < s.size(); i++)
                {
                    number += s[i]; 
                }

                num = stoi(number);
                
                p = p + move[num - 1];
                move.push_back(move[num - 1]);
            }

            n--;
        }

        printf("%d\n", p);
    }

    return 0;
}