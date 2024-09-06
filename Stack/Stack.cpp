#include <iostream>

#define STACK_SIZE 10

using namespace std;

class Stack
{
private:
    int top, stack_array[STACK_SIZE];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < STACK_SIZE; i++)
        {
            stack_array[i] = 0;
        }
        cout << "New Stack Created of size: " << STACK_SIZE << endl;
    }

    ~Stack()
    {
        cout << "Stack Destroyed" << endl;
    }

    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }

    bool isFull()
    {
        return (top == STACK_SIZE - 1) ? true : false;
    }

    int push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return 0;
        }
        else
        {
            top++;
            stack_array[top] = val;
            cout << val << " is pushed at position " << top << " of stack." << endl;
            return top;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int value = stack_array[top];
            stack_array[top] = 0;
            cout << value << " is popped from position " << top << endl;
            top--;
            return value;
        }
    }

    int peek(int pos)
    {
        return stack_array[pos];
    }

    int count()
    {
        return top + 1;
    }

    int change(int pos, int val)
    {
        int prevVal = stack_array[pos];
        stack_array[pos] = val;
        cout << "Value changed at location" << pos << endl;
        return prevVal;
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
