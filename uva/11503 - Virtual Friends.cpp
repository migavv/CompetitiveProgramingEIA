
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef unordered_map<string, string> ms;
typedef unordered_map<string, int> mi;

class UnionFind { //Friendship networks are represented with Union Find Disjoint Set data structure
private:
    ms p;
    mi rank, rep; //rep stores the size of the sets
public:
    void insertItem(const string& item) {
        if(p.find(item) == p.end()) {
            p[item] = item;
            rank[item] = 0;
            rep[item] = 1; //Initial sie of each set is 1
        }
    }
    string findSet(const string& item) {
        return (p[item] == item) ? item : p[item] = findSet(p[item]);
    }

    bool isSameSet(const string& i, const string& j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(const string& i, const string& j) {
        insertItem(i);
        insertItem(j);
        if(!isSameSet(i, j)) {
            string x = findSet(i);
            string y = findSet(j);
            if(rank[x] >= rank[y]) {
                p[y] = x;
                rep[x] += rep[y]; //Updating number of elements when merging two sets
                if(rank[x] == rank[y])
                    rank[x]++;
            } else {
                p[x] = y;
                rep[y] += rep[x]; //Same as comment above
            }
        }
    }

    int getSize(const string& i) {
        return rep[findSet(i)];
    }
};

int main() {
    int c, f; //c = number of cases; f = number of friendships for each case
    string a, b; //a & b store the names of the two people involved in the friendship
    cin >> c;
    while(c--) {
        cin >> f;
        UnionFind network;
        while(f--) {
            cin >> a >> b;
            network.unionSet(a, b); //Linking the two people
            cout << network.getSize(a) << endl; //Printing friendship network size
        }
    }
}