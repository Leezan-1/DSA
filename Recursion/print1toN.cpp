#include "Recursion.h"

void Recursion::print1toN(int n)
{
    if (n < 0)
        return;

    print1toN(n - 1);
    cout << n << " ";
}