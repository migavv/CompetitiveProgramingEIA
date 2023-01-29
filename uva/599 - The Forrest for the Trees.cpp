
#include<cstdio>
#include<cstring>
#include<bitset>

using namespace std;

int main() {
    int cases, v, e, a; //v: number of vertices; e: number of edges; a: number of acorns (vertices with no edges).
    scanf("%d", &cases);
    while(cases--) {
        e = 0;
        char input[100]; //C String to process input
        bitset<26> acorns; //Keeps track of vertices with some edge
        while(scanf("%s", input), input[0] != '*') { //Getting edges
            //Setting bits corresponding to vertices with edges to 1.
            //Vertices are named with capital letters
            acorns[input[1] - 65] = true; //Character 'A' equals 65 (UTF-8), B = 66, C = 67, ...
            acorns[input[3] - 65] = true;
            e++; //Keeping track of number of edges
        }
        scanf("%s", input); //Getting list of vertices
        size_t len = strlen(input);
        v = ((int)len + 1)/2; //Computing number of vertices (ignoring commas from string)
        a = 0;
        for(int i = 0; i < len; i +=2) { //Counting vertices with no edges
            if(!acorns[input[i] - 65])
                a++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n", v - e - a, a);
    }
}


