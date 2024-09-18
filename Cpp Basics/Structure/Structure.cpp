#include <iostream>

using namespace std;

typedef struct dog
{
    string gender;
    int a[5];
}dog;

int main()
{
    dog moomin, lucy;
    moomin.gender="Female";
    moomin.a[0]=1;
    lucy.gender="Female";
    cout << moomin.gender<<"\t"<<moomin.a[0];
     return 0;
}