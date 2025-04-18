#include "Recursion.h"

#include "print1toN.cpp"
#include "printNto1.cpp"
int main()
{
    int N = 5;

    cout << "print 0 to " << N << ": " << endl;
    Recursion::print1toN(5);
    cout << endl;
    cout << endl;
    cout << "print " << N << " to 0: " << endl;
    Recursion::printNto1(N);
    return 0;
}