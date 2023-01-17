
#include <cstdio>
#include <set>

using namespace std;

int main() {
    int n; //Number of days of the promotion
    int k, bill; //k: stores number of bills;    bill: stores bill amount
    unsigned long int total; //Accumulates Mal-Wart's payments
    while(scanf("%d", &n), n) {
        total = 0;
        multiset<int> bills; //multiset simulates the urn. It's an ordered container, so at the end of each day,
                            // the highest and the lowest are easily accessible.
        while(n--) { //Loop until promotion is over
            scanf("%d", &k);
            for(int i = 0; i < k; i++) { //Compute a day's bills
                scanf("%d", &bill);
                bills.insert(bill);
            }
            total += *bills.rbegin() - *bills.begin(); //Add prize (highest bill - lowest bill)
                                                        // to total expenses.
            bills.erase(bills.begin()); //Removing bills from urn
            bills.erase(--bills.end());
        }
        printf("%lu\n", total); //Output result. "%lu" is specifier for unsigned long
    }
}
