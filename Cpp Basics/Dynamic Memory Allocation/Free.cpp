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

    free(ptr);//frees memory
    ptr = NULL;

    cout << "CREATING NEW DYNAMIC MEMORY ALLOCATION" << endl;
    n = 5;
    ptr = (int *)malloc( n * sizeof(int));

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
    free(ptr);
    ptr = NULL;
}