// # Given an integer x, return true if x is a palindrome
#include "Solution.h"

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

void palindromeNumberDisplay()
{
    cout << "\n~~ Palindrome Number ~~\n";
    int integer = 121;
    Solution palindrome_number_solution;
    string result = palindrome_number_solution.isPalindrome(integer) ? "True" : "False";
    cout << "The number is a palindrome: " << result << endl;
}