#include "Recursion.h"

// #include "print1toN.cpp"
// #include "printNto1.cpp"
// #include "sumofN.cpp"
int main()
{
    int N = 5;
    int power = 3;

    cout << "~~Recursion~~" << endl;

    cout << "print 0 to " << N << ", recursively: " << endl;
    Recursion::print1toN(N);

    cout << endl
         << "\nprint " << N << " to 0, recursively: " << endl;
    Recursion::printNto1(N);

    // Recursion::sumOfN(5);
    int sum = Recursion::sumOfN(N);
    cout << endl
         << "\nThe sum of " << N << " natural numbers is: " << sum << endl;

    int fct = Recursion::factorialOfN(N);
    cout << endl
         << "\nThe factorial of " << N << " is: " << fct << endl;

    int res = Recursion::powerFunction(N, power);
    cout << endl
         << "\nThe result of " << N << " ^ " << 2 << " is: " << res << endl;

    return 0;
}