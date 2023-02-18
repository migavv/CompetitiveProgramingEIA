
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;

class SegmentTree { //Segment tree implementation for Range Maximum Query
private:
    vi st, A;
    int n;
    int left(int i) {return (i << 1);}
    int right(int i) {return (i << 1) + 1;}
    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = L;
        } else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] > A[p2]) ? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return(A[p1] > A[p2]) ? p1 : p2;
    }
public:
    SegmentTree(const vi &_A) {
        A = _A; n = _A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rmq(int i, int j) {return (i <= j) ? A[rmq(1, 0, n - 1, i, j)] : -1;}
};

int main() {
    int n, q, val, pos, freq, I, J; //n = Size of array; q = Number of Queries;
    // pos: Aux. Stores left bound of current sequence of repeated numbers;
    // freq: Aux. Stores frequency of value being read
    //[I, J]: Query range
    vi A, F; //A: Stores array; F: Vector of frequencies of A.
    // Example: A = -1 -1 1 1 1 1 3 10 10 10  =>  F = 2 2 4 4 4 4 1 3 3 3
    unordered_map<int,int> L, R; //L: L[i] = index of leftmost occurrence of i in A
    //R: R[i] = index of rightmost occurrence of i in A
    while(scanf("%d", &n), n) { //Read n
        scanf("%d", &q); //Read q
        L.clear();
        R.clear();
        A.assign(n + 1, 0); //Arrays sized n + 1, so it can be handled as one-based arrays
        F.assign(n + 1, 0);
        //Building vectors and maps
        scanf("%d", &val);
        A[1] = val;
        L[val] = 1;
        pos = 1;
        freq = 1;
        for(int i = 2; i <= n; i++) {
            scanf("%d", &val);
            if(val != A[i - 1]) {
                R[A[i - 1]] = i - 1;
                L[val] = i;
                fill_n(F.begin() + pos, i - pos, freq);
                pos = i;
                freq = 0;
            }
            freq++;
            A[i] = val;
        }
        R[A[n - 1]] = n - 1;
        fill(F.begin() + pos, F.end(), freq);
        SegmentTree st(F); //Segment tree built upon vector F for Range Maximum Query
        while(q--) {
            scanf("%d %d", &I, &J); //Reading queries
            //4 Cases:
            if(A[I] == A[J]) printf("%d\n", J - I + 1); //Case 1: Range composed of only one value (-1 -1 [1 1 1 1] 3 10 10 10)
            else if(A[I] != A[I - 1] && (J + 1 > n || A[J] != A[J + 1])) //Case 2: >1 Range composed of all repetitions of some values of A ([-1 -1 1 1 1 1] 3 10 10 10)
                printf("%d\n", st.rmq(I, J));
            else if(A[I] == A[I - 1] && (J + 1 > n || A[J] != A[J + 1])) //Case 3: Doesn't include every repetition of leftmost value (-1 -1 1 1 [1 1 3 10 10 10])
                printf("%d\n", max(R[A[I]] - I + 1, st.rmq(R[A[I]] + 1, J)));
            else if(A[I] != A[I - 1] && (J + 1 <= n && A[J] == A[J + 1])) //Case 4: Doesn't include every repetition of rightmost value ([-1 -1 1 1 1] 1 3 10 10 10)
                printf("%d\n", max(J - L[A[J]] + 1, st.rmq(I, L[A[J]] - 1)));
            else { //Case 5: Doesn't include neither every repetition of leftmost value nor every repetition of rightmost value (-1 -1 1 [1 1 1 3 10 10] 10)
                int left = R[A[I]] - I + 1;
                int mid = st.rmq(R[A[I]] + 1, L[A[J]] - 1);
                int right = J - L[A[J]] + 1;
                if(left >= mid) printf("%d\n", max(left, right));
                else printf("%d\n", max(mid, right));
            }
        }
    }
}

