
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct state { //This struct is used to keep track of number of negative numbers and zeros within a range
    int val, n = 0, z = 0; //val: Stores value given by friends;
    // n: Negatives counter. Keeps track of number of negatives of the sequence within corresponding Fenwick Tree range.
    // z: Zeroes counter. Keeps track of number of zeroes of the sequence within corresponding Fenwick Tree range.
    state(int _val) { val = _val; }
};

int LSOne(int s) {return s & (-s);} //Aux method of Fenwick Tree DS to get most significant one of an integer
int sign(int s) {
    if(!s) return 0;
    if(s < 0) return -1;
    return 1;
}
class FenwickTree {
private: vector<state> ft;
public:
    FenwickTree(int n) {ft.assign(n + 1, state(1));}
    int zeros(int b) { //Returns frequency of zero from 1 to b
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b].z;
        return sum;
    }
    int negatives(int b) { //Returns frequency of negative numbers from 1 to b
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b].n;
        return sum;
    }
    int negatives(int a, int b) {return negatives(b) - negatives(a - 1); } //Returns frequency of zeros from a to b
    int zeros(int a, int b) {return zeros(b) - zeros(a - 1); } //Returns frequency of negatives numbers from a to b
    void adjust(int k, int v) {
        for(int i = k; i < ft.size(); i += LSOne(i)) {
            if(!v) {
                if(ft[k].val) ft[i].z++; //If a number != is replaced by a 0, increase zeros counter
                if(ft[k].val < 0) ft[i].n--; //If the number was negative, decrease negatives counter
            }
            else if(v < 0) {
                if(ft[k].val >= 0) ft[i].n++; //If a number >= 0 is replaced by a negative, increase negative counter
                if(ft[k].val == 0) ft[i].z--; //If the number  was negatives, decrease zeros counter
            }
            else {
                if(ft[k].val < 0) ft[i].n--; //If a negative number is replaced by a positive number, decrease negatives counter
                else if(!ft[k].val) ft[i].z--; //If a zero is replaced by a positive number, decrease zeros counter
            }
        }
        ft[k].val = v;
    }
};

int main() {
   int n, k, i, v, val; //n: Sequence size; k: Number of commands;
   // i: First parameter of command; v: Second parameter of command;
   char cmd; //Character representing kind of command.
   vi a;//Stores initial sequence
   while(cin >> n >> k) { //Reading sequence
       a.assign(n + 1, 1);
       for(int j = 1; j <= n; j++) {
           cin >> val;
           a[j] = val;
       }
       FenwickTree ft(n);
       for(int j = 1; j <= n; j++) ft.adjust(j, a[j]);
       while(k--) {
           cin >> cmd >> i >> v;
           if(cmd == 'C') {ft.adjust(i, v); } //Change operation
           else { //Product operation
               if(ft.zeros(i, v) > 0) cout << 0; //If any zero within range [i, v], print 0.
               else if(ft.negatives(i, v) % 2) cout << '-'; //If odd frequency of negative numbers within range [i, v], print '-'.
               else cout << '+'; //In any other case, print '+'.
           }
       }
       cout << endl;
   }
}