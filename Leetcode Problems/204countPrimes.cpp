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

bool Solution::checkPrime(int num)
{
    for (size_t i = 2; i < num; i++)
        if (num % i == 0)
            return false;

    return true;
}

int Solution::countPrimes(int n)
{
    int count = 0;
    for (size_t i = 2; i < n; i++)
    {
        if (checkPrime(i))
            count++;
    }

    return count;
}