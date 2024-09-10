#include <iostream>

using namespace std;

string reverse_string(string usr_string, int start, int end)
{
    cout<<usr_string<<start<<end<<endl;
    if (start >= end)
        return usr_string;
    
    cout<<usr_string[0];
    return "ABC";

}

int main()
{
    string user_string = "ABC", reversed_string;

    cout << "Enter the string to reverse: "<<user_string<<endl;;
    // cin >> user_string;

    int start =0, end =  user_string.length()-1;

    reversed_string = reverse_string(user_string, start, end);
    cout << "The reverse of your string is: " << reversed_string<<endl;
    return 0;
}