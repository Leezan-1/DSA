#include <iostream>

using namespace std;

bool checkPrimeNumber(int num)
{
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int countPrime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (checkPrimeNumber(i))
        {
            cout << i << " ";
            count++;
        }
    }

    return count;
}
int main()
{
    cout << countPrime(20);
    return 0;
}
