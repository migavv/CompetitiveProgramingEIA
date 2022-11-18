//
// Created by migav on 11/10/2022.
//

#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

string a, b;
stack<char> s;

void anagrams(int i, int o, int idx, char ops[]) {
    if(i < a.length()) {
        s.push(a[i]);
        ops[idx] = 'i';
        anagrams(i + 1, o, idx + 1, ops);
        s.pop();
    }
    if(o < i) {
        if(s.top() == b[o]) {
            s.pop();
            ops[idx] = 'o';
            anagrams(i, o + 1, idx + 1, ops);
            s.push(b[o]);
        }
    }
    if(i == a.length() && o == b.length()) {
        for(size_t j = 0; j < 2 * a.length(); ++j) {
            if(j) printf(" ");
            printf("%c", ops[j]);
        }
        printf("\n");
        return;
    }
}

//int main() {
//    while(getline(cin >> ws, a)) {
//        getline(cin >> ws, b);
//        char ops[100];
//        printf("[\n");
//        if(a.length() == b.length())
//            anagrams(0, 0, 0, ops);
//        printf("]\n");
//    }
//    return 0;
//}