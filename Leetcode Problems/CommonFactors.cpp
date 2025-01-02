#include "Solution.h"

int Solution::commonFactors(int a, int b)
{
    int no_of_factors = 0, arr[10] = {0};

    int limit = (a > b) ? b : a;
    for (int i = 1; i <= limit; i++)
        if (a % i == 0 && b % i == 0)
            no_of_factors++;

    return no_of_factors;
}

void commonFactorsDisplay(int test_cases_a, int test_case_b)
{
    static int case_no = 0;
    Solution common_factors_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input a = " << test_cases_a << ", b = " << test_case_b << endl;

    int output = common_factors_solution.commonFactors(test_cases_a, test_case_b);
    cout << "Output: " << output << endl;
}

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