#include <iostream>
#include <string>

#define STACK_SIZE 20
#define POSTFIX_EXP " 34 4 + 4 5 - *"

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
            top--;
            return popped_value;
        }
    }

    void display()
    {
        cout << "All values in the stack are" << endl;
        for (int i = STACK_SIZE-1; i >= 0; i--)
        {
            cout << "|" << "\t" << stack_array[i] << "\t" << "|" << endl;
        }
        cout << endl
             << endl;
    }
};

