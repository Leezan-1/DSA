#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Dynamic size of memory is 5." << endl;
    n = 5;

    int *ptr = (int *)malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        int *var = ptr + i;
        *var = i;
    }

    // printing
    for (size_t i = 0; i < n; i++)
    {
        cout << *(ptr + i) << endl;
    }

    cout << "reallocating size" << endl;
    n = 10;
    ptr = (int *)realloc(ptr, n * sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        int *var = ptr + i;
        *var = i;
    }

    // printing
    for (size_t i = 0; i < n; i++)
    {
        cout << *(ptr + i) << endl;
    }
}