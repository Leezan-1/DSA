#ifndef SOLUTION_H
#define SOLUTION_H

class Solution
{
private:
    int mapSymbol(char sym);

    bool checkPrime(int num);

public:
    // 1. Two Sum
    vector<int> twoSum(vector<int> &nums, int target);

    // 9. Palindrome Number
    bool isPalindrome(int x);

    // 13. Roman to Integer
    int romanToInt(string s);

    // 26. Remove Duplicates from Sorted Array
    int removeDuplicates(vector<int> &nums);

    // 66. Plus One
    vector<int> plusOne(vector<int> &digits);

    // 204. Count Primes
    int countPrimes(int n);

    // 2427. Number of Common Factors
    int commonFactors(int a, int b);
};

#endif