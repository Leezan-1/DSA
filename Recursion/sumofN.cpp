#include "Recursion.h"

int Recursion::sumOfN(int n)
{
    if (n < 1)
        return 0;

    return n + sumOfN(n - 1);
}