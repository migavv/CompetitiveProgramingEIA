//
// Created by migav on 12/10/2022.
//

#include<string>
#include<iostream>
#include<vector>

using namespace std;

//int main() {
//    string arrival;
//    vector<char> stacks;
//    int c = 1;
//    while(getline(cin >> ws, arrival), arrival != "end") {
//        size_t i = 0;
//        stacks = vector<char>();
//        while(i < arrival.length()) {
//            size_t j = 0;
//            while(j < stacks.size()) {
//                if(arrival[i] < stacks[j]) {
//                    stacks[j] = arrival[i];
//                    break;
//                }
//                if(arrival[i] == stacks[j])
//                    break;
//                j++;
//            }
//            if(j == stacks.size())
//                stacks.push_back(arrival[i]);
//            i++;
//        }
//        printf("Case %d: %d\n", c, (int)stacks.size());
//        c++;
//    }
//}