#include <iostream>

using namespace std;

int *findMid(int a[], int n)
{
    return &a[n/2];   
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<sizeof(arr)<<endl<<sizeof(arr[0])<<endl<<sizeof(int)<<endl;
    int *mid = findMid(arr, n);
    cout<<*mid;
    return 0;
}
