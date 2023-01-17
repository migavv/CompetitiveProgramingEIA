
#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
    cout.precision(4); //Decimal precision requirement for output
    int cases;
    scanf("%d\n", &cases);
    while(cases--) {
        string name;
        int size = 0; //Counter for number of trees inserted on map
        map<string, int> trees; //Using map instead of unordered_map as output must be in alphabetical order
        while(getline(cin, name), name.length() != 0) {
            trees[name]++; //Insert/update values on map
            size++; //Update number of trees
        }
        for(auto const& pair : trees) //Iteration method for map (C++ 11)
            cout << pair.first << " " << fixed << (double)pair.second / size * 100 << endl; //pair.first = key, pair.second = value.
                                     // "fixed" for formatting percentages as expected
        if(cases != 0) cout << endl; //Conditional to avoid extra line at the end
    }
}