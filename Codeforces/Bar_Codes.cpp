#include <iostream>
#include <tuple>
#include <map>

using namespace std;

unsigned long long numberOfCombination(int n, int k, int m);

map <tuple<short int, short int, short int>, unsigned long long> results;

/**
 * This exercise is about "Bar codes". For this im going to explain four things. The bar codes in the exercise are represented in 1 and 0, each bar code always starts
 * with a 1. Each bar code will contain n bars (1 or 0), k columns (each column is the set of bars of the same number that are adjacent) and each column can contain at MAX 
 * m bars. With this an example of a bar code that follows n = 9, k = 5, m = 3 would be 110001001.
 * 
 * So the exersice is for a given n, k, m combination, return the number of bar codes that follow this constraint.
 * 
 * Example: the combination n = 5, k = 4, m = 2 has only 4 posible bar codes, wich are the following:
 * 
 *      first: 10010    second: 10100   third: 10110    fourth: 11010
 * 
 * That is basically the exercise.
 * 
 * My approach:
 *      I basically saw that the number of posibilities of bar codes for a given n, k, m is the same as adding the number of bar codes that are possible when the first column
 *      of 1's has a lenght of 1, then addign the number of posibilities when the first column has a lenght of 2, then a lenght of 3, until the first column has a lenght of m.
 *      This may seem very obvious, but the thing is that what remains after you "remove" the first column is still a bar code, but that this time starts with 0, so then we 
 *      abstract away that fact, and just search for the number of posible combination that smaller bar code has. That is the recursion of this problem.
 *      
 *      This fact is more visible in the problem pdf since it shows the combination 7, 4, 3, and it's 16 posible ways, but still it can bee seen with the example above.
 *      When the first column of 1's only has a lenght of 1, it can form 3 bar codes: 10010, 10100, 10110 then we substract the 1, and its like having the combination
 *      6, 3, 3 but this time starting with ceros, this combination has 3 posibilities: 1101, 1011, 1001, if we flip the 1 and 0, you will see that is efectively the same.
 *      so we do this over and over again until we hit the base cases and eventually get the answer.
 * 
 * Base cases:
 *      There are base cases that tell us that it does not exist a bar code that follows this combination, and combinations that only one bar follows.
 *      Base cases that does not exist:
 *          when n < k, since we are tryng to make more columns than bars in existance.
 *          when k*m < n, since the number of columns times the maximum column size (the maximum lenght we can achieve) is less than the number of bars that are set to exist.
 * 
 *      Base cases that are only followed by one:
 *          when wither n, k or m are 1, since if n == 1 there's is only one bar, so the only way to get one bar is having one bar, k == 1 because having only one column means
 *              that all bars are 1, m == 1 because it means that the bar code is going to be alternating 1's and 0's.
 *          when n == k, because the only way to have the same number of columns as bars, is that each column is only one bar, the same as having m == 1.
 *      
*/


int main()
{
    // Variables to use
    short int n, k, m;

    // Do the work
    while (scanf("%hd %hd %hd", &n, &k, &m) != EOF)
    {
        printf("%llu\n", numberOfCombination(n, k, m));
    }

    return 0;
}

// Counts the number of posible ways of solving
unsigned long long numberOfCombination(int n, int k, int m)
{
    // Cases that are not able to make a combination
    if (n < k || (k * m) < n)
        return 0;


    // Base cases
    else if (n == 1 || k == 1 || n == k || m == 1)
        return 1;

    // Make the tuple for the current combination, to be searched / used in the map 
    tuple<short int, short int, short int> currentCombination = make_tuple(n, k, m);

    // Check if the combination has been already solved
    if (results.count(currentCombination) != 0)
    {
        return results[currentCombination];
    }
    unsigned long long result = 0;

    // Make the work
    for (int i = 1; i <= m; i++)
    {
        result += numberOfCombination(n - i, k - 1, m);
    }

    // Add the result to the map and return
    results[currentCombination] = result;
    return result;
}
