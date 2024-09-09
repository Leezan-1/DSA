#include <iostream>

using namespace std;

unsigned int fibonacci(int n)
{

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    unsigned  int length = 30;

    // User Input
    cout << "Enter the length of fibonacci series: ";
    cin>>length;

    // Final Output 
    cout << "The fibonacci sequences are: ";
    for (size_t i = length; i >= 0; i--)
    {
        if (i == 0)
            cout << fibonacci(i)<<endl;
        else
            cout << fibonacci(i) << ", ";
    }

    return 0;
}
