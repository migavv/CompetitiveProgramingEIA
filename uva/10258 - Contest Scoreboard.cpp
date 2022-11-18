//
// Created by migav on 30/09/2022.
//

#include<iostream>
#include<climits>
#include<cstdio>
#include<algorithm>
#include<string>
#include<sstream>

//struct team {
//    int num = 0;
//    int problems = 0;
//    int penalty = INT_MAX;
//    int attempts[10] = {0};
//    bool solved[10] = {false};
//
//    bool operator < (const team& t2) const {
//        if(problems != t2.problems)
//            return problems > t2.problems;
//        if(penalty != t2.penalty)
//            return penalty < t2.penalty;
//        return num < t2.num;
//    }
//};
//
//using namespace std;
//
//int main() {
//    int cases, c, p, t; //Contestant, Problem, Time
//    char l; //Verdict
//    string submission;
//    scanf("%d\n", &cases);
//    while(cases--) {
//        team teams[101];
//        while(getline(cin, submission), submission.length() != 0) {
//            istringstream aux(submission);
//            aux >> c >> p >> t >> l;
//            if(teams[c].num == 0) {
//                teams[c].num = c;
//                teams[c].penalty = 0;
//            }
//            if(l == 'I')
//                teams[c].attempts[p] += 20;
//            else if(l == 'C' && !teams[c].solved[p]) {
//                teams[c].problems++;
//                teams[c].solved[p] = true;
//                teams[c].penalty += teams[c].attempts[p] + t;
//            }
//        }
//        sort(teams, teams + 101);
//        size_t i = 0;
//        while(teams[i].num != 0) {
//            printf("%d %d %d\n", teams[i].num, teams[i].problems, teams[i].penalty);
//            i++;
//        }
//        if(cases != 0)
//            printf("\n");
//    }
//}