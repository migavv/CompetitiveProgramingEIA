//
// Created by migav on 10/10/2022.
//

#include <stack>
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//int main() {
//    int n;
//    bool possible;
//    string input;
//    while(scanf("%d", &n), n) {
//        cin >> ws;
//        while(getline(cin, input), input != "0") {
//            istringstream aux(input);
//            int output[1000];
//            for(size_t i = 1; i <= n; ++i)
//                aux >> output[i];
//            stack<int> station;
//            int i = 1;
//            size_t j = 1;
//            possible = true;
//            while(j <= n) {
//                if(station.empty() || station.top() != output[j]) {
//                    if(i > n) {
//                        possible = false;
//                        break;
//                    }
//                    station.push(i++);
//                } else {
//                    station.pop();
//                    j++;
//                }
//            }
//            if(possible) printf("Yes\n");
//            else printf("No\n");
//        }
//        printf("\n");
//    }
//}