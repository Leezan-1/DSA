#include <iostream>

#include "Stack.h"

using namespace std;

ArrayStack::Numeric::Stack stack1;

void decimalToBinary(int number)
{
    while(number != 0)
    {
        int remainder = number % 2;
        stack1.push(remainder);
        number /= 2;
    }
}

int main()
{
    decimalToBinary(31);
    while (!stack1.isEmpty())
    {
        cout<< stack1.pop();
    }
    
    return 0;
}