#include <iostream>

using namespace std;

/* Circular linked list is the type of linked list in which last node points
    to the first node.
    Last node has address of first node;
*/

class CircularDoubly
{
private:
    typedef struct CircularDoublyNode
    {
        struct CircularDoublyNode *prev_addr;
        int data;
        struct CircularDoublyNode *next_addr;
        /*
            This creates a node for singly circular linked list.
            The singly circular linked list contains data and address of next node.
            And the end node points to the starting node.
        */
    } Node;

    Node *tail;
    int value[0];

    Node *createNode(int value)
    {
        int data;
        // cout << "\nEnter the data for node: ";
        // cin >> data;
        data = value;
        Node *new_node = new Node;

        new_node->data = data;
        new_node->next_addr = nullptr;
        new_node->prev_addr = nullptr;

        return new_node;

        /*
            The fuction creates a new node with dynamic memory allocation.
            It returns the address of the new_node.
        */
    }

    bool checkEmpty()
    {
        if (tail = nullptr)
            return true;
        else
            return false;
    }

public:
    CircularDoubly()
    {
        tail = createNode(value[1]);
        tail->next_addr = tail;
        tail->prev_addr = tail;
        cout << "Circular Doubly Linked List Created!" << endl;

        /*
            The intilizing of linked list consist of creating node
            and adding it to tail pointer.
            Circular Linked list, end node points to the first node.
            So tail's next_addr also points to itself.
        */
    }
    
    bool insertNodeAtFront()
    {
        if (checkEmpty())
            return false;
        return true;
    }

};
