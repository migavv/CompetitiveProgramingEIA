
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

void addValue(vector<vii> &matrix, int row, int col, int weight) { //Weight represents value of the cell
    ii edge;
    edge.first = col;
    edge.second = weight;
    matrix[row].push_back(edge);
}

int main() {
    int m, n, nz, col, val;
    while(scanf("%d %d", &m, &n) != EOF) {
        vector<vii> matrix(m + 1); //Matrix is represented as an adjacency list
        //Reading values into the matrix
        for(int i = 1; i <= m; i++) {
            scanf("%d", &nz);
            //Computing coordinates
            for(int j = 0; j < nz; j++) {
                scanf("%d", &col);
                addValue(matrix, i, col, 0); //Weight is temporarily set as 0,
                                                            // until its value is read in the next input line
            }
            //Computing values
            for(int j = 0; j < nz; j++) {
                scanf("%d", &val);
                matrix[i][j].second = val;
            }
        }
        vector<vii> transposed(n + 1); //Creating adjacency list for transposed matrix
        //Filling transposed matrix
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j < matrix[i].size(); j++)
                transposed[matrix[i][j].first].push_back(ii(i, matrix[i][j].second)); //Switching rows <=> cols
        }
        //Printing results
        printf("%d %d\n", n, m);
        for(int i = 1; i <= n; i++) {
            printf("%d", (int)transposed[i].size());
            for(int j = 0; j < transposed[i].size(); j++)
                printf(" %d", transposed[i][j].first);
            printf("\n");
            for(int j = 0; j < transposed[i].size(); j++) {
                printf("%d", transposed[i][j].second);
                if(j < transposed[i].size() - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
