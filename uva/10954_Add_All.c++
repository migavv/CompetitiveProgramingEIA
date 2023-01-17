#include <bits/stdc++.h>

using namespace std;

int n;
int main(){

    while(scanf("%d", &n), n != 0){
        priority_queue <int, vector<int>, greater<int> > queue;
        int number;

        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", &number);
            queue.push(number);
        }

        int sum = 0, temp = 0;

        while(queue.size() > 1){
            temp = queue.top();
            queue.pop();
            temp = temp + queue.top();
            queue.pop();
            sum += temp;
            queue.push(temp);
        }

        printf("%d\n", sum);
    }

    return 0;
}