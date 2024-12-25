#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl, std::vector, std::size_t, std::string;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target);

    bool isPalindrome(int x);
};

#endif