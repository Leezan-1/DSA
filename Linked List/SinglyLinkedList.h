#include <iostream>
#include <climits>

using namespace std;

class Singly
{
private:
    struct Node
    {
        int data;
        struct Node *next_addr;

        Node(int value) : next_addr(nullptr), data(value) {};
    };

    Node *head, *tail;

    bool checkEmpty()
    {
        if (head == nullptr && tail == nullptr)
        {
            cout << "\nlinked list is empty!\n";
            return true;
        }
        else
            return 0;
    }

    Node *createNode()
    {
        int data;
        cout << "\nEnter the data for node: ";
        cin >> data;
        Node *new_node = new Node(data);
        return new_node;
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
    Singly()
    {
        head = createNode();
        tail = head;
        cout << "Linked List Created\n";
    }

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

    void displayNodes() // This function prints the linked list;
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

    bool insertNodeAtFront()
    {
        if (checkEmpty())
        {
            head = createNode();
            tail = head;
        }
        else
        {
            Node *temp = createNode();
            temp->next_addr = head;
            head = temp;
        }
        return true;
    }

    bool deleteNodeAtFront()
    {
        if (checkEmpty())
            return false;

        Node *temp = this->head;
        this->head = this->head->next_addr;
        
        delete (temp);
        temp = nullptr;
        return true;
    }

    bool insertNodeAtEnd() // This function inserts node with a value at the end of linked list
    {
        if (checkEmpty())
            return false;

        Node *temp = createNode();
        tail->next_addr = temp;
        tail = temp;

        return true;
        /*
            while (head->link != NULL)
            head = head->link;

            head->link = temp;
        This can also be done but it increases time complexity.,
        this is not efficient
        head is passed in as argument inseat of current_end;
        and the return type of function can be void
        */
    }

    bool deleteNodeAtEnd()
    {
        if (checkEmpty())
            return false;

        Node *temp = head;

        if (temp->next_addr == nullptr)
        {
            delete (temp);
            head = nullptr;
            tail = nullptr;
            return true;
        }

        while (temp->next_addr != tail)
            temp = temp->next_addr;

        temp->next_addr = nullptr;
        delete (tail);
        tail = temp;
        return true;
    }

    bool insertNodeAtPosition(int position)
    {
        if (checkEmpty())
            return false;
        else if (checkInvalidPosition(position))
            return false;

        if (position == 1)
            insertNodeAtFront();
        else
        {
            Node *new_node = createNode(), *temp;

            for (size_t i = 1; i < position - 1; i++)
                temp = temp->next_addr;

            new_node->next_addr = temp->next_addr;
            temp->next_addr = new_node;
        }
        return true;
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
            deleteNodeAtFront();
        else
        {
            Node *node_bef_pos, *temp = head;

            for (size_t i = 1; i < position; ++i)
            {
                node_bef_pos = temp;
                temp = temp->next_addr;
            }

            node_bef_pos->next_addr = temp->next_addr;

            delete temp;
            temp = nullptr;
        }
        return true;
    }
};
