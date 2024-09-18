#include <iostream>

using namespace std;

int *input(int length)
{
    int *ptr = (int *)malloc(length * sizeof(int)); //declared here
    for (size_t i = 0; i < length; i++)
    {
        int *var = ptr + i;
        *var = i+1;
    }
    return ptr;
}

int main()
{
    int n, *pointer;
    cout << "Dynamic size of memory is 5." << endl;
    n = 5;

    pointer = input(n);
    

    // printing
    for (size_t i = 0; i < n; i++)
    {
        cout << *(pointer + i) << "\t";
    }

    free(pointer);//but the memory is freed here
    pointer = NULL;

}