#include <stdio.h>
#include <stdlib.h>

/* Doubly Linked list is a type of linked list that has address of both 
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

DoublyNode *HEAD=NULL, *TAIL=NULL;    //  POINTERS THAT POINTS THE HEAD AND TAIL OF LINKED LIST.

const int NODESIZE = sizeof(DoublyNode);    //  MESURES THE SIZE OF A NODE TO MAKE DYNAMIC MEMORY ALLOCATION

void displayDoubly(DoublyNode *node)  //  DISPLAYS A DOUBLE LINKED LIST NODE FROM THE GIVEN NODE ADDRESS, usually address in head.
{
    if (node == NULL)
        printf("Linked List is empty");
    else
    {
        printf("Head: %p\n", node);
        
        while (node->next_addr != NULL)
        {
            printf("| %p | %d | %p | <--->", node->prev_addr, node->data, node->next_addr );
            node = node->next_addr;
        }
        printf("| %p | %d | %p |", node->prev_addr, node->data, node->next_addr );
        
    }
}

DoublyNode *createLinkedList(int value)     //  FUNCTION TO CREATE A LINKED LIST WITH A NODE    
{
    DoublyNode *temp = malloc(NODESIZE);
    temp->data = value;
    temp->prev_addr = NULL;
    temp->next_addr = NULL;
    return temp;
}


int main()
{
    int data = 10;
    HEAD = createLinkedList(data);

    displayDoubly(HEAD);
}