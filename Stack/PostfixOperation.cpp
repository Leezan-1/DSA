#include <iostream>
#include <string>

#define STACK_SIZE 5
#define POSTFIX_EXP "34 4 + 4 5 - *"

using namespace std;

class Stack
{
private:
    int top, stack_array[STACK_SIZE];

public:
    Stack()
    {
        top = -1;
        for (size_t i = 0; i < STACK_SIZE; i++)
        {
            stack_array[i] = 0;
        }
    }

    bool isFull()
    {
        return (top == STACK_SIZE - 1) ? true : false;
    }

    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }

    int push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflown";
            return -1;
        }
        else
        {
            top++;
            stack_array[top] = val;
            return top;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int popped_value = stack_array[top];
            stack_array[top] = 0;
            top = top - 1;
            return popped_value;
        }
    }

    void display()
    {
        cout << "All values in the stack are" << endl;
        for (int i = STACK_SIZE - 1; i >= 0; i--)
        {
            cout << "|" << "\t" << stack_array[i] << "\t" << "|" << endl;
        }
        cout << "Top value is: " << top
             << endl;
    }
};

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
    cout<<"The final result of postfix expression is: "<<stack1.pop()<<endl;
    return 0;
}
