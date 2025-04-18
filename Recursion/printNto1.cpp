#include "Recursion.h"

void Recursion::printNto1(int n)
{
    if (n < 0)
        return;

    cout << n << " ";
    printNto1(n - 1);
}