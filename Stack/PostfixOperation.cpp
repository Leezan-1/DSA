#include <iostream>
#include <string>
#include "Stack.cpp"

#define POSTFIX_EXP "34 4 + 4 5 - *"

using namespace std;


int postfixOperation(int first_operand, int second_operand, string operators)
{
    int result = 0;

    if (operators == " +")
    {
        result = first_operand + second_operand;
    }
    else if (operators == " -")
    {
        result = first_operand - second_operand;
    }
    else if (operators == " *")
    {
        result = first_operand * second_operand;
    }
    else if (operators == " /")
    {
        result = first_operand / second_operand;
    }
    else if (operators == " %")
    {
        result = first_operand % second_operand;
    }
    else
    {
        cout << "Invalid operator: " << operators << endl;
    }

    return result;
}

int main()
{

    size_t pos = 0, previous_pos, length, number;
    Stack stack1;

    string expression;
    expression.append(POSTFIX_EXP);

    while (pos != string::npos)
    {
        previous_pos = pos;
        pos = expression.find(' ', pos + 1);
        length = pos - previous_pos;
        try
        {
            size_t number = stoi(expression.substr(previous_pos, length));
            stack1.push(number);
        }
        catch (const invalid_argument &e)
        {
            string operatorr = expression.substr(previous_pos, length);

            if (operatorr != " ")
            {
                int second_operand = stack1.pop();
                int first_operand = stack1.pop();

                int resultt = postfixOperation(first_operand, second_operand, operatorr);
                stack1.push(resultt);
            }
        }
    }
    
    stack1.display();
    int final_result = stack1.pop();
    cout<<"The final result of postfix expression is: "<<final_result<<endl;
    return 0;
}
