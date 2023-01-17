#include <bits/stdc++.h>
 
using namespace std;

int t;

int main(){

    scanf("%d", &t);

    while(t--){
        int k, n, count = 1, temp = 1, aux = 0;

        scanf("%d" "%d", &k, &n);

        int res[n+1] = {0};
        vector<int> ans;

        for (size_t i = 1; i < (n+1); i++)
        {
            if(aux < k){
                if(count == i){
                    res[i] = i;
                    count += temp;
                    temp++;
                    aux++;
                }
            }
        }

        if(aux < k){
            
            for (size_t i = n; i > 0; i--)
            {
                if(aux < k){
                    if(res[i] == 0) {
                        res[i] = i;
                        aux++;
                    }

                }else break;
                
            }
            
        }

        for (size_t i = 1; i < (n+1); i++)
        {
            if(res[i] != 0){
                ans.push_back(res[i]);
            }
        }

        for (size_t i = 0; i < ans.size(); i++)
        {
            printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
        }
        
    }

    return 0;

}