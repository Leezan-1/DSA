#include <stdio.h>
#include <stdlib.h>

// linked list using structure
typedef struct Node // This create a variable acting node of linked list
{
    int data;
    struct Node *link;
} Node;

const int NODE_SIZE = sizeof(Node);

int countNodes(Node *front_node) // This function counts the number of nodes present in linked list
{
    int count = 0;
    if (front_node == NULL)
        return count;

    while (front_node != NULL)
    {
        count++;
        front_node = front_node->link;
    }
    return count;
}

void displayNodes(Node *pointer) // This function prints the linked list;
{
    if (pointer == NULL)
    {
        printf("linked list is empty!\n");
        return;
    }
    printf("The Linked list is: |%p| ", pointer);
    while (pointer != NULL)
    {
        printf("----> |%d|%p| ", pointer->data, pointer->link);
        pointer = pointer->link;
    }

    printf("\n");

    /*
    The time complecity to print is O(n) as each node is travesed.
    */
}

Node *insertNodeAtEnd(Node *current_end, int value) // This function inserts node with a value at the end of linked list
{
    Node *temp = malloc(NODE_SIZE);
    temp->data = value;
    temp->link = NULL;

    current_end->link = temp;
    return temp;

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

Node *insertNodeAtFront(Node *front_node, int value)
{
    Node *temp = malloc(NODE_SIZE);
    temp->data = value;
    temp->link = front_node;
    return temp;
}

void insertNodeAtPosition(Node **head, int pos, int value)
{
    Node *temp = malloc(NODE_SIZE);
    temp->data = value;

    if (pos == 0)
    {
        temp->link = *head;
        *head = temp;
        return;
    }

    Node *node_bef_pos = *head;
    for (size_t i = 0; i < pos - 1; i++)
    {
        node_bef_pos = node_bef_pos->link;
    }

    temp->link = node_bef_pos->link;
    node_bef_pos->link = temp;

    return;
}

Node *deleteNodeAtFront(Node *front_node)
{
    Node *temp = front_node;
    front_node = front_node->link;

    free(temp);
    temp = NULL;
    return front_node;
}

Node *deleteNodeAtEnd(Node *front_node)
{
    if (front_node == NULL)
    {
        printf("linked list is empty\n");
        return NULL;
    }
    else if (front_node->link == NULL)
    {
        free(front_node);
        return NULL;
    }
    else
    {
        // here i commented the other method to do same stuff but with 2 pointer var involved

        Node *last_node = front_node ; // *second_last_node = front_node; 

        while (last_node->link->link != NULL)
        {
            // second_last_node = last_node; last_node = last_node->link;
            last_node = last_node->link;
        }

        //second_last_node->link = NULL; free(last_node); last_node = NULL;
        free(last_node->link);
        last_node->link = NULL;

        return front_node;
    }
}

int main()
{
    Node *head = malloc(NODE_SIZE);
    Node *current = malloc(NODE_SIZE);
    int data, position;

    // the first node of the linked list
    data = 5;
    head->data = data;
    head->link = NULL;
    current = head;

    // This is the third node of linked list
    data = 25;
    current = insertNodeAtEnd(current, data);

    // This is the fourth node of linked list
    data = 30;
    current = insertNodeAtEnd(current, data);

    // This adds new node at front, shift head pointer to new node;
    data = 100;
    head = insertNodeAtFront(head, data);

    // Adding node at 3rd position; since pos starts from 0.
    data = 50, position = 2;
    insertNodeAtPosition(&head, position, data);

    printf("The number of nodes in linked list is %d \n", countNodes(head));
    displayNodes(head);

    // Deleting the front node.
    head = deleteNodeAtFront(head);

    // deleting node at last
    head = deleteNodeAtEnd(head);
    displayNodes(head);

    return 0;
}