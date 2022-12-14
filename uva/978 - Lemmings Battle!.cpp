
#include<cstdio>
#include<set>

using namespace std;

int main() {
    int cases, battlefields, green, blue, soldier; //green: num. of green soldiers.
                                                    //blue: num. of blue soldiers.
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d %d", &battlefields, &green, &blue);
        multiset<int, greater<int>> gArmy, bArmy; //Using multiset as it's ordered. Priority queue also works
                                                    //multiset is the same as set but allows repeated elements
                                                    //gArmy: stores green lemmings.    bArmy: stores blue lemmings.
        while(green--) { //Insert green lemmings
            scanf("%d", &soldier);
            gArmy.insert(soldier);
        }
        while(blue--) { //Insert blue lemmings
            scanf("%d", &soldier);
            bArmy.insert(soldier);
        }
        int results[100000] = {0}; //Aux array to keep track of battles' results
        while(!gArmy.empty() && !bArmy.empty()) { //Simulation of the war
            int i = 0;
            while(i < battlefields && !gArmy.empty()) { //Put most powerful green lemmings into the battlefields
                results[i++] = *gArmy.begin();
                gArmy.erase(gArmy.begin());
            }
            i = 0;
            while(i < battlefields && !bArmy.empty()) { //Put most powerful blue lemmings into the battlefields.
                results[i++] -= *bArmy.begin(); //Results of battles are computed as: green soldier's power - blue soldier's power
                bArmy.erase(bArmy.begin());
            }
            for(int j = 0; j < battlefields; j++) {
                if(results[j] > 0) { //If result positive, green won and blue died.
                    gArmy.insert(results[j]); //Reinsert surviving soldier's remaining power into army.
                } else if(results[j] < 0) { //If result negative, blue won and green died.
                    bArmy.insert(results[j] * (-1)); //Reinsert surviving soldier. -1 multiplication to turn value into positive
                }
                results[j] = 0; //Clean battlefield
            }
        }
        //Output results
        if(gArmy.empty() && bArmy.empty())
            printf("green and blue died\n");
        else if(gArmy.empty()) {
            printf("blue wins\n");
            for(auto lem : bArmy)
                printf("%d\n", lem);
        } else {
            printf("green wins\n");
            for(auto lem : gArmy)
                printf("%d\n", lem);
        }
        if(cases != 0)printf("\n");
    }
}
