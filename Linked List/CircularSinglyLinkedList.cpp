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
        CircularSinglyNode *next_addr;
        //  This creates a node for linkedlist
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
    }

public:
    CircularSinglyLinkedList(/* args */)
    {
        for (size_t i = 0; i < (sizeof(value) / sizeof(value[0])); i++)
            value[i] = i * 10;

        (this->tail) = createNode(value[1]);
        (this->tail)->next_addr = (this->tail);
        cout << "Circular Singly Linked List Created!" << endl;
    }

    bool checkEmpty()
    {
        if ((this->tail) == nullptr)
        {
            cout<<"Linked List empty!"<<endl;
            return true;
        }
        else
            return false;
    }

    void displayNodes() // This function prints the linked list;
    {
        if (checkEmpty())
            return;

        Node *temp_node = (this->tail)->next_addr;

        do
        {
            printf("| %d | %p |\t", temp_node->data, temp_node->next_addr);
            temp_node = temp_node->next_addr;
        } while (temp_node != (this->tail)->next_addr);
        cout<<endl<<"Tail: |"<<(this->tail)<<"|"<<endl;;
        

        /*
        the loop is changed compared to singly list ast there is no null at
        last node;
        The time complecity to print is O(n) as each node is travesed.
        */
    }

    
    void insertNodeAtFront()
    {
        if (checkEmpty())
            return;
        
        Node *new_node = createNode(value[0]);
        // new_node->next_addr = tail->next_addr;
        new_node->next_addr = (this->tail)->next_addr;
        (this->tail)->next_addr = new_node;
        
    }

    void deleteNodeAtFront()
    {
        if (checkEmpty())
            return;
        
        Node *temp = (this->tail)->next_addr;
        (this->tail)->next_addr = temp->next_addr;
        
        delete temp;
        temp = nullptr;
    }
};

int main()
{
    CircularSinglyLinkedList linkedlist = CircularSinglyLinkedList();

    linkedlist.insertNodeAtFront();
    linkedlist.displayNodes();
    
    cout<<endl;
    linkedlist.deleteNodeAtFront();
    linkedlist.displayNodes();
    return 0;
}
