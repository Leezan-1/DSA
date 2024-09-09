#include <iostream>

using namespace std;

size_t factorial(size_t n)
{

    if (n == 0)
    {
        cout << "0! = ";
        return 1;
    }
    else
    {
        cout << n << " x ";
        return n * factorial(n - 1);
    }
}

int main()
{
    size_t number;

    // User Input
    cout << "Enter the number that you want to find factorial of: ";
    cin>>number;

    // Final Output
    cout << endl
         << number << "! = " << factorial(number) << endl;
    return 0;
}