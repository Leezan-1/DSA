#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"
#include "usefulFunctions.cpp"

vector<int> Solution::plusOne(vector<int> &digits)
{
    return digits;
}
void plusOneDisplay(vector<int> &digits)
{
    Solution solution;
    static int count = 0;

    cout << "Input: digits = ";
    displayArray(digits);
    cout << "Output : ";

    vector<int> result = solution.plusOne(digits);
    displayArray(result);
}

int main()
{
    vector<int> po_case1 = {1, 2, 3};

    plusOneDisplay(po_case1);
}
