//
// Created by migav on 20/04/2023.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, d, p, curr, bags[10000], c = 0; //d: Each bag dimension; p: Number of resulting pieces after storing them into one another.
    //bags array stores dimension of each bag of a given test case; curr: Aux counter.
    while(cin >> n, n) {
        if(c++) cout << endl;
        //reading input:
        for(int i = 0; i < n; i++)
            cin >> bags[i];

        //Sorting bags:
        sort(bags, bags + n);

        //Getting minimum possible number of pieces 'p', by counting maximum number of bags with the same dimension.
        //i.e: if sorted bags is 112223333, p = 4, as there are 4 bags with dimension 3.
        d = bags[0];
        p = curr = 1;
        for(int i = 1; i < n; i++) {
            if(bags[i] == d) curr++;
            else {
                p = max(curr, p);
                curr = 1;
                d = bags[i];
            }
        }

        //The bags are them distributed equally between the p subsets of bags:
        p = max(curr, p);
        cout << p << endl;
        for(int i = 0; i < p; i++) {
            cout << bags[i];
            for(int j = i + p; j < n; j += p) {
                cout << " " << bags[j];
            }
            cout << endl;
        }
    }
}