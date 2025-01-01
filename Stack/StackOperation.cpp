#include <iostream>
using namespace std;
#include "Stack.h"

int main()
{
    ArrayStack::Numeric::Stack stack1;
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