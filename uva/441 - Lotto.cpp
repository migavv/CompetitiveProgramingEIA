
#include <iostream>

using namespace std;

int main() {
    int k, t = 0;
    int set[13];
    while(cin >> k, k) {
        if(t) cout << endl;
        t++;
        for(int i = 0; i < k; i++) {cin >> set[i];}
        //Iterating through all possible subsets
        for(int a = 0; a < k - 5; a++)
            for(int b = a + 1; b < k - 4; b++)
                for(int c = b + 1; c < k - 3; c++)
                    for(int d = c + 1; d < k - 2; d++)
                        for(int e = d + 1; e < k - 1; e++)
                            for(int f = e + 1; f < k; f++)
                                cout
                                << set[a] << " " << set[b] << " "
                                << set[c] << " " << set[d] << " "
                                << set[e] << " " << set[f] << endl;
    }
}
