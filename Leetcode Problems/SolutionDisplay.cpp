#include "solution.h"

// 1. Two Sum
void twoSumDisplay(vector<int> test_case, int target)
{
    static int case_no = 0;
    Solution two_sum_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input x = [";
    for (int num : test_case)
        cout << num << ",";
    cout << "], target = " << target << endl;

    cout << "Output: [";
    for (int i : two_sum_solution.twoSum(test_case, target))
        cout << i << ",";
    cout << "]\n";
}


// 9. Palindrome Number
void palindromeNumberDisplay(int test_cases)
{
    static int case_no = 0;
    Solution palindrome_number_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input x = " << test_cases << endl;

    string output = palindrome_number_solution.isPalindrome(test_cases) ? "True" : "False";
    cout << "Output: " << output << endl;
}


// 13. Roman to Integer
void romanToIntDisplay(string test_case)
{
    static int case_no = 0;
    Solution roman_to_int_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input a = " << test_case << endl;

    int output = roman_to_int_solution.romanToInt(test_case);
    cout << "Output: " << output << endl;
}


// 204. Count Primes
void countPrimesDisplay(int test_case)
{
    static int case_no = 0;
    Solution count_primes_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input n = " << test_case << endl;

    int output = count_primes_solution.countPrimes(test_case);
    cout << "Output: " << output << endl;
}


// 2427. Number of Common Factors
void commonFactorsDisplay(int test_cases_a, int test_case_b)
{
    static int case_no = 0;
    Solution common_factors_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input a = " << test_cases_a << ", b = " << test_case_b << endl;

    int output = common_factors_solution.commonFactors(test_cases_a, test_case_b);
    cout << "Output: " << output << endl;
}