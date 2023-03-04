
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    long long n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (int)((sqrt(1 + 8 * n) - 1)/2) << endl; //From sum of arithmetic series formula
    }
}