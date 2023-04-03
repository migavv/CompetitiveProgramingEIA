//
// Created by migav on 3/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

struct carMaker {
    string name;
    int min = 0, max = 0;
};

int main() {
    int t, d, q, p, count; //t: Testcases; d: Database length; q: Number of queries; p: Query value;
    //count: Counter variable;
    string res; //Aux variable
    cin >> t;
    carMaker database[10000];
    while(t--) {
        cin >> d;
        for(int i = 0; i < d; i++) {
            carMaker &curr = database[i];
            cin >> curr.name >> curr.min >> curr.max;
        }
        cin >> q;
        while(q--) {
            cin >> p;
            count = 0; // Counts car makers with fitting range
            for(int i = 0; i < d; i++) {
                carMaker &curr = database[i];
                if(p >= curr.min && p <=curr.max) { //Checks if p within car maker price range
                    count++; //Updating counter
                    res = curr.name; //Storing name of the car maker
                }
                if(count > 1) break;
            }
            if(count == 1) cout << res;
            else cout << "UNDETERMINED";
            cout << endl;
        }
        if(t) cout << endl;
    }
}