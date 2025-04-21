#include "Recursion.h"

int Recursion::factorialOfN(int n)
{
    if (n < 1)
        return 1;

    return n * factorialOfN(n - 1);
}