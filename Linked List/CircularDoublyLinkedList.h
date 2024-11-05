

/* Circular linked list is the type of linked list in which last node points
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
        cout << "\nEnter the data for node: ";
        cin >> data;
        Node *new_node = new Node(data);

        return new_node;

        /*
            The fuction creates a new node with dynamic memory allocation.
            It returns the address of the new_node.
        */
    }

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
    CircularDoubly()
    {
        
        tail = createNode();
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

    void displayNodes()
    {
        if (checkEmpty())
            return;

        cout << endl
             << "Number of Node(s): " << countNodes() << endl;

        Node *temp_node = tail->next_addr;
        do
        {
            printf("| %d |\t", temp_node->data);
            temp_node = temp_node->next_addr;
        } while (temp_node != tail->next_addr);
        cout << endl;

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

    bool insertNodeAtFront()
    {
        if (checkEmpty())
            return false;

        Node *temp = createNode();
        temp->prev_addr = tail;
        temp->next_addr = tail->next_addr;

        tail->next_addr->prev_addr = temp;
        tail->next_addr = temp;

        if (tail == tail->next_addr)
            tail->prev_addr = temp;
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

    bool deleteNodeAtEnd()
    {
        if (checkEmpty())
            return false;

        Node *temp = tail;

        if (tail != tail->next_addr)
        {
            tail->next_addr->prev_addr = tail->prev_addr;
            tail->prev_addr->next_addr = tail->next_addr;
        }
        else
            tail = nullptr;

        delete temp;
        return true;
    }

    bool insertNodeAtEnd()
    {
        if (checkEmpty())
            return false;

        Node *new_node = createNode();
        new_node->next_addr = tail->next_addr;
        new_node->prev_addr = tail;

        tail->next_addr->prev_addr = new_node;
        tail->next_addr = new_node;

        tail = new_node;

        return true;
    }

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

    bool deleteNodeAtPosition(int position)
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
            return deleteNodeAtFront();
        else
        {
            Node *prev_temp = tail->next_addr, *temp;

            for (size_t i = 1; i < position - 1; i++)
                prev_temp = prev_temp->next_addr;

            temp = prev_temp->next_addr;

            prev_temp->next_addr = temp->next_addr;
            temp->next_addr->prev_addr = prev_temp;

            if (tail == temp)
                tail = prev_temp;

            delete temp;
            return true;
        }
    }

    bool deleteEntireList()
    {
        if (checkEmpty())
            return false;

        while (tail != nullptr)
            deleteNodeAtFront();

        return true;
    }


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
};
