#include <iostream>
using namespace std;

#include "Stack.h"

LinkedListStack::Stack stack1;

void primeFactorization(int number)
{
    int i = 2;

    while (number != 1)
    {
        while (number % i == 0)
        {
            stack1.push(i);
            number = number / i;
        }
        i++;
    }
}
int main()
{
    unsigned int number=2048;
    cout << "Enter the number to be prime factorized!: ";
    cout << number << endl;
    primeFactorization(number);
    cout << "The prime factors are in descending order: \n";
    while (!stack1.isEmpty())
        cout << stack1.pop() << " ";

    return 0;
}
