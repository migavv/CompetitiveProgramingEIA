
#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

class SegmentTree { //Segment tree for Range Sum Query with lazy updates
private: vi st, A;
    vc lazy;
    int n;
    int left(int i) {return i << 1;}
    int right(int i) {return (i << 1) + 1;}
    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = A[L];
        } else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)]; int p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }
    static void invert(char& v) { //Aux method. Switches update operations.
        /*
         * If current operation is 'I' (mutate to inverse pirates) and
         * there is already an update pending for the node, this method
         * will switch the update accordingly.
         */
        if(v == 'F') v = 'E'; //If previous update operation was 'E', new operation is set to 'E'
        else if(v == 'E') v = 'F'; //If previous update operation was 'E', new operation is set to 'F'
        else if(v == 'I') v = 0; //If both previous and current operation are 'I', they cancel each other, so update removed
        else v = 'I'; //If there is no previous operation, it is set to 'I'.
    }
    int rsq(int p, int L, int R, int i, int j) {
        //Apply lazy update
        if(lazy[p] != 0) {
            if(lazy[p] == 'F') st[p] = R - L + 1;
            else if(lazy[p] == 'E') st[p] = 0;
            else st[p] = (R - L + 1) - st[p];
            if(L < R) { //Assign lazy update to children nodes
                if(lazy[p] == 'I') { //Combine previously assigned update with current 'I' operation.
                    invert(lazy[left(p)]);
                    invert(lazy[right(p)]);
                } else {
                    lazy[left(p)] = lazy[p];
                    lazy[right(p)] = lazy[p];
                }
            }
            lazy[p] = 0;
        }
        if(i > j || L > j || R < i) return 0;
        if(L >= i && R <= j) return st[p];
        int p1 = rsq(left(p), L, (L + R) / 2, i, j);
        int p2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);
        return p1 + p2;
    }
    void update(int p, int L, int R, int i, int j, char v) { //Lazy update implementation
        if(lazy[p]) {
            if(lazy[p] == 'F') st[p] = R - L + 1;
            else if(lazy[p] == 'E') st[p] = 0;
            else st[p] = (R - L + 1) - st[p];
            if(L < R) {
                if(lazy[p] == 'I') { //Same as rsq
                    invert(lazy[left(p)]);
                    invert(lazy[right(p)]);
                } else {
                    lazy[left(p)] = lazy[p];
                    lazy[right(p)] = lazy[p];
                }
            }
            lazy[p] = 0;
        }
        if(i > j || L > j || R < i)
            return;
        if(L >= i && R <= j) {
            if(v == 'F') st[p] = R - L + 1;
            else if(v == 'E') st[p] = 0;
            else st[p] = (R - L + 1) - st[p];
            if(L < R) {
                if(v == 'I') { //Same as rsq
                    invert(lazy[left(p)]);
                    invert(lazy[right(p)]);
                } else {
                    lazy[left(p)] = v;
                    lazy[right(p)] = v;
                }
            }
            return;
        }
        update(left(p), L, (L + R) / 2, i, j, v);
        update(right(p),(L + R) / 2 + 1, R, i, j, v);
        st[p] = st[left(p)] + st[right(p)];
    }
public:
    SegmentTree(const vi &_A) {
        A = _A; n = (int)_A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rsq(int i, int j) {return rsq(1, 0, n - 1, i, j);}
    void update(int i, int j, char v) {
        update(1, 0, n - 1, i, j, v);
    }
};

int main() {
    int T, M, rep, Q, a, b, q; //T: # of test cases; M: # of sets of input; Q: # of queries.
    //rep: Times a sequence of pirates is repeated; a & b: left and right bounds of query respectively.
    //q: Counter of god's questions answered.
    char v; //v: Stores char representing the meaning of current query
    string pirates, curr, query; //pirates: string storing complete pirate sequence.
    //curr: Aux string for building 'pirates' string.
    cin >> T;
    for(int c = 1; c <= T; c++) {
        pirates.clear();
        cin >> M;
        while(M--) { //Building 'pirates' string
            cin >> rep;
            cin >> curr;
            while(rep--)
                pirates += curr;
        }
        vi pirateWorld; //Vector based on 'pirates' string. Used to build segment tree
        pirateWorld.assign(pirates.size(), 0); //Copying pirates string to pirateWorld vector
        for(int i = 0; i < pirates.size(); i++)
            pirateWorld[i] = pirates[i] - '0';
        SegmentTree tree(pirateWorld); //Segment tree to keep track of changes in pirateWorld
        cin >> Q;
        q = 1;
        cout << "Case " << c << ":\n";
        while(Q--) {
            cin >> v >> a >> b; //Read query
            if(v != 'S') tree.update(a, b, v); //Compute magician's spell
            else cout << "Q" << q++ << ": " << tree.rsq(a, b) << endl; //Answer god's question
        }
    }
    return 0;
}