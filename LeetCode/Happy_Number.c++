#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(int n){

    int sum = 0, digito;

    while(n){
        digito = n % 10;
        digito = digito * digito;
        sum += digito;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    
    set<int> sums;

    while(sums.find(n) == sums.end()){
        sums.insert(n);

        n = sumOfDigits(n);
        
        if(n == 1) return true;
    }

    return false;

}

int main(){

    cout << isHappy(19) << endl;
    //isHappy(19);

    return 0;
}