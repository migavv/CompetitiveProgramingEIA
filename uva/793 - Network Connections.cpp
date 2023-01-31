
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> vi;

class UnionFind { //Implementing Union Find Disjoint Set to check connections
private: vi p, rank;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j) { //Checks if two items linked
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) { //Links two items
        if(!isSameSet(i, j)) {
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] >= rank[y])  {
                p[y] = x;
                if(rank[x] == rank[y])
                    rank[x]++;
            }
            else p[x] = y;
        }
    }
};

int main() {
    int cases, size, pc1, pc2, scs, fail; //size: Network size; pc1 & pc2: Computer identifiers
                                            //scs: Counter for successful answers; fail: Counter for unsuccessful answers
    char id; // id = 'c' when input line indicates connection;
            // id = 'q' when input line indicates question
    string input; //Aux string to check for emtpy lines
    scanf("%d\n", &cases);
    while(cases--) {
        scanf("%d\n", &size);
        UnionFind network(size + 1); //size + 1 as computer indexing is 1-based
        scs = 0;
        fail = 0;
        scanf("%d\n", &size);
        while(getline(cin, input), !input.empty()) {
            istringstream aux(input);
            aux >> id >> pc1 >> pc2;
            if(id == 'c') //If 'c', connect computers
                network.unionSet(pc1, pc2);
            else { //else check if computers are connected
                if(network.isSameSet(pc1, pc2)) scs++;
                else fail++;
            }
        }
        //Output results
        printf("%d,%d\n", scs, fail);
        if(cases > 0)
            printf("\n");
    }
}