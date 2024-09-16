#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Dynamic size of memory is 5." << endl;
    n = 5;

    int *ptr = (int *)calloc(n, sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        int *var = ptr + i;
        *var = i+10;
    }

    // printing
    for (size_t i = 0; i < n; i++)
    {
        cout << *(ptr + i) << endl;
    }

    //memory is not free until end of program
}