#include <bits/stdc++.h>

using namespace std;

int n, aux = 0;

int main(){

    scanf("%d", &n);

    while(aux <= n){
        string s;
        aux++;

        getline(cin,s);

        stack<int> stack;
        int flag = 1;

        for (size_t i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[') stack.push(s[i]);
            else{
                if((s[i] == ')' && stack.empty()) || (s[i] == ']' && stack.empty())) flag = 0;
                else{
                    if((s[i] == ')' && stack.top() == '(') || (s[i] == ']' && stack.top() == '[')) stack.pop();
                    else flag = 0;
                }
            }
            
        }
        if(aux > 1){
            if(stack.empty() && flag) printf("Yes\n");
            else printf("No\n");
        }
        
    }

    return 0;
}