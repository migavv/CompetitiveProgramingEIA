#include <bits/stdc++.h>

using namespace std;

int ro, flag = 1;

int main(){

    while(flag){

        scanf("%d", &ro);

        if(ro == -1) flag = 0;

        else{

            string wordS, triesS;
            unordered_set<char> tries;
            unordered_set<char> word;
            int count = 0, aux = 0;

            cin >> wordS >> triesS;

            for (size_t i = 0; i < wordS.length(); i++)
            {
                if(word.find(wordS[i]) == word.end()) word.insert(wordS[i]);
            }
            
            for (size_t i = 0; i < triesS.length(); i++)
            {
                if(!word.empty() && count < 7){
                    if(tries.find(triesS[i]) == tries.end()){
                        if(word.find(triesS[i]) != word.end()){
                            word.erase(triesS[i]);
                            tries.insert(triesS[i]);
                        }else {
                            tries.insert(triesS[i]);
                            count++;
                        }
                    }
                }
            }
            

            if(word.empty()) printf("Round %d\n%s\n", ro, "You win.");
            else{
                if(count < 7){
                    printf("Round %d\n%s\n", ro, "You chickened out.");
                }
                else{
                    printf("Round %d\n%s\n", ro, "You lose.");
                } 
            }
        }
    }
    return 0;
}