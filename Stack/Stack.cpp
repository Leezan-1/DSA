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

int main()
{
    Stack stack1;
    int option, value, position;

    do
    {
        cout << endl
             << "What operations do you want to choose?" << endl
             << "1. Push" << endl
             << "2. Pop" << endl
             << "3. isEmpty()" << endl
             << "4. isFull()" << endl
             << "5. peek()" << endl
             << "6. count()" << endl
             << "7. change()" << endl
             << "8. display()" << endl
             << "9. Clear Screen" << endl
             << "Enter 0 to exit. Select Option Number: ";
        cin >> option;
        cout << endl;

        switch (option) // switch case for options that are selected
        {
        case 1: //  Push
            cout << "Enter the value to push to stack: ";
            cin >> value;
            stack1.push(value);
            break;

        case 2: //  Pop
            stack1.pop();
            break;

        case 3: //  Checking if empty!
            stack1.isEmpty() ? cout << "The stack is empty!" << endl : cout << "The stack is not empty";
            break;

        case 4: //  Checking if full!
            stack1.isFull() ? cout << "The stack is full!" << endl : cout << "The stack is not full";
            break;

        case 5: // Peek
            cout << "Enter the positon to peek at ";
            cin >> position;
            cout << "The element at postion " << position << " is " << stack1.peek(position) << endl;
            break;

        case 6: // Count
            cout << "There are " << stack1.count() << " number of elements in stacks" << endl;
            break;

        case 7: //  Change
            cout << "Enter the Position and Value of stack that needs to be changed, respectively" << endl;
            cin >> position >> value;
            stack1.change(position, value);
            break;

        case 8: // Display Stack
            stack1.display();
            break;

        case 9: // clear screen
            system("clear");
            break;

        default:
            cout << "Enter proper option number" << endl;
        }

    } while (option != 0);
}