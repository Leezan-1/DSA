#include <iostream>
#define PI 1234

using namespace std;

int main()
{
    // Different Data Types
    int integer = 15;
    float floating = 1.5;
    char alphabet = 'A';
    bool boolean = true;

    cout << "Integer result:" << integer << endl;
    cout << "Floating result:" << floating << endl;
    cout << "String Characters:" << alphabet << endl;
    cout << "Boolean:" << boolean << endl;

    //  Type conversions

    //  Implicit Conversion
    int result = integer + floating;
    cout << result << endl;

    // Explicit Conversion
    result = (int)floating;
    cout << result << endl;
    cout << PI<<endl;


    cerr << "Error: Something went wrong!" << endl; // Outputs an error message

    return 0;
}