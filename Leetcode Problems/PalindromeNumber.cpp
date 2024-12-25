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
}

void palindromeNumberDisplay(int test_cases)
{
    static int case_no = 0;
    Solution palindrome_number_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input x = " << test_cases << endl;

    string output = palindrome_number_solution.isPalindrome(test_cases) ? "True" : "False";
    cout << "Output: " << output << endl;
}

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