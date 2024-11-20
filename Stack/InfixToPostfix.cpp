#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "Stack.h"

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

string infixToPostfix(const string &infix_exp)
{
    LinkedListStack::Character::Stack operator_stackk; // A stack to store operator is initialized
    string postfix_exp, number;                        // number is used to separate from string which will be added in exprssion

    for (size_t i = 0; i < infix_exp.length(); i++)
    // Scanning the expression from left to right
    {
        char symbol = infix_exp[i];

        // we need to separate if the sybol is number or not and separate multidigit number with space
        if (std::isdigit(symbol)) // this checks if the symbol is a number.
            number += symbol;     // the number var concats symbol

        else // if symbol is not a number, is any character
        {
            if (!number.empty())             // if number var is not empty it means there is a number that
            {                                //  needs to be concatinated with postfix expression
                postfix_exp += number + " "; // this concatinates each number in pf exp. with space in btwn
                number.clear();              // number needs to be cleared.
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
                {
                    postfix_exp += operatorr;
                    postfix_exp += ' ';
                }
                break;
            }
            case '}':
            {
                char operatorr;
                while ((operatorr = operator_stackk.pop()) != '{')
                    postfix_exp += operatorr;
                break;
            }
            case ']':
            {
                char operatorr;
                while ((operatorr = operator_stackk.pop()) != '[')
                    postfix_exp += operatorr;
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
                    postfix_exp += operator_stackk.pop();
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
        postfix_exp += number + " ";

    // Then check if there are operators in the stack, if there is add to the expression
    while (!operator_stackk.isEmpty())
        postfix_exp += operator_stackk.pop();

    return postfix_exp;
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

int postfixOperation(const string &postfix_exp)
{
    LinkedListStack::Numeric::Stack operand_stackk; // initalize a stack to store operand
    string number;

    for (size_t i = 0; i < postfix_exp.length(); i++)
    // iterate each character in the expression
    {
        char ch = postfix_exp[i];
        if (std::isdigit(ch))
            number += ch;
        else
        {
            if (!number.empty())
            {
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
    cout << "Program: Infix expression to Postfix and its evaluation\n"
         << endl;
    string expression = "((1   0+    5)*3)";
    expression = removeSpace(expression);

    cout << "Input expression: " << expression << endl;
    if (checkBrackets(expression))
    {
        expression = infixToPostfix(expression);
        cout << "Resultant postfix expression: " << expression << endl
             << "Final result: " << postfixOperation(expression) << endl;
    }
    return 0;
}