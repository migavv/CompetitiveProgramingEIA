
#include<cstdio>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main() {
    int cases, nFlakes, maxPack; //nFlakes: number of flakes, maxPack: At the end will hold the size of the largest package
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &nFlakes);
        int flakes[nFlakes]; //Aux array for storing all snowflakes' IDs
        for(int i = 0; i < nFlakes; i++)
            scanf("%d", &flakes[i]);
        unordered_map<int, int> snowflakes;

        //Sliding window algorithm
        maxPack = 0;
        int i = 0; //Sliding window - Right bound
        int j = 0; //Sliding window - Left bound
        while(i < nFlakes) {
            if(snowflakes[flakes[i]] > 0) { //If identical snowflake found
                snowflakes[flakes[j]]--; //Decrease frequency of its corresponding snowflake
                j++;                    //and decrease window size by one, moving left bound to the right
            } else {
                snowflakes[flakes[i]]++; //Insert snowflake in the map
                i++; //Increase window's size by moving right bound
                maxPack = max(maxPack, i - j); //Update max length if current size is longer
            }
        }
        printf("%d\n", maxPack);
    }
}
