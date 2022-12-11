#include <bits/stdc++.h>

using namespace std;

string addBinary(string a, string b) {
    string s1 = "";

    if (a == "0" && b == "0") s1 = "0";
    //Usando string to integer built function de C++ convertimos los strings dados a enteros.
    unsigned long long aInt = stoull(a, 0, 2);
    unsigned long long bInt = stoull(b,0,2);

    int res = aInt + bInt;

    while(res) {
 	    s1 += (res%2) + '0';
        res /= 2;
    }
    reverse(s1.begin(),s1.end());

    return s1;
}

int main(){
    string a = "0", b = "0";
    cout << addBinary(a,b);
    return 0;
}