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

        cout << "\nEnter the data for node: ";
        cin >> user_data;

        Node *new_node = new Node(user_data);

        return new_node;

        /*
            The fuction creates a new node with dynamic memory allocation.
            It returns the address of the new_node.
        */
    }

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
            if position is greater than or 0 or less than 0, position is invalid.
        */
    }

public:
    Doubly() : head(createNode()), tail(head) {};

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

    // Display the list
    void displayNodes()
    {
        if (checkEmpty())
            return;

        Node *temp = head;
        cout << "Number of Nodes(s): " << countNodes() << endl;

        while (temp->next_addr != NULL)
        {
            printf("| %d |\t", temp->data);
            temp = temp->next_addr;
        }
        cout << endl;

        /*
             This function prints the linked list;

            The time complecity to print is O(n) as each node is travesed.
        */
    }

    // Insert node at the front
    bool insertNodeAtFront()
    {
        if (checkEmpty())
        {
            head = createNode();
            tail = head;
        }
        else
        {
            Node *new_first_node = createNode();
            new_first_node->next_addr = head;

            head->prev_addr = new_first_node;
            head = new_first_node;
        }
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
    }

    // Insert node at the end
    bool insertNodeAtEnd()
    {
        if (checkEmpty())
        {
            head = createNode();
            tail = head;
        }
        else
        {
            Node *new_last_node = createNode();
            new_last_node->prev_addr = tail;

            tail->next_addr = new_last_node;
            tail = new_last_node;
        }
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
    }

    // Insert node at a specific position
    bool insertNodeAtPos(int position)
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
    }

    // Delete node at a specific position
    bool deleteNodeAtPos(int position)
    {
        if (checkEmpty())
            return false;

        else if (position == countNodes() + 1)
        {
            checkInvalidPosition(position + 1);
            return false;
        }

        else if (checkInvalidPosition(position))
            return false;

        if (position == 1)
            deleteNodeAtFront();

        else
        {
            Node *prev_temp = head;

            for (int i = 1; i < position - 1; ++i)
                prev_temp = prev_temp->next_addr;

            Node *temp = prev_temp->next_addr;
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
};
