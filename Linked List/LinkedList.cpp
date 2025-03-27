#include <iostream>
using namespace std;

// Include all the headers for different linked list types
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularSinglyLinkedList.h"
#include "CircularDoublyLinkedList.h"

int chooseLinkedList()
{
    int choice;
    do
    {
        cout << "1. Singly Linked List" << endl
             << "2. Doubly Linked List" << endl
             << "3. Singly Circular Linked list" << endl
             << "4. Doubly Circular Linked list" << endl
             << "0 to exit!" << endl
             << "choose the number to select the type of linked list you want to use: ";
        cin >> choice;
        cout << endl;

        if (choice < 0 || choice > 4)
            cout << "Invalid choice, please try again." << endl;

    } while (choice < 0 || choice > 4);

    return choice = 3;
}

template <typename T>
void linkedListFunctionMenu(T &linkedlist)

{
    int choice;
    int position;

    do
    {
        cout << "\nMenu:\n"
             << "1. Display List\n"
             << "2. Insert Node at Front\n"
             << "3. Insert Node at End\n"
             << "4. Insert Node at Position\n"
             << "5. Delete Node at Front\n"
             << "6. Delete Node at End\n"
             << "7. Delete Node at Position\n"
             << "8. Delete Entire List\n"
             << "9. Reverse List\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {

        case 1:
        {
            linkedlist.displayNodes();
            break;
        }

        case 2:
        {
            if (linkedlist.insertNodeAtFront())
                cout << "Node inserted at front!" << endl;
            else
                cout << "Failed to insert node at front!" << endl;
            break;
        }

        case 3:
        {
            if (linkedlist.insertNodeAtEnd())
                cout << "Node inserted at end!" << endl;
            else
                cout << "Failed to insert node at end!" << endl;
            break;
        }

        case 4:
        {
            cout << "Enter position to insert: ";
            cin >> position;
            if (linkedlist.insertNodeAtPosition(position))
                cout << "Node inserted at position " << position << "!" << endl;
            else
                cout << "Failed to insert node at position " << position << "!" << endl;
            break;
        }

        case 5:
        {
            if (linkedlist.deleteNodeAtFront())
                cout << "Node deleted from front!" << endl;
            else
                cout << "Failed to delete node from front!" << endl;
            break;
        }

        case 6:
        {
            if (linkedlist.deleteNodeAtEnd())
                cout << "Node deleted from end!" << endl;
            else
                cout << "Failed to delete node from end!" << endl;
            break;
        }

        case 7:
        {
            cout << "Enter position to delete: ";
            cin >> position;
            if (linkedlist.deleteNodeAtPosition(position))
                cout << "Node deleted from position " << position << "!" << endl;
            else
                cout << "Failed to delete node from position " << position << "!" << endl;
            break;
        }

        case 8:
        {
            if (linkedlist.deleteEntireList())
                cout << "Entire linkedlist deleted!" << endl;
            else
                cout << "Entire linkedlist could not be deleted!" << endl;
            break;
        }

        case 9:
        {
            if (linkedlist.reverseList())
                cout << "List reversed!" << endl;

            else
                cout << "List couldnot be reversed!" << endl;
            break;
        }

        case 0:
        {
            cout << "Exiting menu." << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        }
    } while (choice != 0);
}

int main()
{
    int choice = chooseLinkedList();
    switch (choice)
    {
    case 1:
    {
        Singly list;
        linkedListFunctionMenu(list);
        break;
    }
    case 2:
    {
        Doubly list;
        linkedListFunctionMenu(list);
        break;
    }
    case 3:
    {
        CircularSingly list;
        linkedListFunctionMenu(list);
        break;
    }
    case 4:
    {
        CircularDoubly list;
        linkedListFunctionMenu(list);
        break;
    }
    default:
        cout << "Exiting program." << endl;
    }

    return 0;
}
