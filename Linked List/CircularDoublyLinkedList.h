

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
    int array[6];

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
        if (tail == nullptr)
        {
            cout << "Linked list empty!";
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

public:
    CircularDoubly()
    {
        for (size_t i = 0; i < 6; i++)
        {
            array[i] = i * 10;
        }
        tail = createNode(array[1]);
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

        Node *temp = createNode(array[0]);
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
};
