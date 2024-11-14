#include <iostream>
#include "Stack.h"
#include "ApplicationFunctions.h"

#define PREFIX_EXP "* - 5 4 + 10 + 4 34"
// space between each character is essential to correctly execute the oepration

using namespace std;

int main()
{
    string expression = PREFIX_EXP;
    size_t pos = expression.length(), previous_pos, gap_between_space;

    ArrayStack::Stack prefix_stack;

    cout << "The prefix expression is: " << expression << endl
         << endl;

    while (pos != string::npos)
    {
        previous_pos = pos;
        pos = expression.rfind(' ', pos - 1);
        gap_between_space = previous_pos - pos;

        string token;

        if (pos != string::npos)
            token = expression.substr(pos + 1, gap_between_space - 1);
        else
            token = expression.substr(0, gap_between_space -1);

        cout << endl
             << token << endl;

        try
        {
            size_t number = stoi(token);
            prefix_stack.push(number);
        }
        catch (const invalid_argument &e)
        {
            string operatorr = token;

            if (operatorr != " " and !operatorr.empty())
            {
                int second_operand = prefix_stack.pop();
                int first_operand = prefix_stack.pop();
                int resultt = arthematicOperation(first_operand, second_operand, operatorr);
                prefix_stack.push(resultt);
            }
        }
    }

    int final_result = prefix_stack.pop();
    cout << endl
         << "The final result of prefix expression is: " << final_result << endl;
    return 0;
}
