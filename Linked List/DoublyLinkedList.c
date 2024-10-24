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
        printf("Nodes: %d, Head: %p\n",countNodes(node), node);

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

int main()
{
    int data[] = {10, 20, 30, 40};
    int pos = 3; // position starts from 1 unlike array i.e 0

    HEAD = createNode(data[1]); // This automatically creates a linked list
    TAIL = HEAD;

    HEAD = insertNodeAtFront(HEAD, data[0]); //  adds node to front of linkedlist
    TAIL = insertNodeAtEnd(TAIL, data[3]);   //  adds node to end of linkedlist

    //  adds node to 3rd position of linked list
    int num_of_nodes = countNodes(HEAD);
    if (pos > num_of_nodes + 1 || pos <= 0)
        printf("position doesn't exist!\n");
    else
        insertNodeAtPos(&HEAD, &TAIL, pos, data[2]);

    displayDoubly(HEAD);
    printf("\n");

    HEAD = deleteNodeAtFront(HEAD);
    TAIL = deleteNodeAtEnd(TAIL);
    displayDoubly(HEAD);
}