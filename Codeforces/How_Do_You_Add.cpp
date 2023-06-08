#include <iostream>
#include <map>

using namespace std;

long countCombinations(int N, int K);

/**
 * The Excersize is to find how many ways are there of making a sum of K numbers as to the result of the sum equals N
 * 
 * So the way I thought of solving it was by this:
 *      As the pdf of the question suggest, you should start by making N + 1 sums, and for the first place of each sum you start putting from 0 to N in there, as to the
 *      example below.
 *          N = 3, K = 3
 *          _0_ + ___ + ___ = 3
 *          _1_ + ___ + ___ = 3
 *          _2_ + ___ + ___ = 3
 *          _3_ + ___ + ___ = 3
 * 
 *      When you do this you perhaps see a pattern, and it is that the number of ways that the combination has, is the sum of all the combinations of ways that those blank spaces add 
 *      up to N - (number in first spot), for example, in the case above, for the second ecuation, the number of ways that ecuation can go, is the number of ways those blank spaces 
 *      can add up to 2 "(3 - 1)", and the same applies for all of the four ecuations.
 * 
 *      Recursive Method that does the work: 
 *      The explanation above is the logic behind the recursion I made, basically, for each starting number of that ecuation, I find the number of ways the remaining black spaces can add 
 *      up to N - (number in first spot), and add all of those result together, as to get the result of the <N, K> case.
 *      For this recursion the base cases are gonna be if N == 0, since the only way to make a sum of positive number to add up to cero (independently of how many numbers compose the sum)
 *      is for every number to be cero, then if N == 0, the number of posible combinations is 1. The other base case is if K == 1, this because if we have a sum of only one number, and
 *      that number needs to be another number X, the only way for that one number sum to add to X, is if the only number in the sum equals X (Mathematically if _Y_ = X, then for this to
 *      be true, Y must be X), therefore the total number of combinations is only 1.
 * 
 *      Store Previous Results:
 *      Since doing this leads to repeating again and again certain <N, K> cases, we can store the results of that cases in a map, the key of that map would be a pair <N, K>. In the
 *      recurse method first we check for base cases, and then we check if that <N, K> case is in the map, else we compute the result and store it in the map for future use, that way 
 *      we do not have to compute over and over again cases, leading to the program being time efficient.
 * 
 *      If curious, the result of the N = 3 and K = 3 case is 10
*/

// Stores the result for a given <N, K> combination
map < pair <int,int>, long> combinations;
const int mod = 1000000;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    // Stop the program when the input is "0 0"
    while (N != 0 && K != 0)
    {
        cout << countCombinations(N, K) % mod << endl;

        scanf("%d %d", &N, &K);
    }

    return 0;
}

/**
 * Counts the numbers of ways to sum K positive numbers that result in N
*/
long countCombinations(int N, int K)
{
    // Base cases
    if (N == 0 || K == 1)
    {
        return 1;
    }

    pair<int, int> currentPair = make_pair(N, K);
    // Check if the combination has already been calculated
    if (combinations.count(currentPair) != 0)
    {
        return combinations[currentPair];
    }

    // Stores the number of combinations 
    long counter = 0;

    // Goes for every posible combination
    for (int i = N; i >= 0; i--)
    {
        counter += countCombinations(N - i, K - 1) % mod;
    }

    // Place the new combination in the map
    combinations[currentPair] = counter;
    return counter;    

}
