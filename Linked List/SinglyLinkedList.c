#include <stdio.h>
#include <stdlib.h>

// linked list using structure
typedef struct Node // This create a variable acting node of linked list
{
    int data;
    struct Node *link;
} Node;

const int NODE_SIZE = sizeof(Node);

int countNodes(Node *head) // This function counts the number of nodes present in linked list
{
    int count = 0;
    if (head == NULL)
        return count;

    while (head != NULL)
    {
        const int NODE_SIZE = sizeof(Node);
        count++;
        head = head->link;
    }
    return count;
}

void displayLinkedlist(Node *head) // This function prints the linked list;
{
    if (head == NULL)
    {
        printf("linked list is empty!\n");
        return;
    }
    printf("The Linked list is: |%p| ", head);
    while (head != NULL)
    {
        printf("----> |%d|%p| ", head->data, head->link);
        head = head->link;
    }
}

void insertNodeAtEnd(Node *head, int value) // This function inserts node with a value at the end of linked list
{
    Node *temp = malloc(NODE_SIZE);
    temp->data = value;
    temp->link = NULL;

    while (head->link != NULL)
        head = head->link;

    head->link = temp;
}

int main()
{
    Node *head = NULL;

    // the first node of the linked list
    head = malloc(NODE_SIZE);
    head->data = 5;
    head->link = NULL;

    // The second node of linked list
    {
        Node *current = malloc(NODE_SIZE);
        current->data = 10;
        current->link = NULL;
        head->link = current;
        /*
        The data located at malloc doesnot gets lost until it is freed
         even if the 'current' pointer variable gets delete at the end of the scope
        */
    }

    // This is the third node of linked list
    insertNodeAtEnd(head, 25);

    // This is the fourth node of linked list
    insertNodeAtEnd(head, 30);

    printf("The number of nodes in linked list is %d \n", countNodes(head));
    displayLinkedlist(head);

    return 0;
}