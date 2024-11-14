#include <iostream>
#include <string>
#include "Stack.h"
#include "ApplicationFunctions.h"

#define POSTFIX_EXP "34 4 + 10 + 4 5 - *"
// space between each character is essential to correctly execute the oepration


using namespace std;
int main()
{

    size_t pos = 0, previous_pos, gap_between_space, number;
    
    ArrayStack::Stack postfix_stack;

    string expression = POSTFIX_EXP;
    cout << "The postfix expression is: " << POSTFIX_EXP << endl
         << endl;
    while (pos != string::npos)
    {
        previous_pos = pos;
        pos = expression.find(' ', pos + 1);
        gap_between_space = pos - previous_pos;
        
        try
        {
            size_t number = stoi(expression.substr(previous_pos, gap_between_space));
            postfix_stack.push(number);
        }
        catch (const invalid_argument &e)
        {
            string operatorr = expression.substr(previous_pos, gap_between_space);

            if (operatorr != " ")
            {
                int second_operand = postfix_stack.pop();
                int first_operand = postfix_stack.pop();

                int resultt = arthematicOperation(first_operand, second_operand, operatorr);
                postfix_stack.push(resultt);
            }
        }
    }

    int final_result = postfix_stack.pop();
    cout << endl
         << "The final result of postfix expression is: " << final_result << endl;
    return 0;
}
