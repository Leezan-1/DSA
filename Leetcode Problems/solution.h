#ifndef SOLUTION_H
#define SOLUTION_H

class Solution
{
private:
    int mapSymbol(char sym);

    bool checkPrime(int num);
    
public:
    vector<int> twoSum(vector<int> &nums, int target);

    bool isPalindrome(int x);

    int commonFactors(int a, int b);

    int romanToInt(string s);

    int countPrimes(int n);
};

#endif