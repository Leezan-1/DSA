#include "Solution.h"
#include "TwoSum.cpp"
#include "PalindromeNumber.cpp"

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
    return 0;
}