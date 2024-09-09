#include <iostream>

using namespace std;

int factorial(int n)
{
    return 0; 
}

int main()
{
    size_t number;

    // User Input
    cout<<"Enter the number that you want to find factorial of: ";
    cin>>number;


    // Final Output
    cout<<number<<"! is: "<<factorial(number)<<endl;
    return 0;
}