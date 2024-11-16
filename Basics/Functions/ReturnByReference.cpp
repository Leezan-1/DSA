#include <iostream>

using namespace std;

int& larger(int &a, int &b)
{
    return ( a > b )? a : b;
}