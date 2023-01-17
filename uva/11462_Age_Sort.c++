#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,aux;
    vector<int> numbers;

    while(scanf("%d", &n), n != 0){

        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", &aux);
            numbers.push_back(aux);
        }
        
        sort(numbers.begin(), numbers.end());

        for (size_t i = 0; i < n; i++)
        {
            printf("%d%s", numbers[i], i == n - 1 ? "\n" : " ");
        }

        numbers.clear();
    }

    return 0;
}