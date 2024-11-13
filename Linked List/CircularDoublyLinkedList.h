/*
    Circular linked list is the type of linked list in which last node points
    to the first node.
    Last node has address of first node;
*/

class CircularDoubly
{
private:
    typedef struct Node
    {
        struct Node *prev_addr;
        int data;
        struct Node *next_addr;
        /*
            This creates a node for singly circular linked list.
            The singly circular linked list contains data and address of next node.
            And the end node points to the starting node.
        */

        Node(int value) : prev_addr(nullptr), next_addr(nullptr), data(value) {};
    } Node;

    Node *tail;

    Node *createNode()
    {
        int data;
        cout << "Enter the data for node: ";
        cin >> data;
        Node *new_node = new Node(data);

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
    CircularDoubly() : tail(nullptr) {}

    bool checkEmpty()
    {
        if (tail == nullptr)
        {
            cout << "Linked list empty!" << endl;
            return true;
        }
        else
            return false;
    }

    int countNodes()
    {
        int count = 0;
        Node *temp = tail->next_addr;
        do
        {
            count++;
            temp = temp->next_addr;
        } while (temp != tail->next_addr);
        return count;

        /*
            the loop is changed compared to singly list as there is no null at
            last node;
            The loop runs as temp_node being the first node (tail's next_addr).
            do...while is used here because we check the tail's next_addr(i.e front node) to end the loop.
            and we start loop as the front node which will take us out of loop before even starting (if we use whiile loop).

            The time complecity to print is O(n) as each node is travesed.
        */
    }

    // Displays all nodes in the linked list.
    void displayNodes()
    {
        if (checkEmpty())
            return;

        Node *temp = tail->next_addr;

        cout << "\n-----------------------" << endl
             << "Number of Node(s): " << countNodes() << endl;

        do
        {
            cout << "| " << temp->data << " | ";
            temp = temp->next_addr;
        } while (temp != tail->next_addr);
        cout << "\n-----------------------"
             << endl;

        /*
             This function prints the linked list;
            the loop is changed compared to singly list as there is no null at
            last node;
            The loop runs as temp_node being the first node (tail's next_addr).
            do...while is used here because we check the tail's next_addr(i.e front node) to end the loop.
            and we start loop as the front node which will take us out of loop before even starting (if we use whiile loop).

            The time complecity to print is O(n) as each node is travesed.
        */
    }

    // inserts a new node at the front of the node
    bool insertNodeAtFront()
    {
        Node *new_node = createNode();

        if (tail == nullptr)
        {
            tail = new_node;
            tail->next_addr = tail;
            tail->prev_addr = tail;
        }
        else
        {
            new_node->prev_addr = tail;
            new_node->next_addr = tail->next_addr;

            tail->next_addr->prev_addr = new_node;
            tail->next_addr = new_node;
            if (tail == tail->next_addr)
                tail->prev_addr = new_node;
        }
        return true;

        /*
            first a new node is created and its addr is pointed by temp

            the new node's prev_addr will point to the tail and next_addr
            will point to existing first node.

            then we update the first node's prev_addr to point to temp as it will be 2nd node.
            then we update tail's next_addr i.e firstnode to be temp;

            if there is only one node then
                tail's prev node should be temp;


            ten first
        */
    }

    // deletes the node at the front of the node
    bool deleteNodeAtFront()
    {
        if (checkEmpty())
            return false;

        Node *temp = tail->next_addr;

        if (tail != tail->next_addr)
        {
            tail->next_addr = temp->next_addr;
            temp->next_addr->prev_addr = tail;
        }
        else
            tail = nullptr;

        delete temp;
        return true;

        /*
            first node's addr is stored in temp.

            tail's next_addr stores the addr of 2nd node.(which will be 1st node)

            2nd node's prev_addr will store tail's addr. now temp can be freed
            so temp is deleted.

            if there is only one node then tail point to null;


        */
    }

    // deletes the node at the end of the list
    bool deleteNodeAtEnd()
    {
        if (checkEmpty())
            return false;

        Node *temp = tail, *front_node = tail->next_addr, *prev_to_temp = tail->prev_addr;

        if (tail != tail->next_addr)
        {
            front_node->prev_addr = tail->prev_addr;
            prev_to_temp->next_addr = tail->next_addr;
            tail = prev_to_temp;
        }
        else
            tail = nullptr;

        delete temp;
        return true;
    }

    // inserts a new node at the end of the list
    bool insertNodeAtEnd()
    {
        Node *new_node = createNode();

        if (tail == nullptr)
        {
            tail = new_node;
            tail->next_addr = new_node;
            tail->prev_addr = new_node;
        }
        else
        {
            new_node->next_addr = tail->next_addr;
            new_node->prev_addr = tail;

            tail->next_addr->prev_addr = new_node;
            tail->next_addr = new_node;

            tail = new_node;
        }
        return true;
    }

    // inserts a node at specified position
    bool insertNodeAtPosition(int position)
    {
        if (checkEmpty())
            return false;
        else if (checkInvalidPosition(position))
            return false;

        if (position == 1)
            return insertNodeAtFront();
        else
        {
            Node *temp = tail->next_addr, *new_node = createNode();
            for (size_t i = 1; i < position - 1; i++)
                temp = temp->next_addr;

            new_node->next_addr = temp->next_addr;
            new_node->prev_addr = temp;
            temp->next_addr->prev_addr = new_node;
            temp->next_addr = new_node;

            tail = (temp == tail) ? new_node : tail;
            return true;
        }
    }

    // deletes a node at specified position
    bool deleteNodeAtPosition(int position)
    {
        if (checkEmpty())
            return false;
        else if (checkInvalidPosition(position))
            return false;

        if (position == 1)
            return deleteNodeAtFront();
        else
        {
            Node *prev_to_temp = tail->next_addr, *temp = nullptr;

            for (size_t i = 1; i < position - 1; i++)
                prev_to_temp = prev_to_temp->next_addr;

            temp = prev_to_temp->next_addr;

            prev_to_temp->next_addr = temp->next_addr;
            temp->next_addr->prev_addr = prev_to_temp;

            if (tail == temp)
                tail = prev_to_temp;

            delete temp;
            return true;
        }
    }

    //  reverses entire list
    bool deleteEntireList()
    {
        if (checkEmpty())
            return false;

        while (tail != nullptr)
            deleteNodeAtFront();

        return true;
    }

    //  reverses entire list
    bool reverseList()
    {
        // Reverses the circular doubly linked list.
        if (checkEmpty())
            return false;

        Node *current = tail->next_addr; // Starts from the head
        Node *temp = nullptr;            // Temporary pointer for swapping

        do
        {
            temp = current->prev_addr; // Swaps prev and next of current
            current->prev_addr = current->next_addr;
            current->next_addr = temp;
            current = current->prev_addr; // Moves to the next node in original order
        } while (current != tail->next_addr); // Loops until back at head

        tail = tail->next_addr; // Updates tail to the previous head
        return true;
    }

    // creates entire list
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
                insertNodeAtEnd();
            }
            cout << "Linked List Created\n";
        }
        else
            cout << "Invalid number! No list created!\n";
        return true;
    }

    ~CircularDoubly()
    {
        deleteEntireList();
    }
};
