#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {

    if (s.length() < 2) return false;
        
    stack<char> stack;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack.push(s[i]);
        
        else{
            if ((s[i] == ')' && stack.empty()) || (s[i] == '}' && stack.empty()) || (s[i] == ']' && stack.empty())) return false;
            if((s[i] == ')' && stack.top() == '(') || (s[i] == '}' && stack.top() == '{') || (s[i] == ']' && stack.top() == '[')) stack.pop();
            else return false; 
        }
    }

    if(stack.empty()) return true;
    else return false;

    /*while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }*/

}

int main(){
    string s = "(})";

    cout << isValid(s);

}