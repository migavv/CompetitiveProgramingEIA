
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct query { //Struct for ordering queries
    int id;
    int freq;
    int clock; //Time of next response

    query(int _id, int _freq) {
        id = _id;
        freq = _freq;
        clock = freq;
    }

    bool operator<(const query& _query) const { //Defining less than operator to allow comparison between queries
        if(clock != _query.clock)
            return clock > _query.clock;
        else return id > _query.id;
    }
};

int main() {
    char reg[9]; //String storing word "Register" from query instruction
    int id, freq, k; //id: query id;    freq: query results' output frequency
    priority_queue<query> queue; //Stores queries and orders them according to clock (as defined in struct)
    while(scanf("%s", reg), strcmp(reg, "#")) { //Reading instructions
        scanf("%d %d", &id, &freq);
        query curr(id, freq);
        queue.push(curr); //Inserting query in queue
    }
    scanf("%d", &k);
    while(k--) {
        query updated = queue.top();
        updated.clock += updated.freq; //Update query clock
        printf("%d\n", updated.id); //output result
        //Update query
        queue.pop();
        queue.push(updated);
    }
}