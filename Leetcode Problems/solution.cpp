#include "solution.h"

// 1. Two Sum
vector<int> Solution::twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; i < nums.size(); i++)
        {
            return {i, j};
        }
    }
    return {};

    /*

        Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

        You may assume that each input would have exactly one solution, and you may not use the same element twice.

        You can return the answer in any order.



        Example 1:

        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

        Example 2:

        Input: nums = [3,2,4], target = 6
        Output: [1,2]

        Example 3:

        Input: nums = [3,3], target = 6
        Output: [0,1]



        Constraints:

            2 <= nums.length <= 104
            -109 <= nums[i] <= 109
            -109 <= target <= 109
            Only one valid answer exists.


        Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
    */
}

// 9. Palindrome Number
bool Solution::isPalindrome(int x)
{
    if (x < 0)
        return false;

    long reverse = 0;
    int iterator = x;

    while (iterator != 0)
    {
        reverse = (reverse * 10) + (iterator % 10);
        iterator /= 10;
    }

    return (reverse == x) ? true : false;

    /*
        Given an integer x, return true if x is a
        palindrome
        , and false otherwise.



        Example 1:

        Input: x = 121
        Output: true
        Explanation: 121 reads as 121 from left to right and from right to left.

        Example 2:

        Input: x = -121
        Output: false
        Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

        Example 3:

        Input: x = 10
        Output: false
        Explanation: Reads 01 from right to left. Therefore it is not a palindrome.



        Constraints:
            -2^31 <= x <= 2^31 - 1

        Follow up: Could you solve it without converting the integer to a string?
    */
}

// 13. Roman to Integer
int Solution::mapSymbol(char sym)
{
    int value = 0;
    switch (sym)
    {
    case 'I':
        value = 1;
        break;

    case 'V':
        value = 5;
        break;

    case 'X':
        value = 10;
        break;

    case 'L':
        value = 50;
        break;

    case 'C':
        value = 100;
        break;

    case 'D':
        value = 500;
        break;

    case 'M':
        value = 1000;
        break;
    }
    return value;
}

int Solution::romanToInt(string s)
{
    int result = 0, a, b;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        a = mapSymbol(s[i]), b = mapSymbol(s[i + 1]);
        if (a < b)
            result -= mapSymbol(s[i]);

        else
            result += mapSymbol(s[i]);
    }

    result += mapSymbol(b);
    return result;

    /*
        13. Roman to Integer

        Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

        Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000

        For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

        Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

            I can be placed before V (5) and X (10) to make 4 and 9.
            X can be placed before L (50) and C (100) to make 40 and 90.
            C can be placed before D (500) and M (1000) to make 400 and 900.

        Given a roman numeral, convert it to an integer.
    */
}

// 204. Count Primes
bool Solution::checkPrime(int num)
{
    for (size_t i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    
    return true;
}

int Solution::countPrimes(int n)
{
    int count=0;
    for (size_t i = 2; i < n; i++)
    {
        if( checkPrime(i) )
            count++;
    }
    

    return count;
    /*
        204. Count Primes
        
        Given an integer n, return the number of prime numbers that are strictly less than n.

        

        Example 1:

        Input: n = 10
        Output: 4
        Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

        Example 2:

        Input: n = 0
        Output: 0

        Example 3:

        Input: n = 1
        Output: 0

        

        Constraints:

            0 <= n <= 5 * 106
    */

}

// 2427. Number of Common Factors
int Solution::commonFactors(int a, int b)
{
    int no_of_factors = 0, arr[10] = {0};

    int limit = (a > b) ? b : a;
    for (int i = 1; i <= limit; i++)
        if (a % i == 0 && b % i == 0)
            no_of_factors++;

    return no_of_factors;

    /*
        2427. Number of Common Factors

        Given two positive integers a and b, return the number of common factors of a and b.



        Example 1:

        Input: a = 12, b = 6
        Output: 4
        Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.

        Example 2:

        Input: a = 25, b = 30
        Output: 2
        Explanation: The common factors of 25 and 30 are 1, 5.



        Constraints:
            1 <= a, b <= 1000
    */
}
