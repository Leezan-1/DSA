#include <iostream>

using namespace std;

int main()  
{
    int *ptr = new int(5);
    cout << "Dynamically allocated integer: " << *ptr << endl;

    int size;
    cout << "Enter the size of array ";
    cin >> size;

    int *arr = new int[size];
    for (int i=0; i<size; i++)
    {
        arr[i] = i+1;
    }

    cout << "Dynamically allocated array:" <<endl;

    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    //deleting dynamic memory
    delete ptr;
    delete arr;

    ptr = nullptr;
    arr = nullptr;
}