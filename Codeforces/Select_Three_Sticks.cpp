#include <bits/stdc++.h>

using namespace std;

int main(){

    int cases;
    cin >> cases;

    while (cases--)
    {
        int size;
        int ans=2e9;
        cin >> size;

        int sticks[size];

        for (int i = 0; i < size; i++){
            cin >> sticks[i];
        }

        sort(sticks, sticks + size);

        for (int i=2; i<size; i++){
		    ans = min(ans, sticks[i]-sticks[i-2]);
	    }

        cout << ans << endl;

    }
    
}