#include <bits/stdc++.h>

using namespace std;

int tc;

int main(){

    scanf("%d", &tc);

    string s;
    getline(cin,s);
    getline(cin,s);

    while(tc--){
        string tree;
        map<string, float> map;
        int count = 0;

        while(getline(cin,tree)){
            if(tree == ""){
                break;
            }else{
                map[tree]++;
                count++;
            }
        }

        for(auto it = map.begin(); it != map.end(); it++){
            cout << it->first << " ";
            printf("%.4f\n", ((it->second/count) * 100));
        }

        if(tc != 0)
			cout << endl;
    }

    return 0;
}