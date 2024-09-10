#include <iostream>

using namespace std;

string reverse_string(string usr_string, int start, int end)
{
    if (start >= end)
        return usr_string;

    swap(usr_string[start], usr_string[end]);
    return reverse_string(usr_string, start + 1, end - 1);
}

int main()
{
    string user_string = "candna", reversed_string;

    cout << "Enter the string to reverse: " << user_string << endl;
    // cin >> user_string;

    // logic for string reversal
    int start = 0, end = user_string.length() - 1;
    reversed_string = reverse_string(user_string, start, end);


    cout << "The reverse of your string is: " << reversed_string << endl;

    if (reversed_string == user_string)
        cout<<"It is a palindrome!"<<endl;
    else
        cout<<"It is not a palindrome!"<<endl;

    return 0;
}