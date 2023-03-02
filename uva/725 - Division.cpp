
#include <cstdio>

using namespace std;

int main() {
    int n, tests = 1;
    while(scanf("%d", &n), n) {
        if(tests++ > 1) printf("\n");
        bool found = false;
        for(int den = 0; den <= 98765 / n; den++) { //den: Denominator;
            int num = den * n; //num: Numerator
            //digits: bitmask keeping track of digits already used.
            int aux = num, digits = (den < 10000); //Checking if first digit of den == 0 and storing result in bitmask
            while(aux) {
                digits |= 1 << (aux % 10); //Iterating through numerator digits
                // and setting corresponding bits in bitmask
                aux /= 10;
            }
            aux = den; //Same with denominator digits
            while(aux) {
                digits |= 1 << (aux % 10);
                aux /= 10;
            }
            if(digits == (1 << 10) - 1) { //Check if all digits were used
                printf("%05d / %05d = %d\n", num, den, n);
                found = true;
            }
        }
        if(!found) printf("There are no solutions for %d.\n", n);
    }
}
