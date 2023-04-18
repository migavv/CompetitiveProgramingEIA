//
// Created by migav on 16/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

int towers[20]; //Tower[i] Stores the total amount of people covered by tower i.
unordered_map<int, int> common; //Map storing information about common coverage areas.
//common[0b100011] = 10, would mean that the common area of the zones 1, 2 and 6 (see positions of 1s in key val) covers 10 people.

//Aux method used for checking which of two answers with the same value to choose, according to the problem constraints.
bool isBetter(int a, int b) {
    if(a&1 && ~b&1) return true;
    else if(~a&1 && b&1) return false;
    else return isBetter(a >> 1, b >> 1);
}

int main() {
    int n, b, m, t, tower, val,
        sum, best, rec, c = 0;
    //n: Towers planned; b: Towers to actually be built; m: Number of common zones;
    //t: number of tower that take part of a given common zone; tower: Aux var to store each tower that is part of a common zone;
    //val: Aux var that stores amount of people that a common zone covers; sum: Number of people covered by the union of some b selected towers;
    //best: Number of people covered by the best selection of b towers;
    //rec: Recommended towers to build, as a bitmask (rec = 1011 would mean that towers 1, 2 and 4 are recommended);
    //c: test case counter

    //Reading input
    while(cin >> n >> b, n || b) {
        common.clear();
        //Reading total of people that would be covered by each tower
        for(int i = 0; i < n; i++)
            cin >> towers[i];
        //Reading all common coverage zones
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> t;
            int aux = 0; //bitmask
            //Getting all tower involved in the common zone into the bitmask
            for(int j = 0; j < t; j++) {
                cin >> tower;
                aux |= 1 << (tower - 1); //All bits corresponding to the towers involved are turned into 1
            }
            cin >> val;
            common[aux] += val; //Mapping towers involved and number of people covered by common area
        }

        //Bruteforce search for the best possible selection of b towers
        best = INT_MIN;
        rec = 0;
        for(int s = 1; s < 1 << n; s++) if(__builtin_popcount(s) == b) { //For every possible combination of b towers, expressed as the bitmask s
                sum = 0;
                for(int i = 0; i < n; i++) {
                    if(s & 1 << i) {
                        sum += towers[i];//Sum total number of people that would be covered by each of the selected towers
                    }
                }
                //Inclusion exclusion principle. Avoiding counting extra people:
                for(const auto &area : common) { //Iterating through all common areas.
                    int ints = __builtin_popcount(area.first & s);
                    //ints gets the number of towers from the currently selected ones (s), that take part in the current common area.
                    if(ints > 1) sum -= (ints - 1) * area.second; //If more than one tower is involved, subtract from sum.
                }
                if(sum >= best) { //Update best answer
                    if(sum > best || isBetter(s, rec)){
                        best = sum;
                        rec = s;
                    }
                }
            }

        //Output results
        cout << "Case Number  " << ++c << endl;
        cout << "Number of Customers: " << best << endl;
        cout << "Locations recommended:";
        for(int i = 0; i < n; i++) if(rec & 1 << i) {
                cout << " " << i + 1;
            }
        cout << "\n\n";
    }
}