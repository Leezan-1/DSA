#include <stdio.h>
#include <stdlib.h>

/*
    Doubly Linked list is a type of linked list that has pointer to the address of both
    next node and previous node.
    it looks like :
    | prev_node_address | data | next_node_address|<--->| prev_node_address | data | next_node_address|
*/

typedef struct DoublyNode
{
    // this structure creates a doubly linked list node.
    struct DoublyNode *prev_addr;
    int data;
    struct DoublyNode *next_addr;
} DoublyNode;

DoublyNode *HEAD = NULL, *TAIL = NULL; //  POINTERS THAT POINTS THE HEAD AND TAIL OF LINKED LIST.

const int NODESIZE = sizeof(DoublyNode); //  MESURES THE SIZE OF A NODE TO MAKE DYNAMIC MEMORY ALLOCATION

int countNodes(DoublyNode *node)
{
    int count = 0;
    while (node != NULL)
    {
        node = node->next_addr;
        count++;
    }
    return count;
}

void displayDoubly(DoublyNode *node) //  DISPLAYS A DOUBLE LINKED LIST NODE FROM THE GIVEN NODE ADDRESS, usually address in head.
{
    if (node == NULL)
        printf("Linked List is empty");
    else
    {
        printf("Nodes: %d, Head: %p\n", countNodes(node), node);

        while (node->next_addr != NULL)
        {
            printf("| %p | %d | %p |<--->", node->prev_addr, node->data, node->next_addr);
            node = node->next_addr;
        }
        printf("| %p | %d | %p |\n", node->prev_addr, node->data, node->next_addr);
    }
}

DoublyNode *createNode(int value) //  FUNCTION TO CREATE A LINKED LIST WITH A NODE
{
    DoublyNode *temp = malloc(NODESIZE);
    temp->data = value;
    temp->prev_addr = NULL;
    temp->next_addr = NULL;
    return temp;
    /*
        This function creates a node and returns the address of node.
        data is initialized with given value, both pointers are iniatilized to null.
        It requires a pointer to catch the address of the node or else will be lost.
    */
}

DoublyNode *insertNodeAtFront(DoublyNode *front_node, int data)
{
    DoublyNode *temp = createNode(data);
    temp->next_addr = front_node;
    front_node->prev_addr = temp;
    return temp;
    /*
      It requires a pointer to catch the address of the node or else will be lost.
    */
}

DoublyNode *insertNodeAtEnd(DoublyNode *end_node, int data)
{
    DoublyNode *temp = createNode(data);
    end_node->next_addr = temp;
    temp->prev_addr = end_node;
    return temp;
}

void insertNodeAtPos(DoublyNode **head_addr, DoublyNode **tail_addr, int position, int data)
//  THIS TAKES ADDR IN HEAD AS FRONT NODE, USER INPUT POSITON AND DATA
{
    DoublyNode *temp = createNode(data);
    temp->data = data;
    DoublyNode *node_bef_position = *head_addr;
    if (position > countNodes(*head_addr) + 1 || position <= 0)
        printf("invalid position");
    else if (position == 1)
    {
        temp->next_addr = node_bef_position;
        node_bef_position->prev_addr = temp;
        *head_addr = temp;
    }
    else
    {
        for (size_t i = 1; i < position - 1; i++)
            node_bef_position = node_bef_position->next_addr;
        /*
            the loop runs from 1, starting of linked list node, to second last list.
            the pointer var stores addr of second last node.
            it stores through 3rd node's next node address.
        */

        temp->next_addr = node_bef_position->next_addr; // stores address of next node after the postion.
        temp->prev_addr = node_bef_position;
        if (node_bef_position->next_addr != NULL)
            node_bef_position->next_addr->prev_addr = temp; // stores address of temp node to the pointer of prev address of prev node in the position
        else
            *tail_addr = temp;
        node_bef_position->next_addr = temp; // next addr pointer of previous node of the positon stores adrres of new node
    }
}

DoublyNode *deleteNodeAtFront(DoublyNode *front_node)
{
    front_node = front_node->next_addr;
    free(front_node->prev_addr);
    front_node->prev_addr = NULL;
    return front_node;
}

DoublyNode *deleteNodeAtEnd(DoublyNode *end_node)
{
    end_node = end_node->prev_addr;
    free(end_node->next_addr);
    end_node->next_addr = NULL;
    return end_node;
}

void deleteNodeAtPos(DoublyNode **head_addr, DoublyNode **tail_addr, int position)
{
    // Check if the list is empty
    if (*head_addr == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Get the head node
    DoublyNode *node_bef_position = *head_addr;
    DoublyNode *temp;

    // Check for invalid position
    if (position <= 0 || position > countNodes(*head_addr))
        printf("Invalid position\n");
    // Case 1: Deleting the head node
    else if (position == 1)
    {
        temp = *head_addr;            // Node to delete is the head
        *head_addr = temp->next_addr; // Move head to the next node
        if (*head_addr != NULL)
            (*head_addr)->prev_addr = NULL; // Update new head's prev_addr to NULL
        else
            *tail_addr = NULL; // If the list becomes empty, update tail
    }
    // Case 2: Deleting a node other than the head
    else
    {
        // Traverse to the node just before the target position
        for (size_t i = 1; i < position - 1; i++)
            node_bef_position = node_bef_position->next_addr;

        // The node to be deleted is node_bef_position->next_addr
        temp = node_bef_position->next_addr;

        // Update the next pointer of node_bef_position to skip temp
        node_bef_position->next_addr = temp->next_addr;

        // Case 3: If we're not deleting the last node, update the prev pointer of the next node
        if (temp->next_addr != NULL)
            temp->next_addr->prev_addr = node_bef_position;
        else
            // If deleting the last node, update the tail
            *tail_addr = node_bef_position;
    }

    // Free the node to be deleted
    free(temp);
}

DoublyNode *reverseList(DoublyNode *front_node)
{
    DoublyNode *temp = front_node->next_addr, *ptr = front_node;

    while (temp != NULL)
    {
        ptr->next_addr = ptr->prev_addr;
        ptr->prev_addr = temp;
        ptr = temp;
        temp = ptr->next_addr;
    }
    ptr->next_addr = ptr->prev_addr;
    ptr->prev_addr = temp;
    return ptr;
}

int main()
{
    int data[] = {0, 10, 20, 30, 40, 50};
    int pos = 3; // position starts from 1 unlike array i.e 0

    HEAD = createNode(data[2]); // This automatically creates a linked list
    TAIL = HEAD;

    HEAD = insertNodeAtFront(HEAD, data[1]); //  adds node to front of linkedlist
    TAIL = insertNodeAtEnd(TAIL, data[4]);   //  adds node to end of linkedlist

    //  adds node to 3rd position of linked list
    insertNodeAtPos(&HEAD, &TAIL, pos, data[3]);
    insertNodeAtPos(&HEAD, &TAIL, pos=5, data[5]);
    insertNodeAtPos(&HEAD, &TAIL, pos=1, data[0]);
    displayDoubly(HEAD);
    printf("\n");

    HEAD = deleteNodeAtFront(HEAD);
    TAIL = deleteNodeAtEnd(TAIL);
    deleteNodeAtPos(&HEAD, &TAIL, pos = 2);
    displayDoubly(HEAD);

    printf("\n");

    HEAD = reverseList(HEAD);
    displayDoubly(HEAD);
}