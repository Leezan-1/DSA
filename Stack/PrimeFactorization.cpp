#include <iostream>
using namespace std;

#include "Stack.h"

LinkedListStack::Numeric::Stack stack1;

bool checkPrimeNumber(int number)
{
    int remainder;
    for (size_t i = 2; i < number; i++)
    {
        remainder = number % i;

        if (remainder == 0)
            return false;
    }
    return true;
}

void primeFactorization(int number, int *arr)
{
    int i = 2;
    int j = 0;

    while (number != 1)
    {
        while (number % i == 0)
        {
            arr[++j] = i;
            stack1.push(i);
            number = number / i;
        }
        i++;
    }
}
int main()
{
    int arr[20] = {0};
    unsigned int number = 1936;
    cout << "Enter the number to be prime factorized!: ";
    cout << number << endl;
    primeFactorization(number, arr);
    cout << "The prime factors are in descending order: \n";
    while (!stack1.isEmpty())
        cout << stack1.pop() << " ";

    cout << endl;
    for (int i = 19 ; i >= 0; --i)
    {
        if(arr[i] != 0)
            cout<<arr[i]<<" ";
    }

    return 0;
}
