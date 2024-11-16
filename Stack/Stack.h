#include "../Linked List/SinglyLinkedList.h"
#define STACK_SIZE 10

using namespace std;

namespace ArrayStack
{

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
} // namespace ArrayStack

namespace LinkedListStack
{
    class Stack
    {
    private:
        int top;
        Singly linkedlist;

    public:
        Stack() : top{-1} {}

        bool isEmpty()
        {
            return (top == -1) ? true : false;
        }

        int push(int val)
        {
            linkedlist.insertNodeAtFront(val);
            top++;
            return top;
        }

        int pop()
        {
            if (linkedlist.checkEmpty())
                return -1;
            int popped_data = linkedlist.accessAtPosition(0 + 1);
            top--;
            linkedlist.deleteNodeAtFront();
            return popped_data;
        }

        int count()
        {
            return top + 1;
        }

        int peek(int pos)
        {
            return linkedlist.accessAtPosition(pos + 1);
        }

        void display()
        {
            int no_of_nodes = linkedlist.countNodes();
            cout << "\nAll values in the stack are" << endl;
            for (size_t i = 0; i < no_of_nodes; i++)
                cout << "|" << "\t" << peek(i) << "\t" << "|" << endl;
            cout << endl;
        }
    };

}
