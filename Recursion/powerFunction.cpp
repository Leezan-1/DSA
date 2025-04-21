#include "Recursion.h"

int Recursion::powerFunction(int n, int p)
{
    if (p < 1)
        return 1;

    return n * powerFunction(n, p - 1);
}