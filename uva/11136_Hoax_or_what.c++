#include <bits/stdc++.h>

using namespace std;

int n;

int main(){

    while(scanf("%d", &n), n != 0){

        long long sum = 0;
        multiset<int, greater<int> > bills;

        while(n--){
            int k, kn, dif = 0;

            scanf("%d", &k);
            
            for (size_t i = 0; i < k; i++)
            {
                scanf("%d", &kn);
                bills.insert(kn);
            }

            dif = *(bills.begin()) - *(bills.rbegin()); 

            bills.erase(bills.find(*(bills.begin())));
            bills.erase(bills.find(*(bills.rbegin())));

            sum += dif;
            
        }

        cout << sum << endl;
    }

    return 0;
}