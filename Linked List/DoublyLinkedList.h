#include <iostream>
using namespace std;

class Doubly
{
private:
    // Node structure
    struct Node
    {
        Node *prev_addr;
        int data;
        Node *next_addr;

        Node(int value) : prev_addr(nullptr), next_addr(nullptr), data(value) {};
    };

    Node *head;
    Node *tail;

    Node *createNode()
    {
        int user_data;

        cout << "Enter the data for node: ";
        cin >> user_data;

        Node *new_node = new Node(user_data);

        return new_node;

        /*
            The fuction creates a new node with dynamic memory allocation.
            It returns the address of the new_node.
        */
    }

    bool checkInvalidPosition(int position)
    {

        if (position > countNodes() + 1 || position <= 0)
        {
            cout << "Invalid Position!" << endl;
            return true;
        }
        else
            return false;

        /*
            if position is greater than number of nodes or 0 or less than 0, position is invalid.
        */
    }

public:
    Doubly() : head(nullptr), tail(nullptr) {};

    bool checkEmpty()
    {
        if (tail == nullptr && head == nullptr)
        {
            cout << endl
                 << "Linked List empty!" << endl;
            return true;
        }
        else
            return false;
        /*
            Fucntion checks if the tail pointer is null to validate empty
        */
    }

    // Counts the nodes in list
    int countNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next_addr;
            count++;
        }
        return count;
    }

    // Displays all nodes in the linked list.
    void displayNodes()
    {
        if (checkEmpty())
            return;

        Node *temp = head;

        cout << "\n-----------------------" << endl
             << "Number of Node(s): " << countNodes() << endl;

        while (temp != nullptr)
        {
            cout << "| " << temp->data << " | ";
            temp = temp->next_addr;
        }
        cout << "\n-----------------------"
             << endl;
    }

    // Insert node at the front
    bool insertNodeAtFront()
    {
        Node *new_first_node = createNode();
        new_first_node->next_addr = head;

        if (head == nullptr)
            tail = new_first_node;
        else
            head->prev_addr = new_first_node;

        head = new_first_node;
        return true;
    }

    // Delete node at the front
    bool deleteNodeAtFront()
    {
        if (checkEmpty())
            return false;

        Node *temp = head;

        head = head->next_addr;
        if (head != nullptr)
            head->prev_addr = nullptr;
        else
            tail = nullptr;

        delete temp;
        temp = nullptr;
        return true;
    }

    // Insert node at the end
    bool insertNodeAtEnd()
    {
        Node *new_last_node = createNode();
        new_last_node->prev_addr = tail;

        if (tail == nullptr)
            head = new_last_node;
        else
            tail->next_addr = new_last_node;

        tail = new_last_node;
        return true;
    }

    // Delete node at the end
    bool deleteNodeAtEnd()
    {
        if (checkEmpty())
            return false;

        Node *temp = tail;

        tail = tail->prev_addr;
        if (tail != nullptr)
            tail->next_addr = nullptr;
        else
            head = nullptr;

        delete temp;
        temp = nullptr;
        return true;
    }

    // Insert node at a specific position
    bool insertNodeAtPosition(int position)
    {
        if (checkEmpty())
            return false;

        else if (checkInvalidPosition(position))
            return false;

        if (position == 1)
        {
            insertNodeAtFront();
        }
        else
        {
            Node *new_node = createNode(), *temp = head;

            for (int i = 1; i < position - 1; ++i)
                temp = temp->next_addr;

            new_node->next_addr = temp->next_addr;
            new_node->prev_addr = temp;

            if (temp->next_addr != nullptr)
                temp->next_addr->prev_addr = new_node;
            else
                tail = new_node; // Update tail if inserted at the end

            temp->next_addr = new_node;
        }
        return true;
    }

    // Delete node at a specific position
    bool deleteNodeAtPosition(int position)
    {
        if (checkEmpty())
            return false;

        else if (checkInvalidPosition(position))
            return false;

        if (position == 1)
            deleteNodeAtFront();

        else
        {
            Node *prev_temp = head, *temp = nullptr;

            for (int i = 1; i < position - 1; ++i)
                prev_temp = prev_temp->next_addr;

            temp = prev_temp->next_addr;
            prev_temp->next_addr = temp->next_addr;

            if (temp->next_addr != nullptr)
                temp->next_addr->prev_addr = prev_temp;
            else
                tail = prev_temp; // Update tail if the last node was deleted

            delete temp;
            temp = nullptr;
        }
        return true;
    }

    // Reverse the list
    bool reverseList()
    {
        if (checkEmpty())
            return false;

        Node *temp = nullptr, *current = head;
        tail = head;

        while (current != nullptr)
        {
            temp = current->prev_addr;
            current->prev_addr = current->next_addr;
            current->next_addr = temp;
            current = current->prev_addr;
        }

        if (temp != nullptr) // Update head to the last processed node
            head = temp->prev_addr;

        return true;
    }

    //  Deletes Entire list
    bool deleteEntireList()
    {
        if (checkEmpty())
            return false;
        else
        {
            while (head != nullptr)
                deleteNodeAtFront();
            return true;
        }
    }

    // Creates entire list of user input number of nodes.
    bool createEntireList()
    {
        if (!checkEmpty())
        {
            cout << "\nEntire list can only be created when it is empty!" << endl;
            return false;
        }

        int no_of_nodes;
        cout << "\nEntire new linkedlist will be created!\nEnter the number of nodes in linked list: ";
        cin >> no_of_nodes;

        if (no_of_nodes > 0)
        {
            for (size_t i = 1; i <= no_of_nodes; i++)
            {
                cout << "\nFor Node " << i << ": \n";
                insertNodeAtEnd();;
            }
            cout << "Linked List Created\n";
        }
        else
            cout << "Invalid number! No list created!\n";
        return true;
    }
};
