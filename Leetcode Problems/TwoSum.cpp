std::vector<int> Solution::twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; i < nums.size(); i++)
        {
            return {i, j};
        }
    }
    return {};
}

void twoSumDisplay()
{
    Solution twoSumSolution;
    vector<int> nums = {3, 2, 4};
    int target = 6;

    cout << "The indices that add upto " << target << " is : [";
    for (int i : twoSumSolution.twoSum(nums, target))
        cout << i << ",";
    cout << "]\n";
}