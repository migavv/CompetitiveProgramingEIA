//
// Created by migav on 18/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> serial[60];  //serial[c - 'A'] stores all indexes corresponding to a char c (from A to z)

//Upper bound binary search implementation (c++ upper_bound can be used instead)
int bs(char c, int val) {
    vector<int> &aux = serial[c - 'A'];
    int f = 0, t = (int) aux.size() - 1;
    while (f <= t) {
        int m = (f + t) / 2;
        if (aux[m] <= val)
            f = m + 1;
        else t = m - 1;
    }
    return (f < aux.size()) ? aux[f] : -1; //If no greater value was found, return -1
}

int main() {
    string line, str; //line: String of candidates; str: Fill Bates Query
    bool match; //Will be set to true if a match was found for a query

    //Building map of indexes, 'serial':
    int i = 0;
    int q;
    cin >> line;
    for (char c: line)
        serial[c - 'A'].push_back(i++);

    cin >> q;
    while (q--) {
        match = true;
        cin >> str;
        int first = 0;
        int last = -1; //Last match found
        for (int j = 0; j < str.length(); j++) {
            last = bs(str[j], last); //Find the minimum index greater to previous index within the indexes of char j
            if (last == -1) { //If such value wasn't found, there's no match.
                match = false;
                break;
            }
            if (!j) first = last; //Assign first index to first one found.
        }
        //Print results
        if (match) cout << "Matched " << first << " " << last;
        else cout << "Not matched";
        cout << endl;
    }
}