#include <iostream>

using namespace std;

struct Self
{
    int data;
    struct Self *link;
};

int main()
{
    struct Self var1, var2;

    var1 = {10, NULL};
    var2 = {20, NULL};

    var1.link = &var2;
    var2.link = &var1;

    cout << var1.data << "\t" << var1.link << endl;
    int help =  (int)var1.link->link->data;

    cout<<help;
    return 0;
}