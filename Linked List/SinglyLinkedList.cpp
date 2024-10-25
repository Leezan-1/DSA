#include <iostream>
#include <climits>

using namespace std;

class SinglyLinkedlist
{
private:
    typedef struct SinglyNode
    {
        int data;
        struct SinglyNode *next_addr;
    } Node;

    Node *head, *tail;

public:
    SinglyLinkedlist()
    {
        this->head = this->createNode(10);
        this->tail = this->head;
        cout << "Linked List Created\n";
    }

    Node *createNode(int data)
    {
        // cout << "\nEnter the data for node:\t";
        // cin >> data;
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next_addr = nullptr;
        return new_node;
    }

    void displayNodes() // This function prints the linked list;
    {
        if (this->checkEmpty())
            return;

        Node *temp_node = this->head;

        printf("Head: |%p|\n", temp_node);

        while (temp_node->next_addr != nullptr)
        {
            printf("| %d | %p |<--->", temp_node->data, temp_node->next_addr);
            temp_node = temp_node->next_addr;
        }
        printf("| %d | %p |\n", temp_node->data, temp_node->next_addr);
        /*
        The time complecity to print is O(n) as each node is travesed.
        */
    }

    int checkEmpty()
    {
        if (this->head == nullptr)
        {
            cout << "\nlinked list is empty!\n";
            return 1;
        }
        else
            return 0;
    }

    void insertNodeAtFront()
    {
        Node *temp = createNode(0);
        temp->next_addr = this->head;
        this->head = temp;
    }

    void insertNodeAtEnd() // This function inserts node with a value at the end of linked list
    {
        if (checkEmpty())
            return;

        Node *temp = createNode(20);
        this->tail->next_addr = temp;
        this->tail = temp;

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

    void deleteNodeAtFront()
    {
        if (this->checkEmpty())
            return;

        Node *temp = this->head;
        this->head = this->head->next_addr;
        delete (temp);
    }

    void deleteNodeAtEnd()
    {
        if (this->checkEmpty())
            return;
        Node *temp = this->head;
        if (temp->next_addr == nullptr)
        {
            delete (this->head);
            this->head = nullptr;
            this->tail = nullptr;
        }
        while (temp->next_addr != this->tail)
        {
            temp = temp->next_addr;
        }
        temp->next_addr = nullptr;
        delete (this->tail);
        this->tail = temp;
    }
};

int main()
{
    SinglyLinkedlist linkedlist1 = SinglyLinkedlist();

    linkedlist1.insertNodeAtEnd();
    linkedlist1.insertNodeAtFront();
    linkedlist1.displayNodes();

    cout << endl;
    linkedlist1.deleteNodeAtFront();
    linkedlist1.deleteNodeAtEnd();
    linkedlist1.displayNodes();
}
