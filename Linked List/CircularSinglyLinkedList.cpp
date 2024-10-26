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

    int value[6];

    Node *tail;

    Node *createNode(int data)
    {
        // cout << "\nEnter the data for node:\t";
        // cin >> data;
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next_addr = nullptr;
        // cout<<"Node created"<<endl;
        return new_node;

        /*
            The fuction creates a new node with dynamic memory allocation.
            It returns the address of the new_node.
        */
    }

public:
    CircularSinglyLinkedList(/* args */)
    {
        for (size_t i = 0; i < (sizeof(value) / sizeof(value[0])); i++)
            value[i] = i * 10;

        tail = createNode(value[1]);
        tail->next_addr = tail;
        cout << "Circular Singly Linked List Created!" << endl;

        /*
            The intilizing of linked list consist of creating node
            and adding it to tail pointer.
            Circular Linked list, end node points to the first node.
            So tail's next_addr also points to itself.
        */
    }

    bool checkEmpty()
    {
        if (tail == nullptr)
        {
            cout << "Linked List empty!" << endl;
            return true;
        }
        else
            return false;
        /*
            Fucntion checks if the tail pointer is null to validate empty
        */
    }

    void displayNodes() // This function prints the linked list;
    {
        if (checkEmpty())
            return;

        Node *temp_node = tail->next_addr;
        do
        {
            printf("| %d | %p |\t", temp_node->data, temp_node->next_addr);
            temp_node = temp_node->next_addr;
        } while (temp_node != tail->next_addr);

        cout << endl
             << "Tail: |" << tail << "|" << endl;
        ;

        /*
            the loop is changed compared to singly list as there is no null at
            last node;
            The loop runs as temp_node being the first node (tail's next_addr).
            do...while is used here because we check the tail's next_addr(i.e front node) to end the loop.
            and we start loop as the front node which will take us out of loop before even starting (if we use whiile loop).


            The time complecity to print is O(n) as each node is travesed.
        */
    }

    void insertNodeAtFront()
    {
        if (checkEmpty())
            return;

        Node *new_node = createNode(value[0]);
        // new_node->next_addr = tail->next_addr;
        new_node->next_addr = tail->next_addr;
        tail->next_addr = new_node;

        /*
            The function adds node at the beginning of linked list.
            The new _node's next_addr stores the address of the first node i.e tail's next_addr.
            the end node (tail)'s next_addr stores address of new_node, now first node.
        */
    }

    void deleteNodeAtFront()
    {
        if (checkEmpty())
            return;

        Node *temp = tail->next_addr;

        if (temp == tail)
            tail = nullptr;
        else
            tail->next_addr = temp->next_addr;

        delete temp;
        temp = nullptr;

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

    void insertNodeAtEnd()
    {
        Node *new_node = createNode(value[4]);

        new_node->next_addr = tail->next_addr;
        tail->next_addr = new_node;
        tail = new_node;

        /*
            This function adds node at end.
            the new_node's next_addr is kept as tail node's next_addr
            current end node's next_addr is changed to new_node.
            the tail is now the new node.
        */
    }

    void reverseList()
    {
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

int main()
{
    CircularSinglyLinkedList linkedlist = CircularSinglyLinkedList();

    linkedlist.insertNodeAtFront();
    linkedlist.insertNodeAtFront();
    linkedlist.insertNodeAtEnd();
    linkedlist.displayNodes();

    cout << endl;
    linkedlist.deleteNodeAtFront(); 
    linkedlist.displayNodes();

    cout << endl;
    linkedlist.reverseList();
    linkedlist.displayNodes();
    return 0;
}
