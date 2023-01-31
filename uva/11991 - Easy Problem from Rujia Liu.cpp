
#include<vector>
#include<cstdio>

using namespace std;

typedef vector<int> vi;

int main() {
    int n, m, val, occ; //n: Size of the array; m: Number of queries;
                        // val: Stores array input values; occ: Stores the occurrence asked by the query
    while(scanf("%d %d", &n, &m) != EOF) {
        vector<vi> adjList(1000000); //adjList[val] is a vector<int> storing 
                                        // all indexes of the occurrences of val in the array, in ascending order
        for(int i = 1; i <= n; i++) {
            scanf("%d", &val);
            adjList[val].push_back(i); //Storing occurrences
        }
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &occ, &val);
            if(adjList[val].size() < occ) //Checking if 0 occurrences
                printf("0\n");
            else printf("%d\n", adjList[val][occ - 1]); //Printing index of Nth occurrence
        }
    }
}
