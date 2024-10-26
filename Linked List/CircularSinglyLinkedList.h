#include <iostream>

using namespace std;

/* Circular linked list is the type of linked list in which last node points
    to the first node.
    Last node has address of first node;
*/

class CircularSinglyLinkedList
{
private:
    typedef struct CircularSinglyNode
    {
        int data;
        struct CircularSinglyNode *next_addr;
        /*
            This creates a node for singly circular linked list.
            The singly circular linked list contains data and address of next node.
            And the end node points to the starting node.
        */
    } Node;

    Node *tail;

    Node *createNode()
    {
        int data;
        cout << "\nEnter the data for node: ";
        cin >> data;
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next_addr = nullptr;
        return new_node;

        /*
            The fuction creates a new node with dynamic memory allocation.
            It returns the address of the new_node.
        */
    }

public:
    CircularSinglyLinkedList()
    {
        tail = createNode();
        tail->next_addr = tail;
        cout << "Circular Singly Linked List Created!" << endl;

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

    bool checkEmpty()
    {
        if (tail == nullptr)
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

    void displayNodes()
    {
        if (checkEmpty())
            return;

        Node *temp_node = tail->next_addr;
        cout << endl
             << "Number of Node(s): " << countNodes() << endl;
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

        Node *new_node = createNode();
        // new_node->next_addr = tail->next_addr;
        new_node->next_addr = tail->next_addr;
        tail->next_addr = new_node;

        return true;
        /*
            The function adds node at the beginning of linked list.
            The new _node's next_addr stores the address of the first node i.e tail's next_addr.
            the end node (tail)'s next_addr stores address of new_node, now first node.
        */
    }

    bool deleteNodeAtFront()
    {
        if (checkEmpty())
            return false;

        Node *temp = tail->next_addr;

        if (temp == tail)
            tail = nullptr;
        else
            tail->next_addr = temp->next_addr;

        delete temp;
        temp = nullptr;
        return true;
        /*
            The function helps to delete the front node.
            The pointer temp stores the addr of the front node i.e tail's next_addr.
            if: there is only one node i.e temp and tail are equal
                then tail should point to null and we free temp;
            else:
                we store second node's addrss as the new frist node.
                and we free temp;

        */
    }

    bool insertNodeAtEnd()
    {

        if (checkEmpty())
            return false;

        Node *new_node = createNode();
        new_node->next_addr = tail->next_addr;
        tail->next_addr = new_node;
        tail = new_node;
        return true;
        /*
            This function adds node at end.
            the new_node's next_addr is kept as tail node's next_addr
            current end node's next_addr is changed to new_node.
            the tail is now the new node.
        */
    }

    bool deleteNodeAtEnd()
    {
        if (checkEmpty())
            return false;

        Node *temp = tail->next_addr;
        while (temp->next_addr != tail)
            temp = temp->next_addr;

        temp->next_addr = tail->next_addr;
        delete tail;
        tail = (tail != temp) ? temp : nullptr;
        return true;
        /*
            function deletes node at end.
            first the temp stores the add of head node
            the loop runs until the temp is second last node.
            the second last node's next_addr points to the first node.
            the last node is freed

            the last exp checks if thereis only one node, then tail should point to null.
        */
    }

    bool insertNodeAtPosition(int position)
    {

        if (checkEmpty())
            return false;
        else if (checkInvalidPosition(position))
            return false;

        Node *new_node = createNode();

        if (position == 1)
        {
            new_node->next_addr = tail->next_addr;
            tail->next_addr = new_node;
        }
        else
        {
            Node *temp = tail->next_addr;
            for (size_t i = 1; i < position - 1; i++)
                temp = temp->next_addr;

            new_node->next_addr = temp->next_addr;
            tail = (temp == tail) ? new_node : tail;

            temp->next_addr = new_node;
        }

        return true;
        /*
            if position is 1,
                then, new_node's next addr is front node and tail's next_addr points to new_node
            else
                we need a temp pointer pointing to previous node of the node at the postion
                the loop continues until we reach the previous node of the given position.
                there we update the new_node's next_addr to point to the node at that position.

                then we check if we are inserting a end node, ie temp is tail.
                if true, the new_node is tail.

                at last we update the next_addr of the node previous to the position, pointing to new_node.

                temp -> new_node -> next

        */
    }

    bool deleteNodeAtPosition(int position)
    {
        if (checkEmpty())
            return false;
        else if (checkInvalidPosition(position))
            return false;

        Node *temp;
        if (position == 1)
        {
            temp = tail->next_addr;
            if (tail == temp)
                tail = nullptr;
            else
                tail->next_addr = temp->next_addr;
        }

        else
        {
            Node *prev_temp = tail->next_addr;
            for (size_t i = 1; i < position - 1; i++)
                prev_temp = prev_temp->next_addr;

            temp = prev_temp->next_addr;
            prev_temp->next_addr = temp->next_addr;

            if (tail == temp)
                tail = prev_temp;
        }
        delete temp;
        temp = nullptr;
        return true;
        /*
            here temp is the node that will be deleted.

            if position is 1 then,
                if there is only one node in linked list,
                    yes then, delete temp and point tail to null
                    no then delete the first node and point tail to second node
            else
                then we need prev_temp;
                prev_temp is the node previos to temp;
                the next_addr of prev_temp is will be temp's next addr
                and if the node we want delete is tail node
                 then tail node will be the prev_temp after we delete the temp.

        */
    }

    bool checkInvalidPosition(int position)
    {
        int no_of_nodes = countNodes();

        if (position > no_of_nodes || position <= 0)
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

    bool reverseList()
    {
        if (checkEmpty())
            return false;
        Node *head = tail->next_addr, *prev_node, *next_node;
        tail = head;
        prev_node = head;
        next_node = head->next_addr;

        while (next_node != tail)
        {
            head = next_node;
            next_node = next_node->next_addr;
            head->next_addr = prev_node;
            prev_node = head;
        }
        tail->next_addr = head;
        return true;
        /*
            The function reverses the linked list.
            It uses 3 varaibles: head , prev_node and next_node.
            next_node stores the addr of the next node.
            head stores the addr of the node whose next_addr is being changed.
            prev_node stores the addr of the previous node
            The loop starts as tail pointing to the first node which will be last node.
            The loop stoops at next_node = tail (i.e when head points to previous last node).
            The time complexity of the function is 0(n)
        */
    }
};
