#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::string;
using std::vector;

#include "solution.cpp"

int main()
{
    // 1. Two Sum
    cout << "\n~~ 1. Two Sum  ~~\n";
    vector<int> ts_case1 = {2, 7, 11, 15}, ts_case2 = {3, 2, 4}, ts_case3 = {3, 3};
    int target1 = 9, target2 = 6, target3 = 6;

    twoSumDisplay(ts_case1, target1);
    twoSumDisplay(ts_case2, target2);
    twoSumDisplay(ts_case3, target3);

    // 9. Palindrome Number
    cout << "\n~~ 9. Palindrome Number ~~\n";
    int pn_case1 = 121, pn_case2 = -121, pn_case3 = 10;

    palindromeNumberDisplay(pn_case1);
    palindromeNumberDisplay(pn_case2);
    palindromeNumberDisplay(pn_case3);

    // 13. Roman to Integer
    cout << "\n~~ 13. Roman to Integer ~~\n";
    string rti_case1 = "III", rti_case2 = "LVIII", rti_case3 = "MCMXCIV", rti_case4 = "D";

    romanToIntDisplay(rti_case1);
    romanToIntDisplay(rti_case2);
    romanToIntDisplay(rti_case3);
    romanToIntDisplay(rti_case4);

    // 26. Remove Duplicates from Sorted Array
    cout << "\n~~26. Remove Duplicates from Sorted Array ~~\n";
    vector<int> rd_case1 = {1, 2, 2, 3, 4};
    vector<int> rd_case2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    removeDuplicateDisplay(rd_case1);
    removeDuplicateDisplay(rd_case2);

    // 204. Count Primes
    cout << "\n~~ 204. Count Primes ~~\n";
    int cp_case1 = 10, cp_case2 = 0, cp_case3 = 1;

    countPrimesDisplay(cp_case1);
    countPrimesDisplay(cp_case2);
    countPrimesDisplay(cp_case3);

    // 2427. Number of Common Factors
    cout << "\n~~ 2427. Number of Common Factors ~~\n";
    int ncf_case1[] = {12, 6}, ncf_case2[] = {25, 30}, ncf_case3[] = {1936, 2025};

    commonFactorsDisplay(ncf_case1[0], ncf_case1[1]);
    commonFactorsDisplay(ncf_case2[0], ncf_case2[1]);
    commonFactorsDisplay(ncf_case3[0], ncf_case3[1]);

    return 0;
}
