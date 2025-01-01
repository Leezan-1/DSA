#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "stack.h"

string removeSpace(const string &expression)
{
    string exp;
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (!isspace(expression[i]))
            exp += expression[i];
    }
    return exp;
}

bool checkBrackets(string &expression)
{
    LinkedListStack::Character::Stack bracket_stackk;
    for (auto i = expression.begin(); i < expression.end(); i++)
    {
        if (*i == '{' || *i == '[' || *i == '(')
            bracket_stackk.push(*i);

        else if (*i == '}' || *i == ']' || *i == ')')
        {
            if (bracket_stackk.isEmpty())
            {
                cerr << "Invalid expression!: Right brackets are more than left brackets" << endl;
                return false;
            }
            else
            {
                char left_bracket = bracket_stackk.pop();
                if ((left_bracket == '{' && *i != '}') ||
                    (left_bracket == '(' && *i != ')') ||
                    (left_bracket == '[' && *i != ']'))
                {
                    cerr << "Invalid expression!: Mismatched brackets!" << endl;
                    return false;
                }
            }
        }
    }
    if (bracket_stackk.isEmpty())
    {
        return true;
    }
    else
    {
        cerr << "Invalid expression!: Left brackets are more than right brackets" << endl;
        return false;
    }
}

int checkPrecedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
    case '%':
        return 2;

    case '+':
    case '-':
        return 1;

    default:
        return 0;
        break;
    }
}

string infixToPrefix(const string &infix_exp)
{
    LinkedListStack::Character::Stack operator_stackk; // A stack to store operator is initialized
    string prefix_exp, number;                         // number is used to separate from string which will be added in exprssion

    for (size_t i = 0; i < infix_exp.length(); i++)
    // Scanning the expression from left to right
    {
        char symbol = infix_exp[i];

        // we need to separate if the sybol is number or not and separate multidigit number with space
        if (std::isdigit(symbol)) // this checks if the symbol is a number.
            number += symbol;     // the number var concats symbol

        else // if symbol is not a number, is any character
        {
            if (!number.empty())                        // if number var is not empty it means there is a number that
            {                                           //  needs to be concatinated with postfix expression
                prefix_exp = " " + number + prefix_exp; // this concatinates each number in pf exp. with space in btwn
                number.clear();                         // number needs to be cleared.
            }

            // if (std::isspace(symbol)) // if the character is space then
            // {
            //     if (isdigit(infix_exp[i + 1]) && isspace(infix_exp[i - 1])) // we check if there are many spaces between the number
            //     {
            //         // if it is a number after space  then it is an invalid expression
            //         cerr << "Invalid expression!: Missing operator between numbers";
            //         exit(1);
            //     }
            //     continue; // else we are cleared! jump to next character
            // }

            // Check of other arthematic operators
            switch (symbol)
            {

            // If it is a left bracket, immediately push into stack
            case '(':
            case '{':
            case '[':
                operator_stackk.push(symbol);
                break;

            // If it is a right bracket, the pop all the character from the operator stack until we get leftbracket operator '('. Discard '()' both brackets
            case ')':
            {
                char operatorr;
                while ((operatorr = operator_stackk.pop()) != '(')
                    prefix_exp = operatorr + prefix_exp;

                break;
            }
            case '}':
            {
                char operatorr;
                while ((operatorr = operator_stackk.pop()) != '{')
                    prefix_exp = operatorr + prefix_exp;

                break;
            }
            case ']':
            {
                char operatorr;
                while ((operatorr = operator_stackk.pop()) != '[')
                    prefix_exp = operatorr + prefix_exp;

                break;
            }

            // If the symbol is an arthematic operator, then:
            // - If the precedence of the operator in stack is greater than the current symbol's precedence
            //  then, pop the operator from the stack and keep it in postfix operatora and push the operator in the stack.
            // - Else, Push the current symbol to the stack.
            // Else it is an invalid symbol.
            case '^':
            case '*':
            case '/':
            case '%':
            case '+':
            case '-':
                while (!operator_stackk.isEmpty() && checkPrecedence(operator_stackk.peek()) >= checkPrecedence(symbol))
                    prefix_exp = operator_stackk.pop() + prefix_exp;
                operator_stackk.push(symbol);
                break;

            default:
                cerr << "Invalid character encountered!" << endl;
                std::exit(1);
                break;
            }
        }
    }
    // If the string has finished scanning and

    // Then, first check if there is number left to concat in expresssion. if true: concat it.
    if (!number.empty())
        prefix_exp = " " + number + prefix_exp;

    // Then check if there are operators in the stack, if there is add to the expression
    while (!operator_stackk.isEmpty())
        prefix_exp = operator_stackk.pop() + prefix_exp;

    return prefix_exp;
}

int arthematicOperation(int first_operand, int second_operand, char operatorr)
{
    switch (operatorr)
    {
    case '+':
        return first_operand + second_operand;

    case '-':
        return first_operand - second_operand;

    case '*':
        return first_operand * second_operand;

    case '/':
        if (second_operand != 0)
            return first_operand / second_operand;
        else
        {
            cerr << "Invalid Expression!: Division by zero" << endl;
            exit(1);
        }

    case '%':
        return first_operand % second_operand;

    case '^':
        return first_operand ^ second_operand;

    default:
        std::cerr << "Invalid Operator";
        std::exit(1);
    }
}

void reverseStringInPlace(std::string &stringToReverse)
{
    int numCharacters = stringToReverse.length();
    for (int i = 0; i < numCharacters / 2; i++)
    {
        std::swap(stringToReverse[i], stringToReverse[numCharacters - i - 1]);
    }
}

int prefixOperation(const string &prefix_exp)
{
    LinkedListStack::Numeric::Stack operand_stackk; // initalize a stack to store operand
    string number;

    for (int i = prefix_exp.length() - 1; i >= 0; i--)
    // iterate each character in the expression
    {
        char ch = prefix_exp[i];
        if (std::isdigit(ch))
            number += ch;
        else
        {
            if (!number.empty())
            {
                reverseStringInPlace(number);
                operand_stackk.push(stoi(number));
                number.clear();
            }
            if (!std::isspace(ch))
            {
                int operand1 = 0, operand2 = 0;
                operand2 = operand_stackk.pop();
                operand1 = operand_stackk.pop();

                operand_stackk.push(arthematicOperation(operand1, operand2, ch));
            }
        }
    }
    return operand_stackk.pop();
}

int main()
{
    cout << "Program: Infix expression to Prefix and its evaluation\n"
         << endl;
    string expression = "8 * (5 ^ 4 + 2) - 6^2 / (9+3)";
    expression = removeSpace(expression);

    cout << "Input expression: " << expression << endl;
    if (checkBrackets(expression))
    {
        expression = infixToPrefix(expression);
        cout << "Resultant prefix expression: " << expression << endl
             << "Final result: " << prefixOperation(expression) << endl;
    }
    return 0;
}