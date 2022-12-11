
#include<string>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<unordered_map>

using namespace std;

int main() {
    int frosh, nStudents, maxPop, currPop; //Frosh: Number of students
    while(scanf("%d", &frosh), frosh != 0) {
        unordered_map<string, int> combinations; //map for storing course combinations and their respective frequencies
        int combination[5];//Aux array for sorting combinations
        while(frosh--) {
            for(int & i : combination)
                scanf("%d", &i);
            sort(combination, combination + 5); //Combinations are sorted so repeated ones are noticed
            stringstream mapEntry; //aux object to transform combination array into a string
            for(int & i : combination)
                mapEntry << i;
            combinations[mapEntry.str()]++; //Insertion in map
        }
        nStudents = 0; //Number of students who chose the most popular combination, or combinations in case
                            // there are more than one combination tied as most popular
        maxPop = 0; //Popularity of the most popular combination(s)
        for(auto const& pair : combinations) { //Iterating the map looking for the most popular combination
            currPop = pair.second; //Popularity of the current map entry in the iteration
            if(currPop == maxPop) //In case there is a tie
                nStudents += currPop; //The number of students of all tied combinations counts
            else if(currPop > maxPop) { //if a more popular combination is founded
                maxPop = currPop; //maxPop replaced
                nStudents = currPop; //nStudents reset
            }
        }
        printf("%d\n", nStudents);
    }
}
